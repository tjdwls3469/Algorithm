#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int frame[4][4];
pair<pair<int, int>, int> fish[17]; // (x,y)좌표, 방향 저장
bool ch[17];
int dx[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[] = { 0, -1, -1, -1, 0, 1, 1, 1 };
int ans;

void dfs(int x, int y, int dir, int (*map)[4], bool *check, pair<pair<int, int>, int> *fish, int sum) {
	for (int i = 1; i <= 16; i++) {
		if (check[i] == true) continue;

		int fx = fish[i].first.first;
		int fy = fish[i].first.second;
		int fd = fish[i].second;

		for (int j = 0; j < 8; j++) {
			int nd = (fd + j) % 8;
			int nx = fx + dx[nd];
			int ny = fy + dy[nd];

			if (nx < 0 || nx >= 4 || ny < 0 || ny >= 4) continue;
			if (map[nx][ny] == -1) continue;

			if (map[nx][ny] == 0) {
				map[nx][ny] = i;
				map[fx][fy] = 0;
				fish[i].first.first = nx;
				fish[i].first.second = ny;
				fish[i].second = nd;
			}
			else {
				int tempX = fx;
				int tempY = fy;
				int tempNum = map[nx][ny];
				fish[i].first.first = nx;
				fish[i].first.second = ny;
				fish[tempNum].first.first = tempX;
				fish[tempNum].first.second = tempY;
				map[nx][ny] = map[fx][fy];
				map[fx][fy] = tempNum;
			}
			break;
		}

		bool isEat = false;
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		while (nx >= 0 && nx < 4 && ny >= 0 && ny < 4) {
			if (map[nx][ny] > 0) {
				int tempMap[4][4];
				bool tempCheck[17];
				pair<pair<int, int>, int> tempFish[17];

				memcpy(tempMap, map, sizeof(tempMap));
				memcpy(tempCheck, check, sizeof(tempCheck));
				memcpy(tempFish, fish, sizeof(tempFish));

				int next = tempMap[nx][ny];
				tempCheck[next] = true;
				tempMap[x][y] = 0;
				tempMap[nx][ny] = -1;

				dfs(nx, ny, tempFish[next].second, tempMap, tempCheck, tempFish, sum + next);
				isEat = true;

			}
			nx += dx[dir];
			ny += dy[dir];
		}
		if (isEat == false) {
			ans = max(ans, sum);
			return;
		}
	}
	return;
}

int main() {
	int num;
	int dir;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> num;
			cin >> dir;
			fish[num] = { {i,j}, dir };
			frame[i][j] = num;
		}
	}
	ch[frame[0][0]] = true;
	//ans += frame[0][0];
	frame[0][0] = -1;
	dfs(0, 0, fish[frame[0][0]].second, frame, ch, fish, ans);
	cout << ans;
	return 0;
}