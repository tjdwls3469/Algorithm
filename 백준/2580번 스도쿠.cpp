#include <iostream>
using namespace std;

int sudoku[10][10];
bool rowCheck[10][10];
bool colCheck[10][10];
bool squareCheck[10][10];

int square(int x, int y) {
	return (x / 3) * 3 + y / 3;
}

bool solve(int num) {
	if (num == 81) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << sudoku[i][j] << ' ';
			}
			cout << '\n';
		}
		return true;
	}
	int x = num / 9;
	int y = num % 9;
	if (sudoku[x][y] != 0) {
		return solve(num + 1);
	}
	else {
		for (int i = 1; i <= 9; i++) {
			if (rowCheck[x][i] == false && colCheck[y][i] == false && squareCheck[square(x, y)][i] == false) {
				rowCheck[x][i] = colCheck[y][i] = squareCheck[square(x, y)][i] = true;
				sudoku[x][y] = i;
				if (solve(num + 1)) {
					return true;
				}
				sudoku[x][y] = 0;
				rowCheck[x][i] = colCheck[y][i] = squareCheck[square(x, y)][i] = false;
			}
		}
	}
	return false;
}

int main() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> sudoku[i][j];
			if (sudoku[i][j] != 0) {
				rowCheck[i][sudoku[i][j]] = true;
				colCheck[j][sudoku[i][j]] = true;
				squareCheck[square(i, j)][sudoku[i][j]] = true;
			}
		}
	}
	solve(0);

	return 0;
}