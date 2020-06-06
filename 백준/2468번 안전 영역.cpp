/*
주어진 맵의 최소높이부터 최대높이까지 반복문 돌면서
DFS를 통해 안전영역을 구해준다
*/
#include <iostream>
#include <cstring>
using namespace std;

int map[100][100];
bool check[100][100];
int rc;
int minVal = 101;
int maxVal = 0;
int ans = 1;
int dx[] = { 0, -1, 0, 1 };
int dy[] = { -1, 0, 1, 0 };

void dfs(int x, int y, int height) {
	check[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < rc && ny >= 0 && ny < rc) {
			if (check[nx][ny] == false && map[nx][ny] > height) {
				check[nx][ny] = true;
				dfs(nx, ny, height);
			}
		}
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> rc;
	for (int i = 0; i < rc; i++) {
		for (int j = 0; j < rc; j++) {
			cin >> map[i][j];
			if (map[i][j] < minVal) {
				minVal = map[i][j];
			}
			if (map[i][j] > maxVal) {
				maxVal = map[i][j];
			}
		}
	}
	for (int i = minVal; i < maxVal; i++) {
		int temp = 0;
		memset(check, false, sizeof(check));
		for (int j = 0; j < rc; j++) {
			for (int k = 0; k < rc; k++) {
				if (map[j][k] > i && check[j][k] == false) {
					temp++;
					dfs(j, k, i);
				}
			}
		}
		if (temp > ans) {
			ans = temp;
		}
	}
	cout << ans;
	return 0;
}