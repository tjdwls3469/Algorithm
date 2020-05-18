#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int color[12][12];
vector<int> map[12][12];
pair<int, int> dir[5] = { {0,0}, {0,1}, {0,-1}, {-1,0}, {1,0} };
pair<int, pair<int, int>> piece[11];

int main() {
	int mapSize;
	int pieceCnt;
	cin >> mapSize >> pieceCnt;
	for (int i = 0; i < mapSize; i++) {
		for (int j = 0; j < mapSize; j++) {
			cin >> color[i][j];
		}
	}
	for (int i = 1; i <= pieceCnt; i++) {
		int temp[3];
		for (int j = 0; j < 3; j++) {
			cin >> temp[j];
		}
		piece[i] = { temp[0] , {temp[1], temp[2]} };
		map[temp[1]][temp[2]].push_back(i);
	}
	int ans = 0;
	int check = false;
	while (true) {
		ans++;
		if (ans > 1000) {
			cout << -1;
			return 0;
		}
		for (int i = 1; i <= pieceCnt; i++) {
			int fx = piece[i].second.first;
			int fy = piece[i].second.second;
			int nx = fx + dir[piece[i].first].first;
			int ny = fy + dir[piece[i].first].second;
			if (nx >= 0 && nx < mapSize && ny >= 0 && ny < mapSize) {
				if (color[nx][ny] == 2) {
					if (piece[i].first % 2 == 0) {
						piece[i].first -= 1;
					}
					else {
						piece[i].first += 1;
					}
				}
				else if (color[nx][ny] == 0) {
					int index = -1;
					for (int j = 0; j < map[fx][fy].size(); j++) {
						if (map[fx][fy][j] == i) {
							index = j;
						}
					}
					if (index != -1) {
						for (int j = index; j < map[fx][fy].size(); j++) {
							map[nx][ny].push_back(map[fx][fy][j]);
						}
						map[fx][fy].erase(map[fx][fy].begin() + index, map[fx][fy].end());
					}
					if (map[nx][ny].size() >= 4) {
						check = true;
					}
					if (check == true){
						break;
					}
				}
				else {
					int index = -1;
					for (int j = 0; j < map[fx][fy].size(); j++) {
						if (map[fx][fy][j] == i) {
							index = j;
						}
					}
					if (index != -1) {
						reverse(map[fx][fy].begin() + index, map[fx][fy].end());
						for (int j = index; j < map[fx][fy].size(); j++) {
							map[nx][ny].push_back(map[fx][fy][j]);
						}
						map[fx][fy].erase(map[fx][fy].begin() + index, map[fx][fy].end());
					}
					if (map[nx][ny].size() >= 4) {
						check = true;
					}
					if (check == true) {
						break;
					}
				}
			}
			else {
				if (piece[i].first % 2 == 0) {
					piece[i].first -= 1;
				}
				else {
					piece[i].first += 1;
				}
			}
		}
	}
	cout << ans;
	return 0;
}