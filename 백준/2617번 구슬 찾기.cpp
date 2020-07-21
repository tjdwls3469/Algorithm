#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int beadCnt;
vector<int> map[100];
int val[2][100];
bool check[100];
int cnt;
int ans;

/*
          1  2  3  4  5
smallCnt  0  1  0  3  1
bigCnt    3  1  1  0  0
*/

void dfs(int num) {
	check[num] = true;
	for (int i = 0; i < map[num].size(); i++) {
		if (check[map[num][i]] == false) {
			val[1][map[num][i]]++;
			cnt++;
			dfs(map[num][i]);
		}
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int pairCnt;
	cin >> beadCnt >> pairCnt;

	for (int i = 0; i < pairCnt; i++) {
		int heavy;
		int light;
		cin >> heavy >> light;
		map[heavy].push_back(light);
	}

	for (int i = 1; i <= beadCnt; i++) {
		cnt = 0;
		memset(check, false, sizeof(check));
		dfs(i);
		val[0][i] = cnt;
	}

	for (int i = 0; i < 2; i++) {
		for (int j = 1; j <= beadCnt; j++) {
			//cout << val[i][j] << ' ';
			if (val[i][j] > beadCnt / 2) {
				ans++;
			}
		}
		//cout << '\n';
	}
	cout << ans;

	return 0;
}