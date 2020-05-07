#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int map[50][50];
int n;
int m;
vector<pair<int, int>> home;
vector<pair<int, int>> chicken;
vector<pair<int, int>> goal;
int ans;

void solve(int index, int select) {
	if (select == m) {
		int result = 0;
		for (int i = 0; i < home.size(); i++) {
			int temp = 0;
			for (int j = 0; j < goal.size(); j++) {
				int val = abs(home[i].first - goal[j].first) + abs(home[i].second - goal[j].second);
				if (temp == 0 || val < temp) {
					temp = val;
				}
			}
			result += temp;
		}
		if (ans == 0 || result < ans) {
			ans = result;
		}
		return;
	}
	if (index >= chicken.size()) {
		return;
	}
	goal.push_back(chicken[index]);
	solve(index + 1, select + 1);
	goal.pop_back();
	solve(index + 1, select);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	int temp;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> temp;
			map[i][j] = temp;
			if (temp == 1) {
				home.push_back(make_pair(i, j));
			}
			else if (temp == 2) {
				chicken.push_back(make_pair(i, j));
			}
		}
	}
	solve(0, 0);
	cout << ans;
	return 0;
}