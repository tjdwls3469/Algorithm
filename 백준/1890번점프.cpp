/*
ans[i][j] = (i,j)에 갈수있는 경로의 개수
*/
#include <iostream>
using namespace std;

int map[100][100];
long long ans[100][100]; // 처음에 int로 했다가 틀림;;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int rc;
	cin >> rc;
	for (int i = 0; i < rc; i++) {
		for (int j = 0; j < rc; j++) {
			cin >> map[i][j];
		}
	}
	ans[0][0] = 1;
	for (int i = 0; i < rc; i++) {
		for (int j = 0; j < rc; j++) {
			if (map[i][j] == 0) {
				continue;
			}
			if (j + map[i][j] < rc) { // 오른쪽으로 이동
				ans[i][j + map[i][j]] += ans[i][j];
			}
			if (i + map[i][j] < rc) { // 아래로 이동
				ans[i + map[i][j]][j] += ans[i][j];
			}
		}
	}
	cout << ans[rc - 1][rc - 1];
	return 0;
}