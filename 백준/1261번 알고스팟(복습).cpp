#pragma warning(disable:4996)
#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int dx[] = { 0,-1,0,1 };
int dy[] = { -1,0,1,0 };

int main() {
	int col;
	int row;
	cin >> col >> row;
	vector<vector<int>> map(row, vector<int>(col));
	vector<vector<int>> ans(row, vector<int>(col));
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			scanf("%1d", &map[i][j]);
			ans[i][j] = -1;
		}
	}
	deque<pair<int, int>> q;
	q.push_front(make_pair(0, 0));
	ans[0][0] = 0;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop_front();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < row && ny >= 0 && ny < col) {
				if (ans[nx][ny] == -1) {
					if (map[nx][ny] == 0) {
						q.push_front(make_pair(nx, ny));
						ans[nx][ny] = ans[x][y];
					}
					else {
						q.push_back(make_pair(nx, ny));
						ans[nx][ny] = ans[x][y] + 1;
					}
				}
			}
		}
	}
	cout << ans[row - 1][col - 1];
	return 0;
}