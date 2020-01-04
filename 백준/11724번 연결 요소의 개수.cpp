#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> edgeInfo[1001];
bool check[1001];

void bfs(int start) {
	queue<int> q;
	check[start] = true;
	q.push(start);
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		for (int i = 0; i < edgeInfo[node].size(); i++) {
			int next = edgeInfo[node][i];
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
	int ans = 0;
	cin >> vertexCnt >> edgeCnt;
	for (int i = 0; i < edgeCnt; i++) {
		int vertex1;
		int vertex2;
		cin >> vertex1;
		cin >> vertex2;
		edgeInfo[vertex1].push_back(vertex2);
		edgeInfo[vertex2].push_back(vertex1);
	}
	for (int i = 1; i <= vertexCnt; i++) {
		if (check[i] == false) {
			ans++;
			bfs(i);
		}
	}
	cout << ans;
	return 0;
}