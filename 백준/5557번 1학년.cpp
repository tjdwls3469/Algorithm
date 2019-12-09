#include <iostream>
#include <vector>

using namespace std;
long long ans[100][21];

int main() {
	int cnt;
	cin >> cnt;
	cnt -= 1;
	vector<int> num(cnt);
	for (int i = 0; i < cnt; i++) {
		cin >> num[i];
	}
	int goal;
	cin >> goal;
	ans[0][num[0]] = 1;
	for (int i = 1; i < cnt; i++) {
		for (int j = 0; j <= 20; j++) {
			if (j - num[i] >= 0) {
				ans[i][j] += ans[i - 1][j - num[i]];
			}
			if (j + num[i] <= 20) {
				ans[i][j] += ans[i - 1][j + num[i]];
			}
		}
	}
	cout << ans[cnt - 1][goal];

	return 0;
}