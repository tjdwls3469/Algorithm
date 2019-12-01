#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <deque>
#include <tuple>
using namespace std;

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

vector<vector<int>> bfs(vector<string> &floorPlan, int x, int y) {
	int height = floorPlan.size();
	int width = floorPlan[0].size();
	vector<vector<int>> result(height, vector<int>(width));
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			result[i][j] = -1;
		}
	}
	deque<pair<int,int>> q;
	q.push_back(make_pair(x, y));
	result[x][y] = 0;
	while (!q.empty()) {
		tie(x, y) = q.front();
		q.pop_front();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= height || ny < 0 || ny >= width) continue;
			if (result[nx][ny] != -1) continue;
			if (floorPlan[nx][ny] == '*') continue;
			if (floorPlan[nx][ny] == '#') {
				result[nx][ny] = result[x][y] + 1;
				q.push_back(make_pair(nx, ny));
			}
			else {
				result[nx][ny] = result[x][y];
				q.push_back(make_pair(nx, ny));
			}
		}
	}
	return result;
}

int main() {
	int cnt;
	cin >> cnt;
	for (int k = 0; k < cnt; k++) {
		int height;
		int width;
		cin >> height >> width;
		vector<string> floorPlan(height + 2);
		for (int i = 1; i <= height; i++) {
			cin >> floorPlan[i];
			floorPlan[i] = "." + floorPlan[i] + ".";
		}
		height += 2;
		width += 2;
		for (int i = 0; i < width; i++) {
			floorPlan[0] += ".";
			floorPlan[height - 1] += ".";
		}
		vector<vector<int>> result1 = bfs(floorPlan, 0, 0);
		int x1, x2, y1, y2;
		x1 = x2 = y1 = y2 = -1;
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				if (floorPlan[i][j] == '$') {
					if (x1 == -1) {
						x1 = i;
						y1 = j;
					}
					else {
						x2 = i;
						y2 = j;
					}
				}
			}
		}
		vector<vector<int>> result2 = bfs(floorPlan, x1, y1);
		vector<vector<int>> result3 = bfs(floorPlan, x2, y2);
		int ans = height * width;
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				if (floorPlan[i][j] == '*') continue;
				int cur = result1[i][j] + result2[i][j] + result3[i][j];
				if (floorPlan[i][j] == '#') {
					cur -= 2;
				}
				if (cur < ans) {
					ans = cur;
				}
			}
		}
		cout << ans << '\n';
	}

	return 0;
}