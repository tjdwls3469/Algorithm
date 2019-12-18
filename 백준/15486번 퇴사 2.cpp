#include <iostream>
#include <algorithm>
using namespace std;

int ans[1500050];
int time[1500000];
int price[1500000];

int main() {
	int cnt;
	cin >> cnt;
	for (int i = 0; i < cnt; i++) {
		cin >> time[i] >> price[i];
	}
	for (int i = 0; i < cnt; i++) {
		ans[i + time[i]] = max(ans[i] + price[i], ans[i + time[i]]);
		ans[i + 1] = max(ans[i], ans[i + 1]);
	}
	cout << ans[cnt];
	return 0;
}