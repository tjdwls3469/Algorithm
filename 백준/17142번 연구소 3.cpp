/*
연구소에 존재하는 바이러스에서 M개를 골라 BFS돌려서 비교하자
*/
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int n;
int cnt;
int map[50][50];
int temp[50][50];
bool check[50][50];
int dx[] = { 0, -1, 0, 1 };
int dy[] = { -1, 0, 1, 0 };
vector<pair<int, int>> virus;
vector<pair<int, int>> choice;
int ans = -1;

void bfs(vector<pair<int, int>> &choice) {
	memset(check, false, sizeof(check));
	memcpy(temp, map, sizeof(map));
	// 큐에는 (x,y)좌표에 시간 저장
	queue<pair<pair<int, int>, int>> q;
	// choice백터에는 연구소 전체의 바이러스중 M개가 들어있음
	for (int i = 0; i < choice.size(); i++) {
		int x = choice[i].first;
		int y = choice[i].second;
		check[x][y] = true;
		// BFS를 시작좌표이기때문에 시간은 0으로 설정
		q.push({ {x, y}, 0 });
	}
	while (!q.empty()) {
		int fx = q.front().first.first;
		int fy = q.front().first.second;
		int d = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = fx + dx[i];
			int ny = fy + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
				// 빈칸이면 
				if (temp[nx][ny] == 0 && check[nx][ny] == false) {
					check[nx][ny] = true;
					q.push({ {nx, ny}, d + 1 });
					temp[nx][ny] = d + 1; // temp에 시간을 업데이트
				}
				// 비활성화 바이러스이면
				if (temp[nx][ny] == -2 && check[nx][ny] == false) {
					check[nx][ny] = true;
					q.push({ {nx, ny}, d + 1});
				}
			}
		}
	}
}

// 선택된 M개의 바이러스는 choice백터에 넣는다
void selectCnt(int index, int select) {
	if (select == cnt) {
		// M개의 바이러스에서 시작되는 BFS
		bfs(choice);
		int max = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				// BFS가 수행 된 후 temp라는 연구소에 시간이 업데이트 된다
				// BFS수행 후 temp에 0이 존재하면 
				// 모든 빈 칸에 바이러스를 퍼뜨릴 수 없는 경우임
				if (temp[i][j] == 0) {
					return;
				}
				// BFS수행 후 걸린 시간은 max변수에 저장
				if (temp[i][j] > max) {
					max = temp[i][j];
				}
			}
		}
		// ans == -1은 BFS에 처음 수행되었을때
		// max값은 BFS한번 수행 후 최종적으로 걸린 시간
		// max값이 ans보다 작으면 ans값 업데이트
		if (ans == -1 || max < ans) {
			ans = max;
		}
		return;
	}
	if (index >= virus.size()) {
		return;
	}
	choice.push_back(make_pair(virus[index].first, virus[index].second));
	selectCnt(index + 1, select + 1);
	choice.pop_back();
	selectCnt(index + 1, select);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> cnt;
	// 벽은 -1, 바이러스는 -2로 바꿔주고 
	// 연구소에 있는 모든 바이러스의 좌표를 virus백터에 넣어준다
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) {
				map[i][j] = -1;
			}
			if (map[i][j] == 2) {
				virus.push_back(make_pair(i, j));
				map[i][j] = -2;
			}
		}
	}
	// 맵에 있는 바이러스중 M개를 선택해서 BFS돌리는 함수
	selectCnt(0, 0);
	cout << ans;
	return 0;
}