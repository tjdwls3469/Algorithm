#include <iostream>
#include <vector>
using namespace std;

int main() {
	int size;
	cin >> size;
	vector<vector<int>> map(size + 1, vector<int>(size + 1));
	int appleCnt;
	cin >> appleCnt;
	for (int i = 0; i < appleCnt; i++) {
		int row;
		int col;
		cin >> row >> col;
		map[row][col] = -1;
	}
	int dirCnt;
	cin >> dirCnt;
	vector<pair<int, char>> timeDir(dirCnt);
	for (int i = 0; i < dirCnt; i++) {
		int time;
		char dir;
		cin >> time >> dir;
		timeDir[i] = make_pair(time, dir);
	}
	int x = 1;
	int y = 1;
	int ans = 0;
	int len = 1;
	char dir = 'E';
	while (true) {
		if (ans >= timeDir[0].first) {
			for (int i = 0; i < dirCnt; i++) {
				if (ans == timeDir[i].first) {
					char nextDir = timeDir[i].second;
					switch (dir) {
					case 'E':
						if (nextDir == 'D') {
							dir = 'S';
						}
						else {
							dir = 'N';
						}
						break;
					case 'W':
						if (nextDir == 'D') {
							dir = 'N';
						}
						else {
							dir = 'S';
						}
						break;
					case 'S':
						if (nextDir == 'D') {
							dir = 'W';
						}
						else {
							dir = 'E';
						}
						break;
					case 'N':
						if (nextDir == 'D') {
							dir = 'E';
						}
						else {
							dir = 'W';
						}
						break;
					default:; break;
					}
				}
			}
		}
		int nx;
		int ny;
		switch (dir) {
		case 'E':
			nx = x;
			ny = y + 1;
			break;
		case 'W':
			nx = x;
			ny = y - 1;
			break;
		case 'S':
			nx = x + 1;
			ny = y;
			break;
		case 'N':
			nx = x - 1;
			ny = y;
			break;
		default:; break;
		}
		ans++;
		if (nx < 1 || nx > size || ny < 1 || ny > size) {
			cout << ans;
			break;
		}
		if (map[nx][ny] != 0 && map[nx][ny] != -1) {
			if (map[nx][ny] >= map[x][y] - len + 1) {
				cout << ans;
				break;
			}
			map[nx][ny] = ans;
			x = nx;
			y = ny;
		}
		else {
			if (map[nx][ny] == -1) {
				len++;
			}
			map[nx][ny] = ans;
			x = nx;
			y = ny;
		}
	}
	return 0;
}