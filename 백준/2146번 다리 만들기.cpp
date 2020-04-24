/*
���� : �Ѱ��� ������ �ƹ� �������� �ִܰŸ� ���ϱ�
���̵�� : �׵θ����� BFS ������ �ּҰ� ã�ƺ���
1. ���� ��������
2. �׵θ� ��ǥ ������
3. BFS�� �ִܰŸ� ���� �� ��
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
vector<pair<pair<int,int>, int>> start; // �׵θ� ��ǥ�� ���� ��ȣ�� �־�� ����

void bfs(int x, int y, int number) { // �� �����ϴ� BFS ( 1�� ��, 2�� �� ... )
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

int bfsAns(int x, int y, int cur_island) { // ���� ������ �ٸ� �������� �ִ� �Ÿ�
	memset(check, false, sizeof(check));
	int dist;
	queue<pair<pair<int, int>, int>> q; // x,y��ǥ �� �Ÿ��� �ִ� ť
	check[x][y] = true;
	q.push(make_pair(make_pair(x, y), 1)); // �׵θ����� �����ϱ⶧���� �̹� ��ĭ �°���
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
					q.push(make_pair(make_pair(nx, ny), dist+1)); // ����ĭ���� ���� �Ÿ�+1 ���ֱ�
				}
			}
		}
	}
	return dist;
}

void makeBorder() {
	// �׵θ��� 0�� ã�� �����Դϴ�.
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			// ���� 0�̸鼭 0<��<n-1 �̸� 
			// ���� 0�� ���� �¿쿡 �ϳ��� 0�� �ƴϸ� �׵θ�
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
			// ���� 0�̸鼭 ���� �����϶�
			// ���� 0�� ���� �������� 0�� �ƴϸ� ������
			if (map[i][j] == 0 && j == 0) {
				if (map[i][j + 1] != 0) {
					start.push_back(make_pair(make_pair(i, j), map[i][j + 1]));
					continue;
				}
			}
			// ���� 0�̸鼭 ���� �������϶�
			// ���� 0�� ���� ������ 0�� �ƴϸ� �׵θ�
			if (map[i][j] == 0 && j == n - 1) {
				if (map[i][j - 1] != 0) {
					start.push_back(make_pair(make_pair(i, j), map[i][j - 1]));
					continue;
				}
			}

			// ���� 0�̸鼭 0<��<n-1 �̸� 
			// ���� 0�� ���� ���Ʒ��� �ϳ��� 0�� �ƴϸ� �׵θ�
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
			// ���� 0�̸鼭 ���� �����϶�
			// ���� 0�� ���� �Ʒ����� 0�� �ƴϸ� ������
			if (map[i][j] == 0 && i == 0) {
				if (map[i + 1][j] != 0) {
					start.push_back(make_pair(make_pair(i, j), map[i + 1][j]));
					continue;
				}
			}
			// ���� 0�̸鼭 ���� �Ʒ����϶�
			// ���� 0�� ���� ������ 0�� �ƴϸ� �׵θ�
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
	// 1�� ��, 2�� �� ... �̷������� �� �����ϱ�
	int number = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 1 && check[i][j] == false) {
				number++;
				bfs(i, j, number);
			}
		}
	}
	makeBorder(); // BFS�� ���� ������ ã��(�׵θ� ã��), start���Ϳ� ������ �ִ� �۾�
	int ans = 100000;
	for (int i = 0; i < start.size(); i++) { // start�� �׵θ� ��ǥ �������
		int x = start[i].first.first;
		int y = start[i].first.second;
		int island = start[i].second;
		int val = bfsAns(x,y, island);
		ans = min(ans, val);
	}
	cout << ans;
	return 0;
}