#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int map[8][8];
int temp[8][8];
vector<pair<int, int>> virus;
int row;
int col;
int dx[] = { 0, -1, 0, 1 };
int dy[] = { -1, 0, 1, 0 };
int oneCnt;
int twoCnt;
int ans;
int result;

int bfs(int x, int y) {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int virusCnt = 1;
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	while (!q.empty()) {
		int fx = q.front().first;
		int fy = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = fx + dx[i];
			int ny = fy + dy[i];
			if (nx >= 0 && nx < row && ny >= 0 && ny < col) {
				if (temp[nx][ny] == 0) {
					q.push(make_pair(nx, ny));
					temp[nx][ny] = 2;
					virusCnt++;
				}
			}
		}
	}
	return virusCnt;
}

int main() {
	cin >> row >> col;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				virus.push_back(make_pair(i, j));
			}
			else if (map[i][j] == 1) {
				oneCnt++;
			}
		}
	}
	oneCnt += 3;

	for (int x1 = 0; x1 < row; x1++) {
		for (int y1 = 0; y1 < col; y1++) {
			if (map[x1][y1] != 0) {
				continue;
			}
			for (int x2 = 0; x2 < row; x2++) {
				for (int y2 = 0; y2 < col; y2++) {
					if (map[x2][y2] != 0) {
						continue;
					}
					for (int x3 = 0; x3 < row; x3++) {
						for (int y3 = 0; y3 < col; y3++) {
							if (map[x3][y3] != 0) {
								continue;
							}
							if ((x1 == x2 && y1 == y2) || (x2 == x3 && y2 == y3) || (x3 == x1 && y3 == y1)) {
								continue;
							}
							memcpy(temp, map, sizeof(map));
							temp[x1][y1] = 1;
							temp[x2][y2] = 1;
							temp[x3][y3] = 1;

							/*cout << '\n';
							for (int a = 0; a < row; a++) {
								for (int b = 0; b < col; b++) {
									cout << temp[a][b] << ' ';
								}
								cout << '\n';
							}
							cout << '\n';*/

							result = 0;
							bool check = false;
							for (int o = 0; o < virus.size(); o++) {
								result += bfs(virus[o].first, virus[o].second);
								if (result > twoCnt && twoCnt != 0) {
									check = true;
									break;
								}
							}
							if (check == true) {
								continue;
							}
							if (twoCnt == 0 || result < twoCnt) {
								twoCnt = result;
								int zeroCnt = (row*col) - (oneCnt + twoCnt);
								if (ans == 0 || zeroCnt > ans) {
									ans = zeroCnt;
								}
							}
						}
					}
				}
			}
		}
	}
	cout << ans;
	return 0;
}