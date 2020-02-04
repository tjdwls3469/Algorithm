#include <iostream>
#include <vector>
using namespace std;

int main() {
	int cnt;
	int goal;
	int ans = 0;
	cin >> cnt >> goal;
	vector<int> num(cnt);
	for (int i = 0; i < cnt; i++) {
		cin >> num[i];
	}
	for (int i = 1; i < (1 << cnt); i++) {
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
	cout << ans;
	return 0;
}