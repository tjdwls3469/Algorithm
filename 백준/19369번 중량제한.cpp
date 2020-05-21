/*
1���� �־��� ������ �ִ밪���� ����Ž���ϰ�
BFS�� ���� mid��(�߷�)�� �������� ���������� ���������� �����Ҽ��ִ��� ���Ѵ�
*/
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int islandCnt;
int infoCnt;
int start; // ���� ��
int finish; // ���� ��
int ans = -1;
vector<pair<int,int>> map[10001]; //  ����� ����ȣ�� �߷���������
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
	if (bfs(start, mid) == true) { // BFS�� true�� �����ϸ� ������ �����ߴٴ� ��
		if (ans == -1 || mid > ans) {
			ans = mid;
		}
		solve(mid + 1, right); // �׷��ٸ� �߷��� ����
	}
	else {
		solve(left, mid - 1); // �ƴϸ� �߷��� ����
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
			right = weight; // right�� �־��� �߷��� �ִ� �߷��� ����
		}
	}
	cin >> start >> finish;
	solve(left, right);
	cout << ans;
	return 0;
}