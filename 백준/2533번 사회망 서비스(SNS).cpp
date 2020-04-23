#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int vertexCnt;
int ans[1000001][2];
bool check[1000001];
vector<int> edge[1000001];


void dfs(int start) {
	check[start] = true;
	ans[start][0] = 0;
	ans[start][1] = 1;
	for (int i = 0; i < edge[start].size(); i++) {
		int next = edge[start][i];
		if (check[next] == false) {
			check[next] = true;
			dfs(next);
			ans[start][0] += ans[next][1];
			ans[start][1] += min(ans[next][0], ans[next][1]);
		}
	}
}

int main() {
	cin >> vertexCnt;
	for (int i = 0; i < vertexCnt - 1; i++) {
		int vertex1;
		int vertex2;
		cin >> vertex1 >> vertex2;
		edge[vertex1].push_back(vertex2);
		edge[vertex2].push_back(vertex1);
	}
	dfs(1);
	cout << min(ans[1][0], ans[1][1]);
	return 0;
}