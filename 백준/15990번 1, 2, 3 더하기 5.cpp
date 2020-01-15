#include <iostream>
using namespace std;

long long ans[100001][4];
const long long mod = 1000000009LL;

int main() {
	int cnt;
	ans[1][1] = 1;
	ans[2][2] = 1;
	ans[3][3] = 1;
	for (int i = 1; i <= 100000; i++) {
		if (i > 1) {
			ans[i][1] = ans[i - 1][2] + ans[i - 1][3];
		}
		if (i > 2) {
			ans[i][2] = ans[i - 2][1] + ans[i - 2][3];
		}
		if (i > 3) {
			ans[i][3] = ans[i - 3][1] + ans[i - 3][2];
		}
		ans[i][1] %= mod;
		ans[i][2] %= mod;
		ans[i][3] %= mod;
	}
	cin >> cnt;
	for (int i = 0; i < cnt; i++) {
		int num;
		cin >> num;
		cout << (ans[num][1] + ans[num][2] + ans[num][3]) % mod << '\n';
	}
	return 0;
}