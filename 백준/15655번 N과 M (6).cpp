#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int m;

void solve(int index, int selectCnt, vector<int> &ans, vector<int> &num) {
	if (selectCnt == m) {
		for (int i = 0; i < m; i++) {
			cout << ans[i] << ' ';
		}
		cout << '\n';
		return;
	}
	if (index == n) {
		return;
	}
	ans[selectCnt] = num[index];
	solve(index + 1, selectCnt + 1, ans, num);
	ans[selectCnt] = 0;
	solve(index + 1, selectCnt, ans, num);
}

int main() {
	cin >> n >> m;
	vector<int> num(n);
	vector<int> ans(n);
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	sort(num.begin(), num.end());
	solve(0, 0, ans, num);
	return 0;
}