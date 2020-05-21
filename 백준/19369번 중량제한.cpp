/*
1부터 주어진 값중의 최대값까지 이진탐색하고
BFS를 돌려 mid값(중량)을 기준으로 시작점부터 도착지까지 도달할수있는지 비교한다
*/
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int islandCnt;
int infoCnt;
int start; // 시작 섬
int finish; // 도착 섬
int ans = -1;
vector<pair<int,int>> map[10001]; //  연결된 섬번호와 중량제한정보
bool check[10001];

bool bfs(int island, int weight) {
	memset(check, false, sizeof(check));
	queue<int> q;
	check[island] = true;
	q.push(island);
	while (!q.empty()) {
		int first = q.front();
		q.pop();
		if (first == finish) {
			return true;
		}
		for (int i = 0; i < map[first].size(); i++) {
			int next = map[first][i].first;
			int nextWeight = map[first][i].second;
			if (check[next] == false && weight <= nextWeight) {
				check[next] = true;
				q.push(next);
			}
		}
	}
	return false;
}

void solve(int left, int right) {
	int mid = (left + right) / 2;
	if (left > right) {
		return;
	}
	if (bfs(start, mid) == true) { // BFS가 true를 리턴하면 무사히 도착했다는 뜻
		if (ans == -1 || mid > ans) {
			ans = mid;
		}
		solve(mid + 1, right); // 그렇다면 중량을 높임
	}
	else {
		solve(left, mid - 1); // 아니면 중량을 낮춤
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> islandCnt >> infoCnt;
	int left = 1;
	int right = -1;
	for (int i = 0; i < infoCnt; i++) {
		int island1;
		int island2;
		int weight;
		cin >> island1 >> island2 >> weight;
		map[island1].push_back({ island2, weight });
		map[island2].push_back({ island1, weight });
		if (right == -1 || weight > right) {
			right = weight; // right는 주어진 중량중 최대 중량이 들어간다
		}
	}
	cin >> start >> finish;
	solve(left, right);
	cout << ans;
	return 0;
}