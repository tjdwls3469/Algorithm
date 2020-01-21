#include <iostream>
using namespace std;

long long ans[91][2];

int main() {
	int len;
	cin >> len;
	ans[1][0] = ans[2][1] = 0;
	ans[1][1] = ans[2][0] = 1;
	for (int i = 3; i <= len; i++) {
		ans[i][0] = ans[i - 1][0] + ans[i - 1][1];
		ans[i][1] = ans[i - 1][0];
	}
	cout << ans[len][0] + ans[len][1];
	return 0;
}