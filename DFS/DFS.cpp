#include <iostream>
#include <vector>

using namespace std;

int checked[7];
vector<int> aryV[7];

void dfs(int x) {
	if (checked[x] == 1) {
		return;
	}

	checked[x] = 1;
	cout << x << " ";

	for (int i = 0; i < aryV[x].size(); i++) {
		int y = aryV[x][i];
		dfs(y);
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

	dfs(1);

	return 0;
}