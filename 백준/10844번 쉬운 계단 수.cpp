#include <iostream>
using namespace std;

int ans[101][10];
long long mod = 1000000000;

int main() {
	int length;
	cin >> length;
	for (int i = 1; i <= 9; i++) {
		ans[1][i] = 1;
	}
	for (int i = 2; i <= length; i++) {
		for (int j = 0; j <= 9; j++) {
			if (j - 1 >= 0) {
				ans[i][j] += ans[i - 1][j - 1];
			}
			if (j + 1 <= 9) {
				ans[i][j] += ans[i - 1][j + 1];
			}
			ans[i][j] %= mod;
		}
	}
	long long sum = 0;
	for (int i = 0; i <= 9; i++) {
		sum += ans[length][i];
	}
	sum %= mod;
	cout << sum;
	return 0;
}