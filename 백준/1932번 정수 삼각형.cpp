#include <iostream>
#include <algorithm>
using namespace std;

int map[501][501];
int ans[501][501];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = n - 1; i >= 0; i--) {
		for (int j = 0; j <= i; j++) {
			ans[i][j] = max(ans[i + 1][j], ans[i + 1][j + 1]) + map[i][j];
		}
	}
	cout << ans[0][0];
	return 0;
}