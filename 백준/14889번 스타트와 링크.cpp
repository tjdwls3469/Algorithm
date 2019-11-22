#include <iostream>
#include <vector>
using namespace std;

int cnt;
int ability[20][20];

int solve(int index, vector<int> &start, vector<int> &link) {
	if (index == cnt) {
		if (start.size() != cnt / 2 || link.size() != cnt / 2) {
			return -1;
		}
		int startAbility = 0;
		int linkAbility = 0;
		for (int i = 0; i < cnt / 2; i++) {
			for (int j = 0; j < cnt / 2; j++) {
				if (i == 0 && j == 0) {
					continue;
				}
				startAbility += ability[start[i]][start[j]];
				linkAbility += ability[link[i]][link[j]];
			}
		}
		int result = startAbility - linkAbility;
		if (result < 0) {
			result = -result;
		}
		return result;
	}

	int result = -1;
	start.push_back(index);
	int ans1 = solve(index + 1, start, link);
	if (result == -1 || (ans1 != -1 && ans1 < result)) {
		result = ans1;
	}
	start.pop_back();

	link.push_back(index);
	int ans2 = solve(index + 1, start, link);
	if (result == -1 || (ans2 != -1 && ans2 < result)) {
		result = ans2;
	}
	link.pop_back();

	return result;
}

int main() {
	cin >> cnt;
	for (int i = 0; i < cnt; i++) {
		for (int j = 0; j < cnt; j++) {
			cin >> ability[i][j];
		}
	}
	vector<int> start;
	vector<int> link;
	cout << solve(0, start, link);

	return 0;
}