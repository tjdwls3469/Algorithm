#pragma warning (disable:4996)
#include <iostream>
#include <queue>
using namespace std;

int w;
int h;
int island[50][50];
int result[50][50];
int dx[] = { -1,-1,0,1,1,1,0,-1 };
int dy[] = { 0,-1,-1,-1,0,1,1,1 };

void bfs(int x, int y, int cnt) {
	queue<pair<int,int>> q;
	q.push(make_pair(x, y));
	result[x][y] = cnt;
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int i = 0; i < 8; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < w && ny >= 0 && ny < h) {
				if (island[nx][ny] == 1 && result[nx][ny] == 0) {
					q.push(make_pair(nx, ny));
					result[nx][ny] = cnt;
				}
			}
		}
	}
}

int main() {
	while (true) {
		scanf("%d %d", &w, &h);
		if (w == 0 && h == 0) {
			break;
		}
		for (int i = 0; i < w; i++) {
			for (int j = 0; j < h; j++) {
				scanf("%1d", &island[i][j]);
				result[i][j] = 0;
			}
		}
		int cnt = 0;
		for (int i = 0; i < w; i++) {
			for (int j = 0; j < h; j++) {
				if (island[i][j] == 1 && result[i][j] == 0) {
					bfs(i, j, ++cnt);
				}
			}
		}
		cout << cnt << "\n";
	}

	return 0;
}