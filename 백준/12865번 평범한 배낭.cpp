#include <iostream>
#include <vector>
using namespace std;

int main() {
	int cnt;
	int maxWeight;
	cin >> cnt >> maxWeight;
	vector<int> weight(cnt);
	vector<int> value(cnt);
	for (int i = 0; i < cnt; i++) {
		cin >> weight[i] >> value[i];
	}
	vector<int> ans(maxWeight + 1);
	for (int i = 1; i <= maxWeight; i++) {
		for (int j = 0; j < cnt; j++) {
			if (i - weight[j] < 0) {
				continue;
			}
			if (ans[i - weight[j]] + value[j] > ans[i]) {
				ans[i] = ans[i - weight[j]] + value[j];
			}
		}
	}
	cout << ans[maxWeight];
	return 0;
}