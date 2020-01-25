#include <iostream>
#include <queue>
using namespace std;

char map[50][50];
int ans[50][50];
bool check[50][50];
int dx[] = { 0, -1, 0, 1 };
int dy[] = { -1, 0, 1, 0 };

int main() {
	int row;
	int col;
	queue<pair<int, int>> q;
	pair<int, int> start;
	pair<int, int> goal;
	cin >> row >> col;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (map[i][j] == 'D') {
				goal = make_pair(i, j);
			}
			else if (map[i][j] == '*') {
				q.push(make_pair(i, j));
			}
			else if (map[i][j] == 'S') {
				start = make_pair(i, j);
			}
			else {
				;
			}
		}
	}
	check[start.first][start.second] = true;
	q.push(start);
	while (!q.empty()) {
		int fx = q.front().first;
		int fy = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = fx + dx[i];
			int ny = fy + dy[i];
			if (nx < 0 || nx >= row || ny < 0 || ny >= col) {
				continue;
			}
			if (map[fx][fy] == '*' && map[nx][ny] == '.') {
				q.push(make_pair(nx, ny));
				map[nx][ny] = '*';
			}
			else if (map[fx][fy] == 'S') {
				if ( (map[nx][ny] == '.' || map[nx][ny] == 'D') && check[nx][ny] == false ) {
					check[nx][ny] = true;
					q.push(make_pair(nx, ny));
					map[nx][ny] = 'S';
					ans[nx][ny] = ans[fx][fy] + 1;
				}
			}
			else {
				;
			}
		}
	}
	if (ans[goal.first][goal.second] == 0) {
		cout << "KAKTUS";
	}
	else {
		cout << ans[goal.first][goal.second];
	}
	return 0;
}