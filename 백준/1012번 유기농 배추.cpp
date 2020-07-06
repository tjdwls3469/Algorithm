/*
	섬의 개수문제랑 같은 문제
*/

#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int col;
int row;
int map[50][50];
bool check[50][50];
int dx[] = { 0, -1, 0, 1 };
int dy[] = { -1, 0, 1, 0 };

void bfs(int x, int y) {
	queue<pair<int, int>> q;
	check[x][y] = true;
	q.push({ x,y });
	while (!q.empty()) {
		int fx = q.front().first;
		int fy = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = fx + dx[i];
			int ny = fy + dy[i];
			if (nx >= 0 && nx < row && ny >= 0 && ny < col) {
				if (map[nx][ny] == 1 && check[nx][ny] == false) {
					check[nx][ny] = true;
					q.push({ nx,ny });
				}
			}
		}
	}
}

int main() {
	int tc;
	cin >> tc;
	int cnt;
	int c;
	int r;
	for (int i = 0; i < tc; i++) {
		int ans = 0;
		memset(map, 0, sizeof(map));
		memset(check, false, sizeof(check));
		cin >> col >> row >> cnt;
		for (int j = 0; j < cnt; j++) {
			cin >> c >> r;
			map[r][c] = 1;
		}
		for (int j = 0; j < row; j++) {
			for (int k = 0; k < col; k++) {
				if (map[j][k] == 1 && check[j][k] == false) {
					ans++;
					bfs(j, k);
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}