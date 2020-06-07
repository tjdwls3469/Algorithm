/*
대각선은 위에서 오는거랑 옆에서 오는거를 수행하면 되기때문에
대각선은 신경안써도 된다
ans[i][j] = max(ans[i - 1][j], ans[i][j - 1]) + map[i][j]
*/
#include <iostream>
#include <algorithm>
using namespace std;

int map[1000][1000];
int ans[1000][1000];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int row;
	int col;
	cin >> row >> col;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cin >> map[i][j];
		}
	}
	ans[0][0] = map[0][0];
	for (int i = 1; i < col; i++) {
		ans[0][i] = ans[0][i - 1] + map[0][i];
	}
	for (int i = 1; i < row; i++) {
		ans[i][0] = ans[i - 1][0] + map[i][0];
	}
	for (int i = 1; i < row; i++) {
		for (int j = 1; j < col; j++) {
			ans[i][j] = max(ans[i - 1][j], ans[i][j - 1]) + map[i][j];
		}
	}
	cout << ans[row - 1][col - 1];
	return 0;
}