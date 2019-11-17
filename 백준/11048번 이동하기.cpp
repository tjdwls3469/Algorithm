#include <iostream>
using namespace std;

int map[1001][1001];
int result[1001][1001];
int cal(int num1, int num2, int num3) {
	int max = -1;
	if (num1 > num2) {
		max = num1;
	}
	else {
		max = num2;
	}
	if (num3 > max) {
		max = num3;
	}
	return max;
}

int main() {
	int row;
	int col;
	cin >> row >> col;
	for (int i = 1; i <= row; i++) {
		for (int j = 1; j <= col; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 1; i <= row; i++) {
		for (int j = 1; j <= col; j++) {
			result[i][j] = cal(result[i - 1][j], result[i][j - 1], result[i - 1][j - 1]) + map[i][j];
		}
	}
	cout << result[row][col];

	return 0;
}