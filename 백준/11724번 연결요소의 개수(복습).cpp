#include <iostream>
#include <vector>
using namespace std;

vector<int> edge[1001];
bool check[1001];
void dfs(int start) {
	check[start] = true;
	for (int i = 0; i < edge[start].size(); i++) {
		int next = edge[start][i];
		if (check[next] == false) {
			dfs(next);
		}
	}
}

int main() {
	int vertexCnt;
	int edgeCnt;
	int result = 0;
	cin >> vertexCnt >> edgeCnt;
	for (int i = 0; i < edgeCnt; i++) {
		int vertex1;
		int vertex2;
		cin >> vertex1 >> vertex2;
		edge[vertex1].push_back(vertex2);
		edge[vertex2].push_back(vertex1);
	}
	for (int i = 1; i <= vertexCnt; i++) {
		if (check[i] == false) {
			result++;
			dfs(i);
		}
	}
	cout << result;

	return 0;
}