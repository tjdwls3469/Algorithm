#include <iostream>
#include <vector>
#include <string>
using namespace std;

int row;
int col;
string map[20];
bool check[26];
int dx[] = { 0,-1,0,1 };
int dy[] = { -1,0,1,0 };
int ans = 1;

int solve(int x, int y, int val) {
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < row && ny >= 0 && ny < col) {
			if (check[map[nx][ny] - 'A'] == false) {
				check[map[nx][ny] - 'A'] = true;
				int temp = solve(nx, ny, val + 1);
				if (temp > ans) {
					ans = temp;
				}
				check[map[nx][ny] - 'A'] = false;
			}
		}
	}
	return val;
}

int main() {
	cin >> row >> col;
	for (int i = 0; i < row; i++) {
		cin >> map[i];
	}
	check[map[0][0] - 'A'] = true;
	solve(0, 0, 1);
	cout << ans;
	return 0;
}