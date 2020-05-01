#include <iostream>
#include <algorithm>
using namespace std;

int row;
int col;
int map[1000][1000];
int dist[1000][1000];
int dx[] = { 1, 0, 1 };
int dy[] = { 0, 1, 1 };

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
	dist[0][0] = map[0][0];
	dist[1][0] = map[1][0];
	dist[0][1] = map[0][1];
	for (int i = 1; i < col; i++) {
		dist[0][i] = dist[0][i - 1] + map[0][i];
	}
	for (int i = 1; i < row; i++) {
		dist[i][0] = dist[i - 1][0] + map[i][0];
	}
	for (int i = 1; i < row; i++) {
		for (int j = 1; j < col; j++) {
			if (i - 1 < 0 || j - 1 < 0) {
				continue;
			}
			dist[i][j] += max(max(dist[i - 1][j], dist[i][j - 1]), dist[i - 1][j - 1]) + map[i][j];
		}
	}
	cout << dist[row - 1][col - 1];
	return 0;
}