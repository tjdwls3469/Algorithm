#include <iostream>
#include <cstring>
using namespace std;

int width;
int height;
int map[50][50];
bool check[50][50];
int dx[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
void dfs(int x, int y) {
	check[x][y] = true;
	for (int i = 0; i < 8; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && ny >= 0 && nx < height && ny < width) {
			if (map[nx][ny] == 1 && check[nx][ny] == false) {
				dfs(nx, ny);
			}
		}
	}
}

int main() {
	int islandCnt = 0;
	while (true) {
		cin >> width >> height;
		if (width == 0 && height == 0) {
			break;
		}
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				cin >> map[i][j];
			}
		}
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				if (map[i][j] == 1 && check[i][j] == false) {
					islandCnt++;
					dfs(i, j);
				}
			}
		}
		cout << islandCnt << '\n';
		islandCnt = 0;
		memset(map, 0, sizeof(map));
		memset(check, false, sizeof(check));
	}

	return 0;
}