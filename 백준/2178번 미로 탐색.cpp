#pragma warning(disable:4996)
#include <iostream>
#include <queue>
using namespace std;

int maze[100][100];
bool check[100][100];
int row;
int col;
int dx[] = { 0, -1, 0, 1 };
int dy[] = { -1, 0, 1, 0 };

void bfs(int x, int y) {
	queue<pair<int,int>> q;
	check[x][y] = true;
	q.push(make_pair(x, y));
	while (!q.empty()) {
		int fx = q.front().first;
		int fy = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = fx + dx[i];
			int ny = fy + dy[i];
			if (nx >= 0 && nx < row && ny >= 0 && ny < col) {
				if (maze[nx][ny] != 0 && check[nx][ny] == false) {
					check[nx][ny] = true;
					maze[nx][ny] = maze[fx][fy] + 1;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
}

int main() {
	cin >> row >> col;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			scanf("%1d", &maze[i][j]);
		}
	}
	bfs(0, 0);
	cout << maze[row - 1][col - 1];
	return 0;
}