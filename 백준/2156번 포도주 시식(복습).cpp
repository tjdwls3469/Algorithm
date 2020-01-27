#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int ans[10001][3];

int main() {
	int cnt;
	cin >> cnt;
	vector<int> wine(cnt + 1);
	for (int i = 1; i <= cnt; i++) {
		cin >> wine[i];
	}
	ans[1][1] = wine[1];
	ans[2][0] = ans[1][1];
	ans[2][1] = wine[2];
	ans[2][2] = wine[1] + wine[2];
	for (int i = 3; i <= cnt; i++) {
		ans[i][0] = max(max(ans[i - 1][0], ans[i - 1][1]), ans[i - 1][2]);
		ans[i][1] = ans[i - 1][0] + wine[i];
		ans[i][2] = ans[i - 1][1] + wine[i];
	}
	cout << max(max(ans[cnt][0], ans[cnt][1]), ans[cnt][2]);
	return 0;
}