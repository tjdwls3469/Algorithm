#include <iostream>
using namespace std;

int num[20];

int main() {
	int cnt;
	int goal;
	int ans = 0;
	cin >> cnt >> goal;
	for (int i = 0; i < cnt; i++) {
		cin >> num[i];
	}
	for (int i = 0; i < (1 << cnt); i++) {
		int sum = 0;
		for (int j = 0; j < cnt; j++) {
			if (i&(1 << j)) {
				sum += num[j];
			}
		}
		if (sum == goal) {
			ans++;
		}
	}
	if (goal == 0) {
		ans--;
	}
	cout << ans;
	return 0;
}