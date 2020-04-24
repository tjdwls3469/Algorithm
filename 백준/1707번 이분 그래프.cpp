#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<int> edge[20001];
int check[20001];
int vertexCnt;
int edgeCnt;

bool dfs(int start, int c) {
	check[start] = c;
	for (int i = 0; i < edge[start].size(); i++) {
		int next = edge[start][i];
		if (check[next] == 0) {
			if (dfs(next, 3 - c) == false) {
				return false;
			}
		}
		else if (check[next] == c) {
			return false;
		}
	}
	return true;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int tc;
	cin >> tc;
	for (int i = 0; i < tc; i++) {
		for (int j = 0; j <= 20001; j++) {
			edge[j].clear();
			check[j] = 0;
		}
		cin >> vertexCnt >> edgeCnt;
		for (int j = 0; j < edgeCnt; j++) {
			int vertex1;
			int vertex2;
			cin >> vertex1 >> vertex2;
			edge[vertex1].push_back(vertex2);
			edge[vertex2].push_back(vertex1);
		}
		bool ok = true;
		for (int j = 1; j <= vertexCnt; j++) {
			if (check[j] == 0) {
				if (dfs(j, 1) == false) {
					ok = false;
				}
			}
		}
		if (ok == true) {
			cout << "YES" << '\n';
		}
		else {
			cout << "NO" << '\n';
		}
	}
	return 0;
}