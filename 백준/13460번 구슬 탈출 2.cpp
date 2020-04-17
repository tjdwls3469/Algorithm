#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

bool check[10][10][10][10];
int dx[] = { 0, -1, 0, 1 };
int dy[] = { -1, 0, 1, 0 };
struct point {
	int rx, ry, bx, by;
};

int main() {
	int row;
	int col;
	int ans = -1;
	int cnt = 0;
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
		if (cnt == 11) {
			ans = -1;
			break;
		}
		int frx = q.front().rx;
		int fry = q.front().ry;
		int fbx = q.front().bx;
		int fby = q.front().by;
		q.pop();

		if (map[frx][fry] == 'O' && map[fbx][fby] != 'O') {
			ans = cnt;
			break;
		}

		for (int i = 0; i < 4; i++) {
			int nrx = frx;
			int nry = fry;
			int nbx = fbx;
			int nby = fby;

			while (true) {
				if (map[nrx][nry] == 'O' || map[nrx][nry] == '#') {
					break;
				}
				nrx += dx[i];
				nry += dy[i];
			}
			while (true) {
				if (map[nbx][nby] == 'O' || map[nbx][nby] == '#') {
					break;
				}
				nbx += dx[i];
				nby += dy[i];
			}
			if (nrx == nbx && nry == nby) {
				if (map[nbx][nby] == 'O') {
					continue;
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
				cnt++;
			}
		}

	}
	cout << ans;
	return 0;
}