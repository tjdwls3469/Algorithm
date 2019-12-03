#include <iostream>
#include <vector>
#include <string>
using namespace std;

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };
int ans = 1;

void solve(vector<string> &board, vector<bool> &check, int x, int y, int cnt) {
	if (cnt > ans) {
		ans = cnt;
	}
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < board.size() && ny >= 0 && ny < board[0].size()) {
			if (check[board[nx][ny] - 'A'] == false) {
				check[board[nx][ny] - 'A'] = true;
				solve(board, check, nx, ny, cnt + 1);
				check[board[nx][ny] - 'A'] = false;
			}
		}
	}
	return;
}

int main() {
	int row;
	int col;
	cin >> row >> col;
	vector<string> board(row);
	for (int i = 0; i < row; i++) {
		cin >> board[i];
	}
	vector<bool> check(26);
	check[board[0][0] - 'A'] = true;
	solve(board, check, 0, 0, ans);
	cout << ans;
	return 0;
}