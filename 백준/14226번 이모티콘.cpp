#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int ans[1001][1001];

int main() {
	int cnt;
	cin >> cnt;
	queue<pair<int, int>> q;
	memset(ans, -1, sizeof(ans));
	ans[1][0] = 0;
	q.push(make_pair(1, 0));
	while (!q.empty()) {
		int s = q.front().first;
		int c = q.front().second;
		q.pop();
		if (ans[s][s] == -1) {
			ans[s][s] = ans[s][c] + 1;
			q.push(make_pair(s, s));
		}
		if (s + c <= cnt && ans[s + c][c] == -1) {
			ans[s + c][c] = ans[s][c] + 1;
			q.push(make_pair(s + c, c));
		}
		if (s - 1 >= 0 && ans[s - 1][c] == -1) {
			ans[s - 1][c] = ans[s][c] + 1;
			q.push(make_pair(s - 1, c));
		}
	}
	int result = -1;
	for (int i = 1; i <= cnt; i++) {
		if (ans[cnt][i] != -1) {
			if (result == -1 || ans[cnt][i] < result) {
				result = ans[cnt][i];
			}
		}
	}
	cout << result;
	return 0;
}