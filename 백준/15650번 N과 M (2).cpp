#include <iostream>
using namespace std;

int cnt;
int ans[8];

void solve(int index, int selectCnt, int max) {
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
	solve(index + 1, selectCnt + 1, max);
	ans[selectCnt] = 0;
	solve(index + 1, selectCnt, max);
}

int main() {
	int max;
	cin >> max >> cnt;
	solve(1, 0, max);
	return 0;
}