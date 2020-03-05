#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <tuple>
using namespace std;

int n;
int dx[] = { 0, -1, 0, 1 };
int dy[] = { -1, 0, 1, 0 };

void bfs(int x, int y, vector<string> &paint, vector<vector<bool>> &check) {
	queue<pair<int, int>> q;
	check[x][y] = true;
	q.push(make_pair(x, y));
	while (!q.empty()) {
		int fx;
		int fy;
		tie(fx, fy) = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = fx + dx[i];
			int ny = fy + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
				if (check[nx][ny] == false && paint[nx][ny] == paint[fx][fy]) {
					check[nx][ny] = true;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
}

void bfs2(int x, int y, vector<string> &paint, vector<vector<bool>> &check) {
	queue<pair<int, int>> q;
	check[x][y] = true;
	q.push(make_pair(x, y));
	while (!q.empty()) {
		int fx;
		int fy;
		tie(fx, fy) = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = fx + dx[i];
			int ny = fy + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
				if (check[nx][ny] == false) {
					if (paint[fx][fy] == 'R' || paint[fx][fy] == 'G') {
						if (paint[nx][ny] != 'B') {
							check[nx][ny] = true;
							q.push(make_pair(nx, ny));
						}
					}
					else {
						if (paint[nx][ny] == 'B') {
							check[nx][ny] = true;
							q.push(make_pair(nx, ny));
						}
					}
				}
			}
		}
	}
}

int main() {
	cin >> n;
	vector<string> paint(n);
	vector<vector<bool>> check(n, vector<bool>(n));
	for (int i = 0; i < n; i++) {
		cin >> paint[i];
	}
	int first = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (check[i][j] == false) {
				bfs(i, j, paint, check);
				first++;
			}
		}
	}
	cout << first << ' ';
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			check[i][j] = false;
		}
	}
	int second = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (check[i][j] == false) {
				bfs2(i, j, paint, check);
				second++;
			}
		}
	}
	cout << second;
	return 0;
}