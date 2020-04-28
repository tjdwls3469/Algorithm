/*
문제 : 빙산이 나누어 지는 최초 시점 찾기
아이디어 : BFS돌리면서 동,서,남,북에 있는 0만큼 현재값을 빼주자
1. map을 temp에 복사한다
2. map에서 BFS돌면서 녹아야하는 건 temp에 적용
3. temp를 map에 복사한다
*/
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int row;
int col;
int map[300][300];
int temp[300][300];
bool check[300][300];
int dx[] = { 0, -1, 0, 1 };
int dy[] = { -1, 0, 1, 0 };
int ans;

void bfs(int x, int y) {
	queue<pair<int, int>> q;
	check[x][y] = true;
	q.push(make_pair(x, y));
	while (!q.empty()) {
		int fx = q.front().first;
		int fy = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = fx + dx[i];
			int ny = fy + dy[i];
			if (nx >= 0 && nx < row && ny >= 0 && ny < col) {
				if (map[nx][ny] != 0 && check[nx][ny] == false) {
					check[nx][ny] = true;
					q.push(make_pair(nx, ny));
				}
				// 동서남북에 0이 있으면 temp에 빼준다
				// map에 바로 적용하면 주어진 예시와 다르게 된다
				if (map[nx][ny] == 0 && temp[fx][fy] > 0) {
					temp[fx][fy]--;
				}
			}
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
	memcpy(temp, map, sizeof(map)); // temp에 map을 복산
	while (true) {
		memset(check, false, sizeof(check));
		bool one = false; // BFS 한번 돌았니?
		ans++;
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (map[i][j] != 0 && check[i][j] == false) {
					if (one == false) { // BFS가 처음 도는거면
						one = true;
						bfs(i, j);
						memcpy(map, temp, sizeof(temp)); 
						// BFS실행 후 녹은 빙하가 저장된 temp를 map에 적용
					}
					else {
						cout << ans - 1;
						return 0;
					}
				}
			}
		}
		if (one == false) {
			cout << 0;
			return 0;
		}
	}
	return 0;
}