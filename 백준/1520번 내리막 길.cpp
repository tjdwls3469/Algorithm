/*
DSF돌리는데 check배열 잘써서 풀자 -> 이것만 적용했더니 시간초과 뜸
DF추가하자
d[i][j] = i행j열에 갈수있는 경로수
*/
#include <iostream>
using namespace std;

int col;
int row;
int ans;
int map[500][500];
int d[500][500];
int dx[] = { 0, -1, 0, 1 };
int dy[] = { -1, 0, 1, 0 };

int dfs(int x, int y) {
	if (x == 0 && y == 0) {
		return 1;
	}
	if (d[x][y] == -1) {
		d[x][y] = 0;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < row && ny >= 0 && ny < col) {
				if (map[nx][ny] > map[x][y]) {
					d[x][y] += dfs(nx, ny);
				}
			}
		}
	}
	return d[x][y];
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> row >> col;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cin >> map[i][j];
			d[i][j] = -1;
		}
	}
	cout << dfs(row - 1, col - 1);
	return 0;
}