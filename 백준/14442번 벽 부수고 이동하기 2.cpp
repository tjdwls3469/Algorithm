#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <tuple>
#include <climits>
using namespace std;

int row;
int col;
int breakCnt;
int dx[] = { 0,-1,0,1 };
int dy[] = { -1,0,1,0 };
queue<tuple<int, int, int>> q;
int ans[1000][1000][10];

void bfs(int x, int y, int z, vector<string> &map, vector<vector<bool>> &check) {
	check[x][y] = true;
	q.push(make_tuple(x, y, z));
	ans[x][y][z] = 1;
	while (!q.empty()) {
		int fx, fy, fz;
		tie(fx, fy, fz) = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = fx + dx[i];
			int ny = fy + dy[i];
			if (nx >= 0 && nx < row && ny >= 0 && ny < col) {
				if (map[nx][ny] == '0' && check[nx][ny] == false) {
					check[nx][ny] = true;
					q.push(make_tuple(nx, ny, fz));
					ans[nx][ny][fz] = ans[fx][fy][fz] + 1;
				}
				if (fz + 1 <= breakCnt && map[nx][ny] == '1' && check[nx][ny] == false) {
					check[nx][ny] = true;
					q.push(make_tuple(nx, ny, fz + 1));
					ans[nx][ny][fz + 1] = ans[fx][fy][fz] + 1;
				}
			}
		}
	}
}

int main() {
	cin >> row >> col >> breakCnt;
	vector<string> map(row);
	vector<vector<bool>> check(row, vector<bool>(col));
	for (int i = 0; i < row; i++) {
		cin >> map[i];
	}
	bfs(0, 0, 0, map, check);
	if (check[row - 1][col - 1] == false) {
		cout << -1;
	}
	else {
		int result = INT_MAX;
		for (int i = 0; i <= breakCnt; i++) {
			if (ans[row - 1][col - 1][i] < result && ans[row - 1][col - 1][i] != 0) {
				result = ans[row - 1][col - 1][i];
			}
		}
		cout << result;
	}
	return 0;
}