#include <iostream>
#include <vector>
using namespace std;

int main() {
	int cnt;
	int goal;
	cin >> cnt >> goal;
	vector<int> num(cnt);
	for (int i = 0; i < cnt; i++) {
		cin >> num[i];
	}
	vector<int> ans(goal + 1);
	for (int i = 0; i <= goal; i++) {
		ans[i] = -1;
	}
	ans[0] = 0;
	for (int i = 0; i < cnt; i++) {
		for (int j = 1; j <= goal; j++) {
			if (j - num[i] >= 0 && ans[j-num[i]] != -1) {
				if (ans[j] == -1 || ans[j - num[i]] + 1 < ans[j]) {
					ans[j] = ans[j - num[i]] + 1;
				}
			}
		}
	}
	if (ans[goal] == 0) {
		cout << -1;
	}
	else {
		cout << ans[goal];
	}
	return 0;
}