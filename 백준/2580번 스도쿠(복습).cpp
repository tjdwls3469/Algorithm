#include <iostream>
using namespace std;

const int SIZE = 9;
int sudoku[SIZE][SIZE];

int main() {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			cin >> sudoku[i][j];
		}
	}
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (sudoku[i][j] != 0) {
				continue;
			}
			bool checkRow[SIZE + 1];
			bool checkCol[SIZE + 1];
			bool checkRect[SIZE + 1];
			for (int k = 0; k <= SIZE; k++) {
				checkRow[k] = checkCol[k] = checkRect[k] = false;
			}
			for (int k = 0; k < SIZE; k++) {
				if (sudoku[i][k] != 0) {
					checkRow[sudoku[i][k]] = true;
				}
				if (sudoku[k][j] != 0) {
					checkCol[sudoku[k][j]] = true;
				}
			}
			int x = i / 3;
			int y = j / 3;
			x *= 3;
			y *= 3;
			for (int m = x; m <= x + 2; m++) {
				for (int n = y; n <= y + 2; n++) {
					if (sudoku[m][n] != 0) {
						checkRect[sudoku[m][n]] = true;
					}
				}
			}
			for (int k = 1; k <= SIZE; k++) {
				if(checkRow[k] == false && checkCol[k] == false && checkRect[k] == false){
					sudoku[i][j] = k;
				}
			}
		}
	}
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			cout << sudoku[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}