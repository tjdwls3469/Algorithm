#include <iostream>
using namespace std;

int map[20][20];
int dx[] = { 0, 0, -1, 1};
int dy[] = { 1, -1, 0, 0};
int dice[7];

int main() {
	int row;
	int col;
	int x;
	int y;
	int commandCnt;
	cin >> row >> col >> x >> y >> commandCnt;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < commandCnt; i++) {
		int command;
		cin >> command;
		command--;
		int nx;
		int ny;
		nx = x + dx[command];
		ny = y + dy[command];
		if (nx < 0 || nx >= row || ny < 0 || ny >= col) {
			continue;
		}
		int temp = dice[1];
		switch (command) {
		case 0:
			dice[1] = dice[4];
			dice[4] = dice[6];
			dice[6] = dice[3];
			dice[3] = temp;
			break;
		case 1:
			dice[1] = dice[3];
			dice[3] = dice[6];
			dice[6] = dice[4];
			dice[4] = temp;
			break;
		case 2:
			dice[1] = dice[5];
			dice[5] = dice[6];
			dice[6] = dice[2];
			dice[2] = temp;
			break;
		case 3:
			dice[1] = dice[2];
			dice[2] = dice[6];
			dice[6] = dice[5];
			dice[5] = temp;
			break;
		default:
			;
			break;
		}
		x = nx;
		y = ny;
		if (map[x][y] == 0) {
			map[x][y] = dice[6];
		}
		else {
			dice[6] = map[x][y];
			map[x][y] = 0;
		}
		cout << dice[1] << '\n';
	}
	return 0;
}