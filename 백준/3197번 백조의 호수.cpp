#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;


int ans;
int row;
int col;
int dx[] = { 0, -1, 0, 1 };
int dy[] = { -1, 0, 1, 0 };
pair<int, int> start = make_pair(-1, -1);
pair<int, int> goal = make_pair(-1, -1);

bool bfs(int x, int y, vector<vector<bool>> &check, vector<string> &map) {
	queue<pair<int, int>> q;
	check[x][y] = true;
	q.push(make_pair(x, y));
	while (!q.empty()) {
		int fx = q.front().first;
		int fy = q.front().second;
		q.pop();
		if (fx == goal.first && fy == goal.second) {
			return true;
		}
		for (int i = 0; i < 4; i++) {
			int nx = fx + dx[i];
			int ny = fy + dy[i];
			if (nx >= 0 && nx < row && ny >= 0 && ny < col) {
				if (check[nx][ny] == false && map[nx][ny] != 'X') {
					check[nx][ny] = true;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
	return false;
}

int main() {
	cin >> row >> col;
	vector<string> map(row);
	vector<vector<bool>> check(row, vector<bool>(col));
	for (int i = 0; i < row; i++) {
		cin >> map[i];
	}
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (map[i][j] == 'L') {
				if (start.first == -1) {
					start.first = i;
					start.second = j;
				}
				else {
					goal.first = i;
					goal.second = j;
				}
			}
		}
	}
	while (true) {
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				check[i][j] = false;
			}
		}
		if (bfs(start.first, start.second, check, map) == true) {
			cout << ans;
			break;
		}
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				check[i][j] = false;
			}
		}
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (map[i][j] != 'X' && check[i][j] == false) {
					for (int k = 0; k < 4; k++) {
						int nx = i + dx[k];
						int ny = j + dy[k];
						if (nx >= 0 && nx < row && ny >= 0 && ny < col) {
							if (map[nx][ny] == 'X') {
								check[nx][ny] = true;
								map[nx][ny] = '.';
							}
						}
					}
				}
			}
		}
		ans++;
	}
}