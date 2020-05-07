/*
ans[N] = 금액 N을 만드는 동전의 최소 개수
*/
#include <iostream>
#include <algorithm>
using namespace std;

int coin[101];
int ans[10001];

int main() {
	int cnt;
	int goal;
	cin >> cnt >> goal;
	for (int i = 1; i <= cnt; i++) {
		cin >> coin[i];
	}
	sort(coin, coin + cnt + 1);
	ans[0] = 1;
	for (int i = 1; i <= goal; i++) {
		for (int j = 1; j <= cnt; j++) {
			if (i - coin[j] < 0) {
				break;
			}
			if (ans[i - coin[j]] != 0) {
				if (ans[i] == 0 || ans[i - coin[j]] + 1 < ans[i]) {
					ans[i] = ans[i - coin[j]] + 1;
				}
			}
		}
	}
	(ans[goal] == 0) ? cout << -1 : cout << ans[goal] - 1;

	/*cout << '\n';
	for (int i = 0; i <= goal; i++) {
		cout << ans[i] << ' ';
	}*/

	return 0;
}