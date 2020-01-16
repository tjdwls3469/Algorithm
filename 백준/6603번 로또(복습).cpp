#include <iostream>
using namespace std;

int set[12];
int ans[6];

void solve(int index, int selectCnt, int cnt) {
	if (selectCnt == 6) {
		for (int i = 0; i < 6; i++) {
			cout << ans[i] << ' ';
		}
		cout << '\n';
		return;
	}
	if (index >= cnt) {
		return;
	}
	ans[selectCnt] = set[index];
	solve(index + 1, selectCnt + 1, cnt);
	ans[selectCnt] = 0;
	solve(index + 1, selectCnt, cnt);
}

int main() {
	while (true) {
		int cnt;
		cin >> cnt;
		if (cnt == 0) {
			break;
		}
		for (int i = 0; i < cnt; i++) {
			cin >> set[i];
		}
		solve(0, 0, cnt);
		cout << '\n';
	}
	return 0;
}