#include <iostream>
using namespace std;

long long ans[1000001];

int main() {
	int cnt;
	int num;
	cin >> cnt;
	ans[1] = 1;
	ans[2] = 2;
	ans[3] = 4;
	for (int i = 4; i <= 1000000; i++) {
		ans[i] = ans[i - 1] + ans[i - 2] + ans[i - 3];
		ans[i] = ans[i] % 1000000009;
	}
	for (int i = 0; i < cnt; i++) {
		cin >> num;
		cout << ans[num] << '\n';
	}
	return 0;
}