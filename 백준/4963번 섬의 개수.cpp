#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int col;
int row;
int map[50][50];
bool check[50][50];
int dx[] = { 0, -1, -1, -1, 0, 1, 1, 1 };
int dy[] = { -1, -1, 0, 1, 1, 1, 0, -1 };

void bfs(int x, int y) {
	queue<pair<int, int>> q;
	check[x][y] = true;
	q.push(make_pair(x, y));
	while (!q.empty()) {
		int fx = q.front().first;
		int fy = q.front().second;
		q.pop();
		for (int i = 0; i < 8; i++) {
			int nx = fx + dx[i];
			int ny = fy + dy[i];
			if (nx >= 0 && nx < row && ny >= 0 && ny < col) {
				if (map[nx][ny] == 1 && check[nx][ny] == false) {
					check[nx][ny] = true;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
}

int main() {
	while (true) {
		int ans = 0;
		memset(check, false, sizeof(check));
		cin >> col >> row;
		if (col == 0 && row == 0) {
			break;
		}
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				cin >> map[i][j];
			}
		}
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (map[i][j] == 1 && check[i][j] == false) {
					ans++;
					bfs(i, j);
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}