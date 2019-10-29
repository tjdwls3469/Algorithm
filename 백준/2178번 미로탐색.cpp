#pragma warning(disable:4996)
#include <iostream>
#include <queue>
using namespace std;

int n;
int m;
int map[100][100];
int result[100][100];
bool check[100][100];
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };
int vertex = 0;

void bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	//result[x][y] = 1;
	result[x][y] = vertex + 1;
	check[x][y] = true;
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
				if (map[nx][ny] == 1 && check[nx][ny] == 0) {
					q.push(make_pair(nx, ny));
					vertex = result[x][y] + 1;
					result[nx][ny] = vertex;
					check[nx][ny] = true;
				}
			}
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 1 && check[i][j] == 0) {
				bfs(i, j);
			}
		}
	}
	cout << result[n - 1][m - 1];

	return 0;
}