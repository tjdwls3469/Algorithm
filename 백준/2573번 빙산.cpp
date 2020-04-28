/*
���� : ������ ������ ���� ���� ���� ã��
���̵�� : BFS�����鼭 ��,��,��,�Ͽ� �ִ� 0��ŭ ���簪�� ������
1. map�� temp�� �����Ѵ�
2. map���� BFS���鼭 ��ƾ��ϴ� �� temp�� ����
3. temp�� map�� �����Ѵ�
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
				// �������Ͽ� 0�� ������ temp�� ���ش�
				// map�� �ٷ� �����ϸ� �־��� ���ÿ� �ٸ��� �ȴ�
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
	memcpy(temp, map, sizeof(map)); // temp�� map�� ����
	while (true) {
		memset(check, false, sizeof(check));
		bool one = false; // BFS �ѹ� ���Ҵ�?
		ans++;
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (map[i][j] != 0 && check[i][j] == false) {
					if (one == false) { // BFS�� ó�� ���°Ÿ�
						one = true;
						bfs(i, j);
						memcpy(map, temp, sizeof(temp)); 
						// BFS���� �� ���� ���ϰ� ����� temp�� map�� ����
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