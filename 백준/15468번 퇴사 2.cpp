#include <iostream>
#include <algorithm>
using namespace std;

long long ans[1500051];
int time[1500001];
int price[1500001];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int cnt;
	cin >> cnt;
	for (int i = 1; i <= cnt; i++) {
		cin >> time[i] >> price[i];
	}
	for (int i = 1; i <= cnt; i++) {
		ans[i + time[i]] = max(ans[i + time[i]], ans[i] + price[i]);
		ans[i + 1] = max(ans[i + 1], ans[i]);
	}
	cout << ans[cnt + 1];
	return 0;
}