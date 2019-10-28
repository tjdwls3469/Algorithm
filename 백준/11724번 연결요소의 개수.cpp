#include <iostream>
#include <vector>
using namespace std;

vector<int> vec[1001];
bool check[1001];

void dfs(int node) {
	check[node] = true;
	for (int i = 0; i < vec[node].size(); i++) {
		int next = vec[node][i];
		if (check[next] == false) {
			dfs(next);
		}
	}
}

int main() {
	int n;
	int m;
	int u;
	int v;
	int result = 0;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		vec[u].push_back(v);
		vec[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) {
		if (check[i] == false) {
			dfs(i);
			result++;
		}
	}
	cout << result;

	return 0;
}