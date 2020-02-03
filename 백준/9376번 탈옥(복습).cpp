#include <iostream>
#include <vector>
#include <string>
#include <deque>
using namespace std;

int row;
int col;
int dx[] = { 0, -1, 0, 1 };
int dy[] = { -1, 0, 1, 0 };

vector<vector<int>> bfs(vector<string> map, int x, int y) {
	vector<vector<int>> result(row, vector<int>(col));
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			result[i][j] = -1;
		}
	}
	deque<pair<int, int>> q;
	q.push_back(make_pair(x,y));
	result[x][y] = 0;
	while (!q.empty()) {
		int fx = q.front().first;
		int fy = q.front().second;
		q.pop_front();
		for (int i = 0; i < 4; i++) {
			int nx = fx + dx[i];
			int ny = fy + dy[i];
			if (nx < 0 || nx >= row || ny < 0 || ny >= col) {
				continue;
			}
			if (result[nx][ny] != -1) {
				continue;
			}
			if (map[nx][ny] == '*') {
				continue;
			}
			else if (map[nx][ny] == '#') {
				result[nx][ny] = result[fx][fy] + 1;
				q.push_back(make_pair(nx, ny));
			}
			else if (map[nx][ny] == '.' || map[nx][ny] == '$') {
				result[nx][ny] = result[fx][fy];
				q.push_front(make_pair(nx, ny));
			}
			else {
				;
			}
		}
	}
	return result;
}

int main() {
	int cnt;
	cin >> cnt;
	for (int i = 0; i < cnt; i++) {
		cin >> row >> col;
		vector<string> map(row + 2);
		for (int j = 1; j <= row; j++) {
			cin >> map[j];
			map[j] = "." + map[j] + ".";
		}
		row += 2;
		col += 2;
		for (int j = 0; j < col; j++) {
			map[0] += ".";
			map[row - 1] += ".";
		}
		vector<vector<int>> sanggeun = bfs(map, 0, 0);
		int x1, y1;
		int x2, y2;
		x1 = x2 = y1 = y2 = -1;
		for (int j = 0; j < row; j++) {
			for (int k = 0; k < col; k++) {
				if (map[j][k] == '$') {
					if (x1 == -1 && y1 == -1) {
						x1 = j;
						y1 = k;
					}
					else {
						x2 = j;
						y2 = k;
					}
					
				}
			}
		}
		vector<vector<int>> prisoner1 = bfs(map, x1, y1);
		vector<vector<int>> prisoner2 = bfs(map, x2, y2);
		int ans = row * col;
		int cur;
		for (int j = 0; j < row; j++) {
			for (int k = 0; k < col; k++) {
				if (map[j][k] == '*') {
					continue;
				}
				cur = sanggeun[j][k] + prisoner1[j][k] + prisoner2[j][k];
				if (map[j][k] == '#') {
					cur -= 2;
				}
				if (cur < ans) {
					ans = cur;
				}
			}
		}
		cout << ans << '\n';
	}
}