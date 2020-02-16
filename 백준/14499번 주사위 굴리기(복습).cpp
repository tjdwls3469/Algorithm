#include <iostream>
using namespace std;

int map[20][20];
int dice[7];

int main() {
	int row;
	int col;
	int x;
	int y;
	int cnt;
	int command;
	cin >> row >> col >> x >> y >> cnt;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < cnt; i++) {
		cin >> command;
		int temp1 = 0;
		int temp2 = 2;
		bool ok = true;
		switch (command) {
		case 1:
			if (y + 1 >= col) {
				ok = false;
				break;
			}
			y++;
			temp1 = dice[1];
			dice[1] = dice[4];
			temp2 = dice[3];
			dice[3] = temp1;
			dice[4] = dice[6];
			dice[6] = temp2;
			break;
		case 2:
			if (y - 1 < 0) {
				ok = false;
				break;
			}
			y--;
			temp1 = dice[1];
			dice[1] = dice[3];
			dice[3] = dice[6];
			temp2 = dice[4];
			dice[4] = temp1;
			dice[6] = temp2;
			break;
		case 3:
			if (x - 1 < 0) {
				ok = false;
				break;
			}
			x--;
			temp1 = dice[1];
			dice[1] = dice[5];
			temp2 = dice[2];
			dice[2] = temp1;
			dice[5] = dice[6];
			dice[6] = temp2;
			break;
		case 4:
			if (x + 1 >= row) {
				ok = false;
				break;
			}
			x++;
			temp1 = dice[1];
			dice[1] = dice[2];
			dice[2] = dice[6];
			temp2 = dice[5];
			dice[5] = temp1;
			dice[6] = temp2;
			break;
		default:;
			break;
		}
		if (ok == false) {
			continue;
		}
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