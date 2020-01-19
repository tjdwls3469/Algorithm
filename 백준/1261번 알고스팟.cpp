#pragma warning (disable:4996)
#include <iostream>
#include <deque>
using namespace std;

int col;
int row;
int maze[100][100];
bool check[100][100];
int ans[100][100];
int dx[] = { 0, -1, 0, 1 };
int dy[] = { -1, 0, 1, 0 };

void bfs(int x, int y) {
	deque<pair<int, int>> q;
	check[x][y] = true;
	q.push_back(make_pair(x, y));
	while (!q.empty()) {
		int fx = q.front().first;
		int fy = q.front().second;
		q.pop_front();
		for (int i = 0; i < 4; i++) {
			int nx = fx + dx[i];
			int ny = fx + dy[i];
			if (nx >= 0 && nx < row && ny >= 0 && ny < col) {
				if (check[nx][ny] == false) {
					if (maze[nx][ny] == 0) {
						ans[nx][ny] = ans[fx][fy];
						q.push_front(make_pair(nx, ny));
					}
					else {
						check[nx][ny] = true;
						ans[nx][ny] = ans[fx][fy] + 1;
						q.push_back(make_pair(nx, ny));
					}
				}
			}
		}
	}
}

int main() {
	cin >> col >> row;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			scanf("%1d", &maze[i][j]);
		}
	}
	bfs(0, 0);
	cout << ans[row - 1][col - 1];
	return 0;
}