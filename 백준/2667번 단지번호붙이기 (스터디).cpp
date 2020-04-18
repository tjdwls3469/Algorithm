#pragma warning(disable:4996)
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int cnt;
int map[25][25];
bool check[25][25];
int houseCnt;
vector<int> ans;
int dx[] = { 0,-1,0,1 };
int dy[] = { -1,0,1,0 };

int bfs(int x, int y) {
	int homeCnt = 1;
	queue<pair<int, int>> q;
	check[x][y] = true;
	q.push(make_pair(x, y));
	while (!q.empty()) {
		int fx = q.front().first;
		int fy = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = fx + dx[i];
			int ny = fy + dy[i];
			if (nx >= 0 && nx < cnt && ny >= 0 && ny < cnt) {
				if (map[nx][ny] == 1 && check[nx][ny] == false) {
					check[nx][ny] = true;
					q.push(make_pair(nx, ny));
					homeCnt++;
				}
			}
		}
	}
	return homeCnt;
}

int main() {
	/*cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);*/
	cin >> cnt;
	for (int i = 0; i < cnt; i++) {
		for (int j = 0; j < cnt; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	for (int i = 0; i < cnt; i++) {
		for (int j = 0; j < cnt; j++) {
			if (map[i][j] == 1 && check[i][j] == false) {
				houseCnt++;
				int home = bfs(i, j);
				ans.push_back(home);
			}
		}
	}
	sort(ans.begin(), ans.end());
	cout << houseCnt << '\n';
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << '\n';
	}
	return 0;
}