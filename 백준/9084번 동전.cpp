/*
ans[N] = 금액 N을 만드는 모든 방법의 수
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int tc;
	cin >> tc;
	for (int i = 0; i < tc; i++) {
		int cnt;
		cin >> cnt;
		vector<int> coin(cnt + 1);
		for (int j = 1; j <= cnt; j++) {
			cin >> coin[j];
		}
		int goal;
		cin >> goal;
		vector<int> ans(goal + 1);
		ans[0] = 1;
		for (int k = 1; k <= cnt; k++) {
			for (int j = coin[k]; j <= goal; j++) {
				ans[j] += ans[j - coin[k]];
			}
		}
		/*for (int i = 0; i <= goal; i++) {
			cout << ans[i] << ' ';
		}
		cout << '\n';*/
		cout << ans[goal] << '\n';
	}
	return 0;
}