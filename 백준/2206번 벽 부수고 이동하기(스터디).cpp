#pragma warning(disable:4996)
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int row;
int col;
int map[1000][1000];
int dist[1000][1000][2];
int dx[] = { 0, -1, 0, 1 };
int dy[] = { -1, 0, 1, 0 };

void bfs(int x, int y, int z) {
	queue<pair<pair<int, int>, int>> q;
	dist[x][y][0] = 1;
	q.push(make_pair(make_pair(x, y), 0));
	while (!q.empty()) {
		int fx = q.front().first.first;
		int fy = q.front().first.second;
		int fz = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = fx + dx[i];
			int ny = fy + dy[i];
			if (nx >= 0 && nx < row && ny >= 0 && ny < col) {
				if (map[nx][ny] == 0 && dist[nx][ny][fz] == 0) {
					dist[nx][ny][fz] = dist[fx][fy][fz] + 1;
					q.push(make_pair(make_pair(nx, ny), fz));
				}
				if (map[nx][ny] == 1 && fz == 0) {
					dist[nx][ny][1] = dist[fx][fy][fz] + 1;
					q.push(make_pair(make_pair(nx, ny), 1));
				}
			}
		}
	}
}

int main() {
	cin >> row >> col;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	bfs(0, 0, 0);
	if (dist[row - 1][col - 1][0] == 0 && dist[row - 1][col - 1][1] == 0) {
		cout << -1;
	}
	else if (dist[row - 1][col - 1][0] != 0 && dist[row - 1][col - 1][1] != 0){
		cout << min(dist[row - 1][col - 1][0], dist[row - 1][col - 1][1]);
	}
	else if (dist[row - 1][col - 1][0] == 0) {
		cout << dist[row - 1][col - 1][1];
	}
	else {
		cout << dist[row - 1][col - 1][0];
	}
	return 0;
}