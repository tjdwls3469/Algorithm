#include <iostream>
#include <queue>
using namespace std;

int row;
int col;
int map[100][100];
bool check[100][100][5];
int sx, sy, sd;
int ex, ey, ed;
pair<int, int> dir[] = { {0,0}, {0,1}, {0,-1}, {1,0}, {-1,0} };
queue<pair<pair<int, int>, pair<int, int>>> q;

bool goal(int fx, int fy, int fd) {
	return (fx == ex && fy == ey && fd == ed);
}

void move(int fx, int fy, int fd, int fc) {
	for (int i = 1; i <= 3; i++) {
		int nx = fx + dir[fd].first*i;
		int ny = fy + dir[fd].second*i;
		if (nx < 0 || nx >= row || ny < 0 || ny >= col) {
			break;
		}
		if (map[nx][ny] == 1) {
			break;
		}
		if (check[nx][ny][fd] == false) {
			check[nx][ny][fd] = true;
			q.push({ {nx,ny}, {fd,fc + 1} });
		}
	}
}

void bfs(int x, int y, int d) {
	check[x][y][d] = true;
	q.push({ {x,y}, {d,0} });
	while (!q.empty()) {
		int fx = q.front().first.first;
		int fy = q.front().first.second;
		int fd = q.front().second.first;
		int fc = q.front().second.second;
		q.pop();
		if (goal(fx, fy, fd) == true) {
			cout << fc;
		}

		// 현재 방향에서 1,2,3 이동
		move(fx, fy, fd, fc);

		// 오른쪽 회전
		int nd;
		if (fd == 3) {
			nd = fd - 1;
		}else{
			nd = (fd + 2) % 5;
		}
		if (check[fx][fy][nd] == false) {
			check[fx][fy][nd] = true;
			q.push({ { fx,fy }, { nd,fc + 1 } });
		}

		// 왼쪽 회전
		if (fd == 2) {
			nd = fd + 1;
		}
		else {
			nd = (fd + 3) % 5;
		}
		if (check[fx][fy][nd] == false) {
			check[fx][fy][nd] = true;
			q.push({ { fx,fy }, { nd,fc + 1 } });
		}

		// 180도 회전
		if (fd == 1 || fd == 3) {
			nd = fd + 1;
		}
		else {
			nd = fd - 1;
		}
		if (check[fx][fy][nd] == false) {
			check[fx][fy][nd] = true;
			q.push({ { fx,fy }, { nd,fc + 2 } });
		}
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> row >> col;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cin >> map[i][j];
		}
	}
	cin >> sx >> sy >> sd;
	cin >> ex >> ey >> ed;
	sx--; sy--;
	ex--; ey--;
	bfs(sx, sy, sd);
	return 0;
}