#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

bool check[10][10][10][10];
bool checkAns[2];
int dx[] = { 0, -1, 0, 1 };
int dy[] = { -1, 0, 1, 0 };
struct point {
	int rx, ry, bx, by;
};

int main() {
	int row;
	int col;
	int ans = 0;
	int rx, ry, bx, by;
	cin >> row >> col;
	vector<string> map(row);
	for (int i = 0; i < row; i++) {
		cin >> map[i];
	}
	for (int i = 1; i < row - 1; i++) {
		for (int j = 1; j < col - 1; j++) {
			if (map[i][j] == 'R') {
				rx = i;
				ry = j;
			}
			else if (map[i][j] == 'B') {
				bx = i;
				by = j;
			}
			else {
				;
			}
		}
	}
	queue<point> q;
	check[rx][ry][bx][by] = true;
	q.push({ rx,ry,bx,by });
	while (!q.empty()) {
		int frx = q.front().rx;
		int fry = q.front().ry;
		int fbx = q.front().bx;
		int fby = q.front().by;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nrx = frx;
			int nry = fry;
			int nbx = fbx;
			int nby = fby;
			while (true) {
				nrx += dx[i];
				nry += dy[i];
				if (nrx >= 1 && nrx < row - 1 && nry >= 1 && nry < col - 1) {
					if (check[nrx][nry][nbx][nby] == false) {
						if (map[nrx][nry] == 'O') {
							break;
						}
						if (map[nrx][nry] != '#') {
							check[nrx][nry][nbx][nby] == true;
							continue;
						}
					}
				}
				nbx -= dx[i];
				nby -= dy[i];
			}
			while (true) {
				nbx += dx[i];
				nby += dy[i];
				if (nbx >= 1 && nbx < row - 1 && nby >= 1 && nby < col - 1) {
					if (check[nrx][nry][nbx][nby] == false) {
						if (map[nbx][nby] == 'O') {
							break;
						}
						if (map[nbx][nby] != '#') {
							check[nrx][nry][nbx][nby] == true;
							continue;
						}
					}
				}
				nbx -= dx[i];
				nby -= dy[i];
			}
			if (nrx == nbx && nry == nby) {
				if (map[nrx][nry] == 'O') {
					cout << -1;
					return 0;
				}
				if (abs(frx - nrx) + abs(fry - nry) > abs(fbx - nbx) + abs(fby - nby)) {
					nrx -= dx[i];
					nry -= dy[i];
				}
				else {
					nbx -= dx[i];
					nby -= dy[i];
				}
			}
			if (check[nrx][nry][nbx][nby] == false) {
				check[nrx][nry][nbx][nby] = true;
				q.push({ nrx,nry,nbx,nby });
			}
		}
	}
}