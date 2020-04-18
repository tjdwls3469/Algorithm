#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

vector<int> edge[1001];
bool check[1001];

void dfs(int start) {
	check[start] = true;
	cout << start << ' ';
	for (int i = 0; i < edge[start].size(); i++) {
		int next = edge[start][i];
		if (check[next] == false) {
			dfs(next);
		}
	}
}

void bfs(int start) {
	queue<int> q;
	check[start] = true;
	q.push(start);
	while (!q.empty()) {
		int cur = q.front();
		cout << cur << ' ';
		q.pop();
		for (int i = 0; i < edge[cur].size(); i++) {
			int next = edge[cur][i];
			if (check[next] == false) {
				check[next] = true;
				q.push(next);
			}
		}
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int vertexCnt;
	int edgeCnt;
	int start;
	cin >> vertexCnt >> edgeCnt >> start;
	for (int i = 0; i < edgeCnt; i++) {
		int vertex1;
		int vertex2;
		cin >> vertex1 >> vertex2;
		edge[vertex1].push_back(vertex2);
		edge[vertex2].push_back(vertex1);
	}
	for (int i = 1; i <= vertexCnt; i++) {
		sort(edge[i].begin(), edge[i].end());
	}
	dfs(start);
	cout << '\n';
	memset(check, false, sizeof(check));
	bfs(start);
	return 0;
}