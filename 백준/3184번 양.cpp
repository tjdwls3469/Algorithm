#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <tuple>
using namespace std;

int row;
int col;
int sheepTot;
int wolfTot;
int dx[] = { 0, -1, 0, 1 };
int dy[] = { -1 ,0, 1 ,0 };
bool check[250][250];

void bfs(int x, int y, vector<string> garden) {
	int sheep = 0;
	int wolf = 0;
	queue<pair<int, int>> q;
	check[x][y] = true;
	q.push(make_pair(x, y));
	while (!q.empty()) {
		int fx;
		int fy;
		tie(fx, fy) = q.front();
		q.pop();
		if (garden[fx][fy] == 'o') {
			sheep++;
		}
		else if (garden[fx][fy] == 'v') {
			wolf++;
		}
		else {
			;
		}
		for (int i = 0; i < 4; i++) {
			int nx = fx + dx[i];
			int ny = fy + dy[i];
			if (nx < 0 || nx >= row || ny < 0 || ny >= col) {
				continue;
			}
			if (garden[nx][ny] != '#' && check[nx][ny] == false) {
				check[nx][ny] = true;
				q.push(make_pair(nx, ny));
			}
		}
	}
	if (sheep > wolf) {
		wolfTot -= wolf;
	}
	else {
		sheepTot -= sheep;
	}
}

int main() {
	cin >> row >> col;
	vector<string> garden(row);
	for (int i = 0; i < row; i++) {
		cin >> garden[i];
	}
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (garden[i][j] == 'o') {
				sheepTot++;
			}
			else if (garden[i][j] == 'v') {
				wolfTot++;
			}
			else {
				;
			}
		}
	}
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (garden[i][j] != '#' && check[i][j] == false) {
				bfs(i, j, garden);
			}
		}
	}
	cout << sheepTot << ' ' << wolfTot << '\n';
	return 0;
}