#include <iostream>
using namespace std;

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };
int map[50][50];

int main() {
	int row;
	int col;
	int x;
	int y;
	int dir;
	cin >> row >> col;
	cin >> x >> y >> dir;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cin >> map[i][j];
		}
	}
	while (true) {
		if (map[x][y] == 0) {
			map[x][y] = 2;
		}
		if (map[x][y - 1] != 0 && map[x - 1][y] != 0 && map[x][y + 1] != 0 && map[x + 1][y] != 0) {
			if (map[x - dx[dir]][y - dy[dir]] == 1) {
				break;
			}
			else {
				x = x - dx[dir];
				y = y - dy[dir];
			}
		}
		else {
			dir = (dir + 3) % 4;
			if (map[x + dx[dir]][y + dy[dir]] == 0) {
				x = x + dx[dir];
				y = y + dy[dir];
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (map[i][j] == 2) {
				ans++;
			}
		}
	}
	cout << ans;
	return 0;
}