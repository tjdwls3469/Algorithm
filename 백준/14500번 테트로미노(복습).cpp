#include <iostream>
#include <vector>
using namespace std;

int row;
int col;
int ans;

void one(int x, int y, vector<vector<int>> &map) {
	if (y + 3 >= col) {
		return;
	}
	int val;
	for (int i = 0; i < 4; i++) {
		val += map[x][y + i];
	}
	if (val > ans) {
		ans = val;
	}
}

void two(int x, int y, vector<vector<int>> &map) {
	if (x + 3 >= row) {
		return;
	}
	int val;
	for (int i = 0; i < 4; i++) {
		val += map[x + i][y];
	}
	if (val > ans) {
		ans = val;
	}
}

void three(int x, int y, vector<vector<int>> &map) {
	if (x + 1 >= row || y + 1 >= col) {
		return;
	}
	int val;
	for (int i = 0; i < 3; i++) {
		val += map[x + i][y];
	}
	if (val > ans) {
		ans = val;
	}
}

void four(int x, int y, vector<vector<int>> &map) {
	if (x + 2 >= row || y + 1 >= col) {
		return;
	}
	int val;
	val += (map[x][y] + map[x + 1][y] + map[x + 2][y] + map[x][y + 1]);
	if (val > ans) {
		ans = val;
	}
}

int main() {
	cin >> row >> col;
	vector<vector<int>> map(row, vector<int>(col));
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {

		}
	}
}