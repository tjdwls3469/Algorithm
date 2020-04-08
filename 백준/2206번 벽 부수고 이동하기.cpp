#pragma warning(disable:4996)
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int ans[1000][1000][2];
int dx[] = { 0, -1, 0, 1 };
int dy[] = { -1, 0, 1, 0 };

int main() {
	int row;
	int col;
	cin >> row >> col;
	vector<vector<int>> map(row, vector<int>(col));
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	queue<tuple<int, int, int>> q;
	q.push(make_tuple(0, 0, 0));
	ans[0][0][0] = 1;
	while (!q.empty()) {
		int fx, fy, fz;
		tie(fx, fy, fz) = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = fx + dx[i];
			int ny = fy + dy[i];
			if (nx >= 0 && nx < row && ny >= 0 && ny < col) {
				if (map[nx][ny] == 0) {
					if (ans[nx][ny][fz] == 0) {
						q.push(make_tuple(nx, ny, fz));
						ans[nx][ny][fz] = ans[fx][fy][fz] + 1;
					}
				}
				else {
					if (fz == 0 && ans[nx][ny][fz + 1] == 0) {
						q.push(make_tuple(nx, ny, fz+1));
						ans[nx][ny][fz + 1] = ans[fx][fy][fz] + 1;
					}
				}
			}
		}
	}
	if (ans[row - 1][col - 1][0] == 0 && ans[row - 1][col - 1][1] == 0) {
		cout << -1;
	}
	else {
		if (ans[row - 1][col - 1][0] < ans[row - 1][col - 1][1]) {
			if (ans[row - 1][col - 1][0] == 0) {
				cout << ans[row - 1][col - 1][1];
			}
			else {
				cout << ans[row - 1][col - 1][0];
			}
		}
		else {
			if (ans[row - 1][col - 1][1] == 0) {
				cout << ans[row - 1][col - 1][0];
			}
			else {
				cout << ans[row - 1][col - 1][1];
			}
		}
	}
	return 0;
}