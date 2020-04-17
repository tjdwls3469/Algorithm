#pragma warning(disable:4996)
#include <iostream>
#include <queue>
using namespace std;

int map[2][100000];
bool check[2][100000];

int main() {
	int col;
	int jump;
	cin >> col >> jump;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < col; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	queue<pair<int,int>> q;
	check[0][0] = true;
	q.push(make_pair(0, 0));
	while (!q.empty()) {
		int fx = q.front().first;
		int fy = q.front().second;
		q.pop();
		int gx = fx;
		int gy = fy + 1;
		if (map[gx][gy] == 1 && check[gx][gy] == false) {
			check[gx][gy] = true;
			q.push(make_pair(gx, gy));
		}
		int bx = fx;
		int by = fy - 1;
		if (map[bx][by] == 1 && check[bx][by] == false) {
			check[bx][by] = true;
			q.push(make_pair(bx, by));
		}
		int jx;
		int jy = fy + jump;
		if (fx == 0) {
			jx = 1;
		}
		else {
			jx = 0;
		}
		if (map[jx][jy] == 1 && check[jx][jy] == false) {
			check[jx][jy] = true;
			q.push(make_pair(jx, jy));
		}
	}
}