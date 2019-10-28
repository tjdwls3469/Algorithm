#pragma warning(disable:4996)
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n;
int map[25][25];
int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };
int group[25][25];
int result[25 * 25];

void bfs(int x, int y, int cnt) {
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	group[x][y] = cnt;

	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
				if (map[nx][ny] == 1 && group[nx][ny] == 0) {
					q.push(make_pair(nx, ny));
					group[nx][ny] = cnt;
				}
			}
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 1 && group[i][j] == 0) {
				bfs(i, j, ++cnt);
			}
		}
	}
	cout << cnt << '\n';
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			result[group[i][j]]++;
		}
	}
	sort(result +1, result + cnt + 1);
	for (int i = 1; i <= cnt; i++) {
		cout << result[i] << '\n';
	}

	return 0;
}