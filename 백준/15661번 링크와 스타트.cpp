#include <iostream>
#include <vector>
using namespace std;

int cnt;
int ability[20][20];

int solve(int index, vector<int> &link, vector<int> &start) {
	if (index == cnt) {
		if (link.size() == 0 || start.size() == 0) {
			return -1;
		}
		int linkAbility = 0;
		int startAbility = 0;
		for (int i = 0; i < link.size(); i++) {
			for (int j = 0; j < link.size(); j++) {
				linkAbility += ability[link[i]][link[j]];
			}
		}
		for (int i = 0; i < start.size(); i++) {
			for (int j = 0; j < start.size(); j++) {
				startAbility += ability[start[i]][start[j]];
			}
		}
		int diff = linkAbility - startAbility;
		if (diff < 0) {
			diff = -diff;
		}
		return diff;
	}
	int ans = -1;
	link.push_back(index);
	int linkTeam = solve(index + 1, link, start);
	if (ans == -1 || linkTeam != -1 && linkTeam < ans) {
		ans = linkTeam;
	}
	link.pop_back();
	start.push_back(index);
	int startTeam = solve(index + 1, link, start);
	if (ans == -1 || startTeam != -1 && startTeam < ans) {
		ans = startTeam;
	}
	start.pop_back();
	return ans;
}

int main() {
	cin >> cnt;
	vector<int> link, start;
	for (int i = 0; i < cnt; i++) {
		for (int j = 0; j < cnt; j++) {
			cin >> ability[i][j];
		}
	}
	cout << solve(0, link, start);
	return 0;
}