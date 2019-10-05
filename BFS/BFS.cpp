#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> aryV[7];
int checked[7];

void bfs(int start) {
	queue<int> q;
	q.push(start);
	checked[start - 1] = 1;

	while (!q.empty()) {
		int data = q.front();
		q.pop();
		printf("%d ", data);
		for (int i = 0; i < aryV[data].size(); i++) {
			int dataV = aryV[data][i];
			if (checked[dataV - 1] == 0) {
				q.push(dataV);
				checked[dataV - 1] = 1;
			}
		}
	}
	return;
}

int main() {
	aryV[1].push_back(2);
	aryV[2].push_back(1);

	aryV[1].push_back(3);
	aryV[3].push_back(1);

	aryV[2].push_back(3);
	aryV[3].push_back(2);

	aryV[2].push_back(4);
	aryV[4].push_back(2);

	aryV[2].push_back(5);
	aryV[5].push_back(2);

	aryV[3].push_back(6);
	aryV[6].push_back(3);

	aryV[3].push_back(7);
	aryV[7].push_back(3);

	aryV[4].push_back(5);
	aryV[5].push_back(4);

	aryV[6].push_back(7);
	aryV[7].push_back(6);

	bfs(1);

	return 0;
}