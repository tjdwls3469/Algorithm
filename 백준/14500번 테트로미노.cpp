#include <iostream>
using namespace std;

int paper[500][500];
bool check[500][500];
int ans;
int row;
int col;
int dx[] = { 0,-1,0,1 };
int dy[] = { -1,0,1,0 };

void solve(int x, int y, int sum, int cnt) {
	if (cnt == 4) {
		if (sum > ans) {
			ans = sum;
			return;
		}
	}
	if (x < 0 || x >= row || y < 0 || y >= col) {
		return;
	}
	if (check[x][y]) {
		return;
	}
	check[x][y] = true;
	for (int i = 0; i < 4; i++) {
		solve(x + dx[i], y + dy[i], sum + paper[x][y], cnt + 1);
	}
	check[x][y] = false;
}

int main() {
	cin >> row >> col;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cin >> paper[i][j];
		}
	}
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			solve(i, j, 0, 0);
			if (j + 2 < col) {
				int temp = paper[i][j] + paper[i][j + 1] + paper[i][j + 2];
				if (i - 1 >= 0) {
					int sum = temp + paper[i - 1][j + 1];
					if (sum > ans) {
						ans = sum;
					}
				}
				if (i + 1 < row) {
					int sum = temp + paper[i + 1][j + 1];
					if (sum > ans) {
						ans = sum;
					}
				}
			}
			if (i + 2 < row) {
				int temp = paper[i][j] + paper[i + 1][j] + paper[i + 2][j];
				if (j - 1 >= 0) {
					int sum = temp + paper[i + 1][j - 1];
					if (sum > ans) {
						ans = sum;
					}
				}
				if (j + 1 < row) {
					int sum = temp + paper[i + 1][j + 1];
					if (sum > ans) {
						ans = sum;
					}
				}
			}
		}
	}
	cout << ans;
	return 0;
}