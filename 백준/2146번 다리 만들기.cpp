/*
문제 : 한개의 섬에서 아무 섬으로의 최단거리 구하기
아이디어 : 테두리에서 BFS 돌려서 최소값 찾아보자
1. 섬을 구분하자
2. 테두리 좌표 구하자
3. BFS로 최단거리 구한 후 비교
*/

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
int map[100][100];
bool check[100][100];
int dx[] = { 0, -1, 0, 1 };
int dy[] = { -1, 0, 1, 0 };
vector<pair<pair<int,int>, int>> start; // 테두리 좌표와 섬의 번호를 넣어둘 공간

void bfs(int x, int y, int number) { // 섬 구분하는 BFS ( 1번 섬, 2번 섬 ... )
	memset(check, false, sizeof(check));
	queue<pair<int, int>> q;
	check[x][y] = true;
	map[x][y] = number;
	q.push(make_pair(x, y));
	while (!q.empty()) {
		int fx = q.front().first;
		int fy = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = fx + dx[i];
			int ny = fy + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
				if (map[nx][ny] != 0 && check[nx][ny] == false) {
					check[nx][ny] = true;
					map[nx][ny] = number;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
}

int bfsAns(int x, int y, int cur_island) { // 현재 섬에서 다른 섬까지의 최단 거리
	memset(check, false, sizeof(check));
	int dist;
	queue<pair<pair<int, int>, int>> q; // x,y좌표 와 거리를 넣는 큐
	check[x][y] = true;
	q.push(make_pair(make_pair(x, y), 1)); // 테두리부터 시작하기때문에 이미 한칸 온거임
	while (!q.empty()) {
		int fx = q.front().first.first;
		int fy = q.front().first.second;
		dist = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = fx + dx[i];
			int ny = fy + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
				if (map[nx][ny] != 0 && map[nx][ny] != cur_island) {
					return dist;
				}
				if (check[nx][ny] == false && map[nx][ny] == 0) {
					check[nx][ny] = true;
					q.push(make_pair(make_pair(nx, ny), dist+1)); // 다음칸으로 갈때 거리+1 해주기
				}
			}
		}
	}
	return dist;
}

void makeBorder() {
	// 테두리인 0을 찾는 과정입니다.
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			// 값이 0이면서 0<열<n-1 이면 
			// 값이 0인 곳의 좌우에 하나라도 0이 아니면 테두리
			if (map[i][j] == 0 && j != 0 && j != n - 1) {
				if (map[i][j - 1] != 0) {
					start.push_back(make_pair(make_pair(i, j), map[i][j - 1]));
					continue;
				}
				if (map[i][j + 1] != 0) {
					start.push_back(make_pair(make_pair(i, j), map[i][j + 1]));
					continue;
				}
			}
			// 값이 0이면서 제일 왼쪽일때
			// 값이 0인 곳의 오른쪽이 0이 아니면 테투리
			if (map[i][j] == 0 && j == 0) {
				if (map[i][j + 1] != 0) {
					start.push_back(make_pair(make_pair(i, j), map[i][j + 1]));
					continue;
				}
			}
			// 값이 0이면서 가장 오른쪽일때
			// 값이 0인 곳의 왼쪽이 0이 아니면 테두리
			if (map[i][j] == 0 && j == n - 1) {
				if (map[i][j - 1] != 0) {
					start.push_back(make_pair(make_pair(i, j), map[i][j - 1]));
					continue;
				}
			}

			// 값이 0이면서 0<행<n-1 이면 
			// 값이 0인 곳의 위아래에 하나라도 0이 아니면 테두리
			if (map[i][j] == 0 && i != 0 && i != n - 1) {
				if (map[i - 1][j] != 0) {
					start.push_back(make_pair(make_pair(i, j), map[i - 1][j]));
					continue;
				}
				if (map[i + 1][j] != 0) {
					start.push_back(make_pair(make_pair(i, j), map[i + 1][j]));
					continue;
				}
			}
			// 값이 0이면서 제일 위쪽일때
			// 값이 0인 곳의 아래쪽이 0이 아니면 테투리
			if (map[i][j] == 0 && i == 0) {
				if (map[i + 1][j] != 0) {
					start.push_back(make_pair(make_pair(i, j), map[i + 1][j]));
					continue;
				}
			}
			// 값이 0이면서 가장 아래쪽일때
			// 값이 0인 곳의 위쪽이 0이 아니면 테두리
			if (map[i][j] == 0 && i == n - 1) {
				if (map[i - 1][j] != 0) {
					start.push_back(make_pair(make_pair(i, j), map[i - 1][j]));
					continue;
				}
			}
		}
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	// 1번 섬, 2번 섬 ... 이런식으로 섬 구분하기
	int number = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 1 && check[i][j] == false) {
				number++;
				bfs(i, j, number);
			}
		}
	}
	makeBorder(); // BFS를 돌릴 시작점 찾기(테두리 찾기), start백터에 시작점 넣는 작업
	int ans = 100000;
	for (int i = 0; i < start.size(); i++) { // start에 테두리 좌표 들어있음
		int x = start[i].first.first;
		int y = start[i].first.second;
		int island = start[i].second;
		int val = bfsAns(x,y, island);
		ans = min(ans, val);
	}
	cout << ans;
	return 0;
}