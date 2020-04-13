#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int cnt;
	int ans = -1;
	cin >> cnt;
	vector<int> team(cnt);
	vector<vector<int>> ability(cnt, vector<int>(cnt));
	int half = cnt / 2;
	for (int i = half; i < cnt; i++) {
		team[i] = 1;
	}
	for (int i = 0; i < cnt; i++) {
		for (int j = 0; j < cnt; j++) {
			cin >> ability[i][j];
		}
	}
	do {
		vector<int> start;
		vector<int> link;
		int startVal = 0;
		int linkVal = 0;
		for (int i = 0; i < cnt; i++) {
			if (team[i] == 0) {
				start.push_back(i);
			}
			else {
				link.push_back(i);
			}
		}
		for (int i = 0; i < half; i++) {
			for (int j = 0; j < half; j++) {
				if (i == j) {
					continue;
				}
				startVal += ability[start[i]][start[j]];
				linkVal += ability[link[i]][link[j]];
			}
		}
		int diff = startVal - linkVal;
		if (diff < 0) {
			diff = -diff;
		}
		if (ans == -1 || diff < ans) {
			ans = diff;
		}
	} while (next_permutation(team.begin(), team.end()));
	cout << ans;
	return 0;
}