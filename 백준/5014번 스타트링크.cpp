#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int maxFloor;
int start;
int goal;
int up;
int down;

void bfs(vector<bool> &check, vector<int> &ans) {
	queue<int> q;
	check[start] = true;
	q.push(start);
	while (!q.empty()) {
		int node = q.front();
		if (node == goal) {
			break;
		}
		q.pop();
		int nextUp = node + up;
		if (nextUp <= maxFloor) {
			if (check[nextUp] == false) {
				check[nextUp] = true;
				q.push(nextUp);
				ans[nextUp] = ans[node] + 1;
			}
		}
		int nextDown = node - down;
		if (nextDown >= 1) {
			if (check[nextDown] == false) {
				check[nextDown] = true;
				q.push(nextDown);
				ans[nextDown] = ans[node] + 1;
			}
		}
	}
}

int main() {
	cin >> maxFloor >> start >> goal >> up >> down;
	if (start > goal && down == 0) {
		cout << "use the stairs";
		return 0;
	}
	else if (start < goal && up == 0) {
		cout << "use the stairs";
		return 0;
	}
	else {
		;
	}
	vector<bool> check(maxFloor + 1);
	vector<int> ans(maxFloor + 1);
	bfs(check, ans);
	if (check[goal] == true) {
		cout << ans[goal];
	}
	else {
		cout << "use the stairs";
	}
	return 0;
}