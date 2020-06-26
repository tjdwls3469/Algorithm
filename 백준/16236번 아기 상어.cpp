#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int sx; // (sx,sy) : ��� ��ġ
int sy;
int rc; // row,col
int map[20][20];
bool check[20][20];
int dx[] = { -1, 0, 0, 1 };
int dy[] = { 0, -1, 1, 0 };
int ans;
int shark = 2; // ��� ũ��
int eat = 0; // ���� ����

/*
	cmp : �켱����ť ���� ����
	pair<pair<int, int>, int> : (x,y)��ǥ, �Ÿ�
	���� ���� �ִ� ����Ⱑ �����������, ���� ���ʿ� �ִ� ����⸦ �Դ´�.
	�Ÿ��� ����� ����Ⱑ ���ٸ�, ���� ���� �ִ� ����⸦ �Դ´�.
	�Ѵ� �ƴϸ� �Ÿ��� ����� ������ �Դ´�.
*/
struct cmp {
	bool operator()(pair<pair<int, int>, int> x, pair<pair<int, int>, int> y) {
		if (x.second == y.second && x.first.first == y.first.first) {
			return x.first.second > y.first.second;
		}
		else if (x.second == y.second && x.first.first) {
			return x.first.first > y.first.first;
		}
		return x.second > y.second;
	}
};

/*
	priority_queue : (x,y)��ǥ�� �Ÿ� ����
	cmp�� ���� ���� ���ĵȴ�
*/
void bfs(int x, int y) {
	priority_queue< pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, cmp> q;
	check[x][y] = true;
	q.push({ {x,y},0 });
	while (!q.empty()) {
		int fx = q.top().first.first;
		int fy = q.top().first.second;
		int time = q.top().second;
		if (map[fx][fy] < shark && map[fx][fy] != 0) { // ���� ���� ����� �Դ´�
			eat++;
			if (eat == shark) { // ���������� ���ũ�Ⱑ ������ (��� + 1)
				shark++;
				eat = 0;
			}
			ans += time;
			memset(check, false, sizeof(check));
			priority_queue< pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, cmp> temp;
			swap(q, temp); // �� ť(temp)�� ����� ��ü�� ���� ť(q)�� ����ش� 
			check[fx][fy] = true;
			q.push({ {fx,fy},0 });
			time = 0;
			map[sx][sy] = 0; // �����ġ�� 0���� ����, ���� ��ġ�� ��� ��ġ�� ����
			sx = fx;
			sy = fy;
		}
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = fx + dx[i];
			int ny = fy + dy[i];
			if (nx >= 0 && nx < rc && ny >= 0 && ny < rc) {
				if (check[nx][ny] == false && map[nx][ny] <= shark) {
					check[nx][ny] = true;
					q.push({ {nx,ny},time + 1 });
				}
			}
		}
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> rc;
	for (int i = 0; i < rc; i++) {
		for (int j = 0; j < rc; j++) {
			cin >> map[i][j];
			if (map[i][j] == 9) {
				sx = i;
				sy = j;
			}
		}
	}
	bfs(sx, sy);
	cout << ans;
	return 0;
}