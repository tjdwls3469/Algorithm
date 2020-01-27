#include <iostream>
#include <algorithm>
using namespace std;

int n;
int m;
int ans[7];
int num[7];

void solve(int cnt) {
	if (cnt == m) {
		for (int i = 0; i < m; i++) {
			cout << ans[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = 0; i < n; i++) {
		ans[cnt] = num[i];
		solve(cnt + 1);
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	sort(num, num + n);
	solve(0);
	return 0;
}