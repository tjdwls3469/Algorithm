#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxCnt;
int cnt;

void solve(int selectCnt, int start, vector<int> &num, vector<int> &ans) {
	if (selectCnt == cnt) {
		for (int i = 0; i < cnt; i++) {
			cout << ans[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = start; i < maxCnt; i++) {
		ans[selectCnt] = num[i];
		solve(selectCnt + 1, i, num, ans);
	}
}

int main() {
	cin >> maxCnt >> cnt;
	vector<int> num(maxCnt);
	vector<int> ans(cnt);
	for (int i = 0; i < maxCnt; i++) {
		cin >> num[i];
	}
	sort(num.begin(), num.end());
	solve(0, 0, num, ans);
	return 0;
}