#include <iostream>
#include <vector>
using namespace std;

vector<int> map[2000];
bool check[2000];
bool isFive;

void dfs(int people, int cnt) {		// 사람번호, 사람 수
	if (cnt == 5) {
		isFive = true;
		return;
	}
	check[people] = true;
	for (int i = 0; i < map[people].size(); i++) {
		if (check[map[people][i]] == false) {
			dfs(map[people][i], cnt + 1);
		}
	}
	check[people] = false;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int pCnt;
	int rCnt;
	cin >> pCnt >> rCnt;

	for (int i = 0; i < rCnt; i++) {
		int people1;
		int people2;
		cin >> people1 >> people2;
		map[people1].push_back(people2);
		map[people2].push_back(people1);
	}

	for (int i = 0; i < pCnt; i++) {
		dfs(i, 1);
		if (isFive == true) {
			cout << 1;
			return 0;
		}
	}
	cout << 0;
	return 0;
}