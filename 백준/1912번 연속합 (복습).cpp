#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int cnt;
	cin >> cnt;
	vector<int> seq(cnt);
	vector<int> ans(cnt);
	for (int i = 0; i < cnt; i++) {
		cin >> seq[i];
	}
	ans[0] = seq[0];
	for (int i = 1; i < cnt; i++) {
		ans[i] = max(seq[i], ans[i - 1] + seq[i]);
	}
	sort(ans.begin(), ans.end());
	cout << ans[ans.size() - 1];
	return 0;
}