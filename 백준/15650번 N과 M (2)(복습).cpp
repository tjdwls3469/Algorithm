#include <iostream>
using namespace std;

int ans[9];

void solve(int index, int selectCnt, int max, int cnt) {
	if (selectCnt == cnt) {
		for (int i = 0; i < cnt; i++) {
			cout << ans[i] << ' ';
		}
		cout << '\n';
		return;
	}
	if (index > max) {
		return;
	}
	ans[selectCnt] = index;
	solve(index + 1, selectCnt + 1, max, cnt);
	ans[selectCnt] = 0;
	solve(index + 1, selectCnt, max, cnt);
}

int main() {
	int max;
	int cnt;
	cin >> max >> cnt;
	solve(1, 0, max, cnt);
	return 0;
}