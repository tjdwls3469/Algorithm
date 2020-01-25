#include <iostream>
using namespace std;

void solve(int index, int selectCnt, int cnt, int *num, int *lotto) {
	if (selectCnt == 6) {
		for (int i = 0; i < 6; i++) {
			cout << lotto[i] << ' ';
		}
		cout << '\n';
		return;
	}
	if (index == cnt) {
		return;
	}
	lotto[selectCnt] = num[index];
	solve(index + 1, selectCnt + 1, cnt, num, lotto);
	lotto[selectCnt] = 0;
	solve(index + 1, selectCnt, cnt, num, lotto);
}

int main() {
	int cnt;
	int num[12];
	int lotto[6];
	while (true) {
		cin >> cnt;
		if (cnt == 0) {
			break;
		}
		for (int i = 0; i < cnt; i++) {
			cin >> num[i];
		}
		solve(0, 0, cnt, num, lotto);
		cout << '\n';
	}
	return 0;
}