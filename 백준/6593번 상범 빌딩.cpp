/*
문제 : 'S' 에서 'E'거리 구하기
아이디어 : 기존의 네방향에 추가로 위아래도 움직이자
*/

#include <iostream>
#include <string>
#include <cstring>
#include <queue>
using namespace std;

int layer;
int row;
int col;
int sz, sx, sy;
int ez, ex, ey;
bool check[30][30][30];
int dz[] = { -1,1 };
int dx[] = { 0,-1,0,1 };
int dy[] = { -1,0,1,0 };

void make_map(string(*map)[30]) {
	bool start = false;
	bool end = false;
	for (int i = 0; i < layer; i++) {
		for (int j = 0; j < row; j++) {
			cin >> map[i][j];
			if (start == false) {
				for (int k = 0; k < col; k++) {
					if (map[i][j][k] == 'S') {
						start = true;
						sz = i;
						sx = j;
						sy = k;
					}
				}
			}
			if (end == false) {
				for (int k = 0; k < col; k++) {
					if (map[i][j][k] == 'E') {
						end = true;
						ez = i;
						ex = j;
						ey = k;
					}
				}
			}
		}
	}
}

// 맵, 행, 열, 면, 거리
int bfs(string (*map)[30], int x, int y, int z, int d) {
	queue < pair<pair<int, int>, pair<int, int>> > q;
	check[z][x][y] = true;
	q.push(make_pair(make_pair(x, y), make_pair(z,d)));
	while (!q.empty()) {
		int fx = q.front().first.first;
		int fy = q.front().first.second;
		int fz = q.front().second.first;
		int dist = q.front().second.second;
		q.pop();
		if (map[fz][fx][fy] == 'E') {
			return dist;
		}
		for (int i = 0; i < 2; i++) {
			int nz = fz + dz[i];
			if (nz >= 0 && nz < layer) {
				if (map[nz][fx][fy] != '#' && check[nz][fx][fy] == false) {
					check[nz][fx][fy] = true;
					q.push(make_pair(make_pair(fx, fy), make_pair(nz, dist + 1)));
				}
			}
		}
		for (int i = 0; i < 4; i++) {
			int nx = fx + dx[i];
			int ny = fy + dy[i];
			if (nx >= 0 && nx < row && ny >= 0 && ny < col) {
				if (map[fz][nx][ny] != '#' && check[fz][nx][ny] == false) {
					check[fz][nx][ny] = true;
					q.push(make_pair(make_pair(nx, ny), make_pair(fz, dist + 1)));
				}
			}
		}
	}
	return -1;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	while (true) {
		cin >> layer >> row >> col;
		if (layer == 0 && row == 0 && col == 0) {
			break;
		}
		string map[30][30];
		memset(check, false, sizeof(check));
		make_map(map); // map 입력 받고 'S', 'E' 좌표 구함 
		int ans = bfs(map, sx, sy, sz, 0);
		if (ans == -1) {
			cout << "Trapped!" << '\n';
		}
		else {
			cout << "Escaped in " << ans << " minute(s)." << '\n';
		}
	}
	return 0;
}