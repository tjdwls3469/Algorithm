#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int check[1001];
vector<int> graph[1001];

void dfs(int node) {
	check[node] = true;
	cout << node << ' ';
	for (int i = 0; i < graph[node].size(); i++) {
		int next = graph[node][i];
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
		int node = q.front();
		q.pop();
		cout << node << ' ';
		for (int i = 0; i < graph[node].size(); i++) {
			int next = graph[node][i];
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
	for (int i = 0; i < edgeCnt; i++) {
		int vertex1;
		int vertex2;
		cin >> vertex1 >> vertex2;
		graph[vertex1].push_back(vertex2);
		graph[vertex2].push_back(vertex1);
	}
	for (int i = 0; i < vertexCnt; i++) {
		sort(graph[i].begin(), graph[i].end());
	}
	dfs(start);
	memset(check, false, sizeof(check));
	cout << '\n';
	bfs(start);
	return 0;
}