#include <iostream>
#include <cstring>
#include <queue>
#include <tuple>
using namespace std;

int dx[] = { 0,0,1,-1,-2,-1,1,2,2,1,-1,-2 };
int dy[] = { 1,-1,0,0,1,2,2,1,-1,-2,-2,-1 };
int cost[] = { 0,0,0,0,1,1,1,1,1,1,1,1 };
int map[200][200];
int ans[200][200][31];

int main() {
	int skill;
	cin >> skill;
	int col;
	int row;
	cin >> col >> row;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cin >> map[i][j];
		}
	}
	memset(ans, -1, sizeof(ans));
	queue<tuple<int, int, int>> q;
	q.push(make_tuple(0, 0, 0));
	ans[0][0][0] = 0;
	while (!q.empty()) {
		int x, y, c;
		tie(x, y, c) = q.front();
		q.pop();
		for (int i = 0; i < 12; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nc = c + cost[i];
			if (nx < 0 || nx >= row || ny < 0 || ny >= col) {
				continue;
			}
			if (map[nx][ny] == 1 || nc > skill || ans[nx][ny][nc] != -1) {
				continue;
			}
			ans[nx][ny][nc] = ans[x][y][c] + 1;
			q.push(make_tuple(nx, ny, nc));
		}
	}
	int result = -1;
	for (int i = 0; i <= skill; i++) {
		if (ans[row - 1][col - 1][i] == -1) {
			continue;
		}
		if (result == -1 || ans[row - 1][col - 1][i] < result) {
			result = ans[row - 1][col - 1][i];
		}
	}
	cout << result;
	return 0;
}