#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int cnt;
	int ans = -1;
	cin >> cnt;
	vector<vector<int>> ability(cnt, vector<int>(cnt));
	int half = cnt / 2;
	for (int i = 0; i < cnt; i++) {
		for (int j = 0; j < cnt; j++) {
			cin >> ability[i][j];
		}
	}
	for (int i = 0; i < (1 << cnt); i++) {
		vector<int> start;
		vector<int> link;
		int startVal = 0;
		int linkVal = 0;
		for (int j = 0; j < cnt; j++) {
			if (i&(1 << j)) {
				start.push_back(j);
			}
			else {
				link.push_back(j);
			}
		}
		if (start.size() != half) {
			continue;
		}
		for (int j = 0; j < half; j++) {
			for (int k = 0; k < half; k++) {
				if (j == k) {
					continue;
				}
				startVal += ability[start[j]][start[k]];
				linkVal += ability[link[j]][link[k]];
			}
		}
		int diff = startVal - linkVal;
		if (diff < 0) {
			diff = -diff;
		}
		if (ans == -1 || diff < ans) {
			ans = diff;
		}
	}
	cout << ans;
	return 0;
}