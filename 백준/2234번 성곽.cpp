#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int col;
int row;
int dx[] = { 0, -1, 0, 1 };
int dy[] = { -1, 0, 1, 0 };

int bfs(int x, int y, vector<vector<int>> &map, vector<vector<bool>> &check) {
	queue<pair<int, int>> q;
	check[x][y] = true;
	q.push(make_pair(x, y));
	int cnt = 0;
	while (!q.empty()) {
		int fx = q.front().first;
		int fy = q.front().second;
		q.pop();
		cnt++;
		for (int i = 0; i < 4; i++) {
			if (map[fx][fy] & (1 << i)) {
				continue;
			}
			int nx = fx + dx[i];
			int ny = fy + dy[i];
			if (nx >= 0 && nx < row && ny >= 0 && ny < col) {
				if (check[nx][ny] == false) {
					check[nx][ny] = true;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
	return cnt;
}

int main() {
	cin >> col >> row;
	vector<vector<int>> map(row, vector<int>(col));
	vector<vector<bool>> check(row, vector<bool>(col));
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cin >> map[i][j];
		}
	}
	int ansCnt = 0;
	int ansArea = 0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (check[i][j] == false) {
				ansCnt++;
				int temp = bfs(i, j, map, check);
				if (temp > ansArea) {
					ansArea = temp;
				}
			}
		}
	}
	cout << ansCnt << '\n' << ansArea;
	return 0;
}