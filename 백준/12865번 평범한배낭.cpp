#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int ans[101][100001];

int main() {
	int cnt;
	int criteria;
	cin >> cnt >> criteria;
	vector<int> weight(cnt + 1);
	vector<int> value(cnt + 1);
	for (int i = 1; i <= cnt; i++) {
		cin >> weight[i] >> value[i];
	}
	for (int i = 1; i <= cnt; i++) {
		for (int j = 1; j <= criteria; j++) {
			ans[i][j] = ans[i - 1][j];
			if (j - weight[i] >= 0) {
				ans[i][j] = max(ans[i][j], ans[i - 1][j - weight[i]] + value[i]);
			}
		}
	}
	cout << ans[cnt][criteria];

	return 0;
}