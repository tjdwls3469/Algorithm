#include <iostream>
#include <algorithm>
using namespace std;

int cnt;
int a[2001];
int b[2001];
int ans[2001][2001];
int result;

void solve(int l, int r) {
	if (l == 0 || r == 0) {
		return;
	}
	ans[l - 1][r] = max(ans[l - 1][r], ans[l][r]);
	solve(l - 1, r);
	ans[l - 1][r - 1] = max(ans[l - 1][r - 1], ans[l][r]);
	solve(l - 1, r - 1);
	if (b[r] < a[l]) {
		ans[l][r - 1] = max(ans[l][r - 1], ans[l][r] + b[r]);
		solve(l, r - 1);
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> cnt;
	for (int i = 1; i <= cnt; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= cnt; i++) {
		cin >> b[i];
	}
	solve(cnt, cnt);
	for (int i = 0; i <= cnt; i++) {
		if (result == 0 || ans[i][0] > result) {
			result = ans[i][0];
		}
	}
	for (int i = 0; i <= cnt; i++) {
		if (result == 0 || ans[0][i] > result) {
			result = ans[0][i];
		}
	}
	cout << result;
	return 0;
}