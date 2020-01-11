#include <iostream>
#include <queue>
using namespace std;

int col;
int row;
int farm[1000][1000];
bool check[1000][1000];
int dx[] = { 0, -1, 0, 1 };
int dy[] = { -1, 0, 1, 0 };

int main() {
	cin >> col >> row;
	queue<pair<int, int>> q;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cin >> farm[i][j];
			if (farm[i][j] == 1) {
				check[i][j] = true;
				q.push(make_pair(i, j));
			}
		}
	}
	while (!q.empty()) {
		int fx = q.front().first;
		int fy = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = fx + dx[i];
			int ny = fy + dy[i];
			if (nx >= 0 && nx < row && ny >= 0 && ny < col) {
				if (farm[nx][ny] == 0 && check[nx][ny] == false) {
					check[nx][ny] = true;
					q.push(make_pair(nx, ny));
					farm[nx][ny] = farm[fx][fy] + 1;
				}
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (farm[i][j] > ans) {
				ans = farm[i][j];
			}
		}
	}
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (farm[i][j] == 0) {
				ans = -1;
				cout << ans;
				return 0;
			}
		}
	}
	cout << ans - 1;
	return 0;
}