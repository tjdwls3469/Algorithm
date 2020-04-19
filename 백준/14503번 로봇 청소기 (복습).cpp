#include <iostream>
#include <queue>
using namespace std;

int map[50][50];
int ans;
int row;
int col;

bool noSpace(int x, int y) {
	int dx[] = { 0, -1, 0, 1 };
	int dy[] = { -1, 0, 1, 0 };
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < row && ny >= 0 && ny < col) {
			if (map[nx][ny] == 0) {
				return false;
			}
		}
	}
	return true;
}

int main() {
	cin >> row >> col;
	int x;
	int y;
	int dir;
	cin >> x >> y >> dir;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cin >> map[i][j];
		}
	}
	queue<pair<int, int>> q;
	map[x][y] = 2;
	q.push(make_pair(x, y));
	ans++;
	while (!q.empty()) {
		int fx = q.front().first;
		int fy = q.front().second;
		q.pop();
		if (noSpace(fx, fy) == true) {
			switch (dir) {
			case 0:
				fx++;
				break;
			case 1:
				fy--;
				break;
			case 2:
				fx--;
				break;
			case 3:
				fy++;
				break;
			default:
				break;
			}
			if (map[fx][fy] == 1) {
				cout << ans;
				return 0;
			}
			else {
				q.push(make_pair(fx, fy));
				continue;
			}
		}
		for (int i = 0; i < 4; i++) {
			int nx = fx;
			int ny = fy;
			switch (dir) {
			case 0:
				ny--;
				break;
			case 1:
				nx--;
				break;
			case 2:
				ny++;
				break;
			case 3:
				nx++;
				break;
			default:
				break;
			}
			dir -= 1;
			if (dir < 0) {
				dir = 3;
			}
			if (map[nx][ny] == 0) {
				map[nx][ny] = 2;
				q.push(make_pair(nx, ny));
				ans++;
				break;
			}
		}
	}
	return 0;
}