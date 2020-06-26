#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int sx; // (sx,sy) : 상어 위치
int sy;
int rc; // row,col
int map[20][20];
bool check[20][20];
int dx[] = { -1, 0, 0, 1 };
int dy[] = { 0, -1, 1, 0 };
int ans;
int shark = 2; // 상어 크기
int eat = 0; // 먹은 개수

/*
	cmp : 우선순위큐 정렬 기준
	pair<pair<int, int>, int> : (x,y)좌표, 거리
	가장 위에 있는 물고기가 여러마리라면, 가장 왼쪽에 있는 물고기를 먹는다.
	거리가 가까운 물고기가 많다면, 가장 위에 있는 물고기를 먹는다.
	둘다 아니면 거리가 가까운 물고리를 먹는다.
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
	priority_queue : (x,y)좌표와 거리 저장
	cmp에 의해 내부 정렬된다
*/
void bfs(int x, int y) {
	priority_queue< pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, cmp> q;
	check[x][y] = true;
	q.push({ {x,y},0 });
	while (!q.empty()) {
		int fx = q.top().first.first;
		int fy = q.top().first.second;
		int time = q.top().second;
		if (map[fx][fy] < shark && map[fx][fy] != 0) { // 상어보다 작은 물고기 먹는다
			eat++;
			if (eat == shark) { // 먹은개수와 상어크기가 같으면 (상어 + 1)
				shark++;
				eat = 0;
			}
			ans += time;
			memset(check, false, sizeof(check));
			priority_queue< pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, cmp> temp;
			swap(q, temp); // 빈 큐(temp)를 만들고 교체를 통해 큐(q)를 비워준다 
			check[fx][fy] = true;
			q.push({ {fx,fy},0 });
			time = 0;
			map[sx][sy] = 0; // 상어위치를 0으로 변경, 현재 위치를 상어 위치로 변경
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