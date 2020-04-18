#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

bool check[301][301];
int ans[301][301];
int len;
int sx, sy, gx, gy;
int dx[] = { -1,-2,-2,-1,1,2,2,1 };
int dy[] = { -2,-1,1,2,2,1,-1,-2 };

void bfs(int x, int y) {
	queue<pair<int, int>> q;
	check[x][y] = true;
	q.push(make_pair(x, y));
	while (!q.empty()) {
		int fx = q.front().first;
		int fy = q.front().second;
		q.pop();
		if (fx == gx && fy == gy) {
			break;
		}
		for (int i = 0; i < 8; i++) {
			int nx = fx + dx[i];
			int ny = fy + dy[i];
			if (nx >= 0 && nx < len && ny >= 0 && ny < len) {
				if (check[nx][ny] == false) {
					check[nx][ny] = true;
					q.push(make_pair(nx, ny));
					ans[nx][ny] = ans[fx][fy] + 1;
				}
			}
		}
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int cnt;
	cin >> cnt;
	for (int i = 0; i < cnt; i++) {
		cin >> len;
		cin >> sx >> sy;
		cin >> gx >> gy;
		memset(check, false, sizeof(check));
		memset(ans, 0, sizeof(ans));
		bfs(sx, sy);
		cout << ans[gx][gy] << '\n';
	}
	return 0;
}