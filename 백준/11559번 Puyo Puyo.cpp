/*
1. BFS돌면서 같은색 4개 이상 찾기
2. 4개 이상이면 터뜨리기
3. 터진 후 뿌요 내려 맵 수정하기
*/
#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

string map[12];
bool check[12][6];
int dx[] = { 0, -1, 0, 1 };
int dy[] = { -1, 0, 1, 0 };
vector<pair<int, int>> sameColor; // 같은 색 뿌요 위치 좌표 저장
int ans;

void move() { // 뿌요 이동시키기
	for (int i = 0; i < 6; i++) {
		for (int j = 10; j >= 0; j--) {
			for (int k = 11; k > j; k--) {
				if (map[j][i] != '.' && map[k][i] == '.') {
					map[k][i] = map[j][i];
					map[j][i] = '.';
					break;
				}
			}
		}
	}
}

void bfs(int x, int y, char ch) {
	queue<pair<int, int>> q;
	check[x][y] = true;
	q.push({ x,y });
	sameColor.push_back({ x,y });
	while (!q.empty()) {
		int fx = q.front().first;
		int fy = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = fx + dx[i];
			int ny = fy + dy[i];
			if (nx >= 0 && nx < 12 && ny >= 0 && ny < 6) {
				if (map[nx][ny] == ch && check[nx][ny] == false) {
					check[nx][ny] = true;
					q.push({ nx,ny });
					sameColor.push_back({ nx, ny });
				}
			}
		}
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	for (int i = 0; i < 12; i++) {
		cin >> map[i];
	}
	while (true) {
		memset(check, false, sizeof(check));
		bool change = false;
		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 6; j++) {
				if (map[i][j] != '.' && check[i][j] == false) {
					sameColor.clear();
					bfs(i, j, map[i][j]);
					if (sameColor.size() >= 4) {
						change = true;
						for (int k = 0; k < sameColor.size(); k++) {
							map[sameColor[k].first][sameColor[k].second] = '.';
						}
					}
				}
			}
		}
		if (change == true) {
			ans++;
			move();
		}
		else {
			break;
		}
	}
	cout << ans;
	return 0;
}