#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	long long nodeCnt;
	int conCnt;
	int tc;
	cin >> nodeCnt >> conCnt >> tc;
	long long curNode = 1;
	vector<vector<long long>> edge(nodeCnt + 1);
	for (long long i = 1; i <= nodeCnt; i++) {
		for (int j = 0; j < conCnt; j++) {
			if (curNode == nodeCnt) {
				break;
			}
			edge[i].push_back(++curNode);
			edge[curNode].push_back(i);
		}
		if (curNode == nodeCnt) {
			break;
		}
	}
	for (int i = 0; i < tc; i++) {
		vector<bool> check(nodeCnt + 1);
		long long start;
		long long goal;
		cin >> start >> goal;

		queue<pair<long long, long long>> q;
		check[start] = true;
		q.push(make_pair(start,0));
		while (!q.empty()) {
			long long cur = q.front().first;
			long long dist = q.front().second;
			q.pop();
			if (cur == goal) {
				cout << dist << '\n';
				break;
			}
			for (int i = 0; i < edge[cur].size(); i++) {
				long long next = edge[cur][i];
				if (check[next] == false) {
					check[next] = true;
					q.push(make_pair(next, dist + 1));
				}
			}
		}
	}
	return 0;
}