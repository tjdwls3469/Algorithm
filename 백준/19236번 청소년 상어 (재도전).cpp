#include <iostream>
#include <algorithm>
using namespace std;

typedef struct fish {
	int x;
	int y;
	int num;
	int dir;
}Fish;

int map[4][4];
Fish shark;
Fish fish[17];
int ans;
int dx[] = { 0, -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[] = { 0, 0, -1, -1, -1, 0, 1, 1, 1 };

void dfs(Fish *fish, int(*map)[4], Fish shark, int sum) {
	ans = max(ans, sum);

	for (int i = 1; i <= 16; i++) {
		int fx = fish[i].x;
		int fy = fish[i].y;
		int fDir = fish[i].dir;

		if (fDir == 0) {		// 죽은 물고기
			continue;
		}

		int dirCnt = 0;
		int nx = fx + dx[fDir];
		int ny = fy + dy[fDir];

		for (dirCnt = 0; dirCnt < 8; dirCnt++) {
			nx = fx + dx[fDir];
			ny = fy + dy[fDir];

			if (nx < 0 || nx >= 4 || ny < 0 || ny >= 4) {
				fish[i].dir = (fDir == 8) ? 1 : fDir + 1;
				fDir = fish[i].dir;
				continue;
			}
			if (nx == shark.x && ny == shark.y) {
				fish[i].dir = (fDir == 8) ? 1 : fDir + 1;
				fDir = fish[i].dir;
				continue;
			}
			break;
		}
		if (dirCnt == 8) {		// 이동할 수 있는 칸이 없으면 이동을 하지 않는다
			continue;
		}

		int nextNum = map[nx][ny];
		if (nextNum == 0) {
			map[fx][fy] = 0;
		}
		else {
			fish[nextNum].x = fx;		// 물고기가 다른 물고기가 있는 칸으로 
			fish[nextNum].y = fy;       // 이동할 때는 서로의 위치를 바꾼다
			map[fx][fy] = nextNum;
		}
		fish[i].x = nx;
		fish[i].y = ny;
		map[nx][ny] = i;
	}

	int fx = shark.x;
	int fy = shark.y;
	int fDir = shark.dir;

	for (int i = 1; i <= 3; i++) {
		Fish tempFish[17];
		for (int j = 0; j < 17; j++) {		// 깊은복사
			tempFish[j] = fish[j];
		}

		int tempMap[4][4];
		for (int j = 0; j < 4; j++) {		// 깊은복사
			for (int k = 0; k < 4; k++) {
				tempMap[j][k] = map[j][k];
			}
		}

		int nx = fx + dx[fDir] * i;
		int ny = fy + dy[fDir] * i;
		if (nx < 0 || nx >= 4 || ny < 0 || ny >= 4) {
			continue;
		}
		if (tempMap[nx][ny] == 0) {
			continue;
		}
		shark.x = nx;
		shark.y = ny;
		int num = tempMap[nx][ny];
		tempMap[nx][ny] = 0;
		shark.dir = tempFish[num].dir;		// 물고기를 먹고, 그 물고기의 방향을 가진다
		tempFish[num].dir = 0;

		dfs(tempFish, tempMap, shark, sum + num);
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int fishNum;
	int fishDir;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> fishNum;
			cin >> fishDir;
			if (i == 0 && j == 0) {
				shark = { i,j,fishNum,fishDir };
				continue;
			}
			fish[fishNum] = { i,j,fishNum,fishDir };
			map[i][j] = fishNum;
		}
	}
	dfs(fish, map, shark, shark.num);
	cout << ans;
	return 0;
}