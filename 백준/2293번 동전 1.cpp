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
	ans[0] = 1;
	for (int i = 0; i < cnt; i++) {
		for (int j = 1; j <= goal; j++) {
			if (j - num[i] >= 0) {
				ans[j] += ans[j - num[i]];
			}
		}
	}
	cout << ans[goal];
	return 0;
}