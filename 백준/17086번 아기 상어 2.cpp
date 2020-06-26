#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int row;
int col;
int map[50][50];
bool check[50][50];
int dx[] = { 0, -1, -1, -1, 0, 1, 1, 1 };
int dy[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int ans = -1;

void dfs(int x, int y, int dist) {
	check[x][y] = true;
	for (int i = 0; i < 8; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < row && ny >= 0 && ny < col) {
			if (check[nx][ny] == false) {
				q.push({ {nx,ny}, nd });
			}
		}
	}
}

void bfs(int x, int y) {
	queue<pair<pair<int, int>, int>> q;
	check[x][y] = true;
	q.push({ {x,y},0 });
	while (!q.empty()) {
		int fx = q.front().first.first;
		int fy = q.front().first.second;
		int fd = q.front().second;
		if (map[fx][fy] == 1) {
			if (ans == -1 || fd > ans) {
				ans = fd;
			}
			break;
		}
		q.pop();
		for (int i = 0; i < 8; i++) {
			int nx = fx + dx[i];
			int ny = fy + dy[i];
			int nd = fd + 1;
			if (nx >= 0 && nx < row && ny >= 0 && ny < col) {
				if (check[nx][ny] == false) {
					check[nx][ny] = true;
					q.push({ {nx,ny}, nd });
				}
			}
		}
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> row >> col;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (map[i][j] == 0) {
				memset(check, false, sizeof(check));
				bfs(i, j);
			}
		}
	}
	cout << ans;
	return 0;
}