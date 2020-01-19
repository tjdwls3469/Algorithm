#include <iostream>
using namespace std;

int ans[1001][10];
int mod = 10007;

int main() {
	int len;
	cin >> len;
	for (int i = 0; i < 10; i++) {
		ans[1][i] = 1;
	}
	for (int i = 2; i <= len; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k <= j; k++) {
				ans[i][j] += ans[i - 1][k];
			}
			ans[i][j] %= mod;
		}
	}
	int result = 0;
	for (int i = 0; i < 10; i++) {
		result += ans[len][i];
	}
	cout << result % mod;
	return 0;
}