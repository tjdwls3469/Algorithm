#include <iostream>
#include <queue>
using namespace std;

int map[50][50];
int ans;
int row;
int col;

bool noSpace(int x, int y) {		// 네 방향 모두 청소가 되어있거나 벽인 경우 true
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
	map[x][y] = 2;		// 현재 위치 청소
	q.push(make_pair(x, y));
	ans++;
	while (!q.empty()) {
		int fx = q.front().first;
		int fy = q.front().second;
		q.pop();
		if (noSpace(fx, fy) == true) {		// 네 방향 모두 청소가 이미 되어있거나 벽인 경우
			switch (dir) {		// 한 칸 후진
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
			if (map[fx][fy] == 1) {		// 후진 할 수 없는 경우에는 작동을 멈춘다
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
			switch (dir) {		// 다음 한 칸을 전진
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
			dir -= 1;		// 왼쪽 방향으로 회전
			if (dir < 0) {
				dir = 3;
			}
			if (map[nx][ny] == 0) {		// 청소
				map[nx][ny] = 2;
				q.push(make_pair(nx, ny));
				ans++;
				break;
			}
		}
	}
	return 0;
}