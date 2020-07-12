#include <iostream>
#include <cmath>
using namespace std;

int row;
int col;
int map[100][100];
long double dp[100][100];
//int dx[] = { 0, -1, 0, 1 };
//int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1 };
int dy[] = { 1, 0 };

void dfs(int x, int y, long double speed, long double time) {
	if (dp[x][y] != -1 && time >= dp[x][y]) {
		return;
	}
	dp[x][y] = time;
	if (x == row - 1 && y == col - 1) {
		return;
	}
	for (int i = 0; i < 2; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < row && ny >= 0 && ny < col) {
			double nextSpeed = speed * pow(2, map[x][y] - map[nx][ny]);
			dfs(nx, ny, nextSpeed, time + 1.0 / speed);
			// 이동할때 걸리는 시간은 현재 속도를 역수 취한 값이다
		}
	}
}

int main() {
	cout.setf(ios::fixed);
	cout.precision(2);

	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			dp[i][j] = -1.0;
		}
	}

	long double speed;
	cin >> speed >> row >> col;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cin >> map[i][j];
		}
	}

	dfs(0, 0, speed, 0);
	cout << dp[row - 1][col - 1];
	return 0;
}