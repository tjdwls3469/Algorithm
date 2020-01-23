#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int m;
bool check[8];

void solve(vector<int> &num, vector<int> &ans, int selectCnt) {
	if (selectCnt == m) {
		for (int i = 0; i < m; i++) {
			cout << ans[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = 0; i < n; i++) {
		if (check[i] == true) {
			continue;
		}
		check[i] = true;
		ans[selectCnt] = num[i];
		solve(num, ans, selectCnt + 1);
		check[i] = false;
	}
}

int main() {
	cin >> n >> m;
	vector<int> num(n);
	vector<int> ans(m);
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	sort(num.begin(), num.end());
	solve(num, ans, 0);
	return 0;
}