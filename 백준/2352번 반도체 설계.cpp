#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int cnt;
	int ans = 0;
	cin >> cnt;
	vector<int> port(cnt);
	vector<int> d(cnt);
	for (int i = 0; i < cnt; i++) {
		cin >> port[i];
	}
	for (int i = 0; i < cnt; i++) {
		d[i] = 1;
		for (int j = 0; j < i; j++) {
			if (port[j] < port[i] && d[j] + 1 > d[i]) {
				d[i] = d[j] + 1;
			}
		}
		ans = max(ans, d[i]);
	}
	cout << ans;
	return 0;
}