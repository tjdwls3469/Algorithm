#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

bool check[1001];
vector<int> edge[1001];

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
		int vertex = q.front();
		q.pop();
		cout << vertex << ' ';
		for (int i = 0; i < edge[vertex].size(); i++) {
			int next = edge[vertex][i];
			if (check[next] == false) {
				check[next] = true;
				q.push(next);
			}
		}
	}
}

int main() {
	int vertexCnt;
	int edgeCnt;
	int start;
	cin >> vertexCnt >> edgeCnt >> start;
	for (int i = 1; i <= edgeCnt; i++) {
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
	memset(check, false, sizeof(check));
	cout << '\n';
	bfs(start);

	return 0;
}