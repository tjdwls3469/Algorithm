#include <iostream>
#include <algorithm>
using namespace std;

int maze[1000][1000];
int ans[1000][1000];

int main() {
	int row;
	int col;
	cin >> row >> col;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cin >> maze[i][j];
		}
	}
	ans[0][0] = maze[0][0];
	for (int i = 1; i < row; i++) {
		ans[i][0] = maze[i][0] + ans[i - 1][0];
	}
	for (int i = 1; i < col; i++) {
		ans[0][i] = maze[0][i] + ans[0][i - 1];
	}
	for (int i = 1; i < row; i++) {
		for (int j = 1; j < col; j++) {
			ans[i][j] = maze[i][j] + max(max(ans[i - 1][j], ans[i][j - 1]), ans[i - 1][j - 1]);
		}
	}
	cout << ans[row - 1][col - 1];
	return 0;
}