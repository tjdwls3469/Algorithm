#include <iostream>
using namespace std;

int ans[1001];

int main() {
	int n;
	cin >> n;
	ans[1] = 1;
	ans[2] = 3;
	for (int i = 3; i <= n; i++) {
		ans[i] = ans[i - 1] + 2 * ans[i - 2];
		ans[i] = ans[i] % 10007;
	}
	cout << ans[n];
	return 0;
}