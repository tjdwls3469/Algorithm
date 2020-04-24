#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int tc;
	cin >> tc;
	for (int i = 0; i < tc; i++) {
		int ans = 1;
		int cnt;
		cin >> cnt;
		vector<pair<int, int>> rank(cnt);
		for (int j = 0; j < cnt; j++) {
			int x, y;
			cin >> x >> y;
			rank[j] = make_pair(x, y);
		}
		sort(rank.begin(), rank.end());
		int val = rank[0].second;
		for (int j = 1; j < cnt; j++) {
			if (rank[j].second < val) {
				ans++;
				val = rank[j].second;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}