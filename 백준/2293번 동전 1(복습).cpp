/*
ans[N] = 금액 N을 만드는 모든 방법의 수
*/
#include <iostream>
#include <algorithm>
using namespace std;

int coin[101];
long long ans[10001];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int cnt;
	int goal;
	cin >> cnt >> goal;
	for (int i = 1; i <= cnt; i++) {
		cin >> coin[i];
	}
	sort(coin, coin + cnt + 1);
	ans[0] = 1;
	for (int j = 1; j <= cnt; j++) {
		for (int i = coin[j]; i <= goal; i++) {
			ans[i] += ans[i - coin[j]];
		}
	}
	cout << ans[goal];
	return 0;
}