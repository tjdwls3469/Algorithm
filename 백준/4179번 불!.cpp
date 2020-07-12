#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int col;
int row;
string map[1000];
bool check[1000][1000];
vector<pair<int, int>> fire;
int dx[] = { 0, -1, 0, 1 };
int dy[] = { -1, 0, 1, 0 };
int ans;

bool isEscape(int x, int y) {		// 지훈이 탈출 확인
	return (x < 0 || x >= row || y < 0 || y >= col) ? true : false;
}

bool bfs(int x, int y) {
	queue<pair<pair<int, int>, int>> sq;		// x,y, 시간 (지훈이 큐)
	queue<pair<int, int>> fq;		// x,y (불 큐)

	for (int i = 0; i < fire.size(); i++) {		// fire좌표 큐에 넣기
		fq.push({ fire[i].first, fire[i].second });
	}
	sq.push({ { x,y }, 0 });		// 지훈이 위치 넣기

	while (!sq.empty()) {
		int fqSize = fq.size();
		for (int i = 0; i < fqSize; i++) {	// 불 이동
			int fx = fq.front().first;
			int fy = fq.front().second;
			fq.pop();
			for (int i = 0; i < 4; i++) {
				int nx = fx + dx[i];
				int ny = fy + dy[i];
				if (nx >= 0 && nx < row && ny >= 0 && ny < col) {
					if (map[nx][ny] == '.' || map[nx][ny] == 'J') {
						map[nx][ny] = 'F';
						fq.push({ nx,ny });
					}
				}
			}
		}

		int sqSize = sq.size();
		for (int i = 0; i < sqSize; i++) {
			int fx = sq.front().first.first;
			int fy = sq.front().first.second;
			int fd = sq.front().second;
			sq.pop();
			for (int i = 0; i < 4; i++) {
				int nx = fx + dx[i];
				int ny = fy + dy[i];
				if (isEscape(nx, ny) == true) {
					ans = fd + 1;
					return true;
				}
				if (nx >= 0 && nx < row && ny >= 0 && ny < col) {
					if (check[nx][ny] == false && map[nx][ny] == '.') {
						check[nx][ny] = true;
						map[nx][ny] = 'J';
						sq.push({ {nx,ny},fd + 1 });
						if (map[fx][fy] == 'J') {
							map[fx][fy] = '.';
						}
					}
				}
			}
		}
	}
	return false;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	vector<pair<int, int>> temp;		// clear()는 메모리가 남기 때문에 
	fire = temp;						// 이런식으로 초기화
	memset(check, false, sizeof(check));

	int x;		// 지훈이 시작 위치
	int y;
	cin >> row >> col;		// 상근이는 col->row 순서로 입력 받고 이번문제는 row->col순서로 입력
	for (int i = 0; i < row; i++) {		// map입력, fire좌표, 상근이 좌표
		cin >> map[i];
		for (int j = 0; j < map[i].length(); j++) {
			if (map[i][j] == 'F') {
				fire.push_back({ i,j });
				continue;
			}
			if (map[i][j] == 'J') {
				x = i;
				y = j;
			}
		}
	}

	if (bfs(x, y) == true) {
		cout << ans;
	}
	else {
		cout << "IMPOSSIBLE";
	}
	
	return 0;
}