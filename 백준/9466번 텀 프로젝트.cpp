#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void dfs(int start, vector<int> &student, vector<bool> &check, vector<int> &node, vector<bool> &solo) {
	if (solo[start] == true) {
		node.push_back(0);
		return;
	}
	check[start] = true;
	node.push_back(start);
	int next = student[start];
	if (check[next] == false) {
		dfs(next, student, check, node, solo);
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int tc;
	cin >> tc;
	for (int i = 0; i < tc; i++) {
		int cnt;
		cin >> cnt;
		vector<int> student(cnt + 1);
		vector<int> ans;
		vector<bool> solo(cnt + 1);
		for (int j = 1; j <= cnt; j++) {
			cin >> student[j];
		}
		for (int j = 1; j <= cnt; j++) {
			vector<bool> check(cnt + 1);
			vector<int> node;
			dfs(j, student, check, node, solo);
			if (node.front() != student[node.back()]) {
				ans.push_back(j);
				solo[j] = true;
			}
		}
		cout << ans.size() << '\n';
	}
	return 0;
}