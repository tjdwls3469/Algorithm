#pragma warning(disable:4996)
#include <iostream>
using namespace std;

const int ROW = 5;
const int COL = 8;

int gearWheel[ROW][COL];
bool same[5];
void rotation(int row) {
	int temp = gearWheel[row][COL - 1];
	for (int i = COL-2; i >= 0; i--) {
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
void solveRight(int num, bool check, int dir) {
	if (num >= 5 || check == true) {
		return;
	}
	if (dir == 1) {
		rotation(num);
		solveRight(num + 1, same[num], -1);
	}
	else {
		reverseRotation(num);
		solveRight(num + 1, same[num], 1);
	}
}

int main() {
	int cnt;
	int num;
	int dir;
	for (int i = 1; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			scanf("%1d", &gearWheel[i][j]);
		}
	}
	cin >> cnt;
	for (int i = 0; i < cnt; i++) {
		cin >> num >> dir;
		same[0] = same[4] = true;
		for (int j = 1; j <= 3; j++) {
			if (gearWheel[j][2] == gearWheel[j+1][6]) {
				same[j] = true;
			}
			else {
				same[j] = false;
			}
		}
		if (dir == 1) {
			rotation(num);
			solveLeft(num - 1, same[num - 1], -1);
			solveRight(num + 1, same[num], -1);
		}
		else {
			reverseRotation(num);
			solveLeft(num - 1, same[num - 1], 1);
			solveRight(num + 1, same[num], 1);
		}
	}
	int ans = 0;
	for (int i = 1; i < ROW; i++) {
		int temp = 1;
		if (gearWheel[i][0] == 1) {
			for (int j = 1; j < i; j++) {
				temp *= 2;
			}
			ans += temp;
		}
	}
	cout << ans;
	return 0;
}