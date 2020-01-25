#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int ans[100001][3];
int up[100001];
int down[100001];

int main() {
	int tc;
	int cnt;
	cin >> tc;
	for (int i = 0; i < tc; i++) {
		cin >> cnt;
		vector<int> up(cnt + 1);
		vector<int> down(cnt + 1);
		for (int j = 1; j <= cnt; j++) {
			cin >> up[j];
		}
		for (int j = 1; j <= cnt; j++) {
			cin >> down[j];
		}
		for (int j = 1; j <= cnt; j++) {
			ans[j][0] = max(max(ans[j - 1][0], ans[j - 1][1]), ans[j - 1][2]);
			ans[j][1] = max(ans[j - 1][0], ans[j - 1][2]) + down[j];
			ans[j][2] = max(ans[j - 1][0], ans[j - 1][1]) + up[j];
		}
		cout << max(max(ans[cnt][0], ans[cnt][1]), ans[cnt][2]) << '\n';
	}
	return 0;
}