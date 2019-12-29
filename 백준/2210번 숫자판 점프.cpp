#include <iostream>
#include <set>
using namespace std;

int board[5][5];
set<int> answer;
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

void solve(int x, int y, int num, int len) {
	if (len == 6) {
		answer.insert(num);
		return;
	}
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (0 <= nx && nx < 5 && 0 <= ny && ny < 5) {
			solve(nx, ny, num * 10 + board[nx][ny], len + 1);
		}
	}
}

int main() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> board[i][j];
		}
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			solve(i, j, board[i][j], 1);
		}
	}
	cout << answer.size() << '\n';
	return 0;
}