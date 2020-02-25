#pragma warning(disable:4996)
#include <iostream>
using namespace std;

const int COL = 8;

int gearWheel[1001][COL];
bool same[1001];
void rotation(int row) {
	int temp = gearWheel[row][COL - 1];
	for (int i = COL - 2; i >= 0; i--) {
		gearWheel[row][i + 1] = gearWheel[row][i];
	}
	gearWheel[row][0] = temp;
	return;
}
void reverseRotation(int row) {
	int temp = gearWheel[row][0];
	for (int i = 1; i <= COL - 1; i++) {
		gearWheel[row][i - 1] = gearWheel[row][i];
	}
	gearWheel[row][COL - 1] = temp;
	return;
}
void solveLeft(int num, bool check, int dir) {
	if (num <= 0 || check == true) {
		return;
	}
	if (dir == 1) {
		rotation(num);
		solveLeft(num - 1, same[num - 1], -1);
	}
	else {
		reverseRotation(num);
		solveLeft(num - 1, same[num - 1], 1);
	}
}
void solveRight(int num, bool check, int dir, int row) {
	if (num > row || check == true) {
		return;
	}
	if (dir == 1) {
		rotation(num);
		solveRight(num + 1, same[num], -1, row);
	}
	else {
		reverseRotation(num);
		solveRight(num + 1, same[num], 1, row);
	}
}

int main() {
	int row;
	int cnt;
	int num;
	int dir;
	cin >> row;
	for (int i = 1; i <= row; i++) {
		for (int j = 0; j < COL; j++) {
			scanf("%1d", &gearWheel[i][j]);
		}
	}
	cin >> cnt;
	for (int i = 0; i < cnt; i++) {
		cin >> num >> dir;
		same[0] = same[row] = true;
		for (int j = 1; j < row; j++) {
			if (gearWheel[j][2] == gearWheel[j + 1][6]) {
				same[j] = true;
			}
			else {
				same[j] = false;
			}
		}
		if (dir == 1) {
			rotation(num);
			solveLeft(num - 1, same[num - 1], -1);
			solveRight(num + 1, same[num], -1, row);
		}
		else {
			reverseRotation(num);
			solveLeft(num - 1, same[num - 1], 1);
			solveRight(num + 1, same[num], 1, row);
		}
	}
	int ans = 0;
	for (int i = 1; i <= row; i++) {
		if (gearWheel[i][0] == 1) {
			ans++;
		}
	}
	cout << ans;
	return 0;
}