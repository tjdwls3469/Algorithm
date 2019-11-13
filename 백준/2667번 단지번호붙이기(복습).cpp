#pragma warning (disable:4996)
#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

int temp;
int complexCnt;
int homeCnt;
vector<int> home;
int map[25][25];
bool check[25][25];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
void dfs(int x, int y) {
	check[x][y] = true;
	homeCnt++;
	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (nx >= 0 && nx < temp && ny >= 0 && ny < temp) {
			if (map[nx][ny] == 1 && check[nx][ny] == false) {
				dfs(nx, ny);
			}
		}
	}
}

int main() {
	int size;
	cin >> size;
	temp = size;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (map[i][j] == 1 && check[i][j] == false) {
				homeCnt = 0;
				complexCnt++;
				dfs(i, j);
				home.push_back(homeCnt);
			}
		}
	}
	cout << complexCnt << '\n';
	for (int i = 0; i < home.size(); i++) {
		cout << home[i] << '\n';
	}
	return 0;
}