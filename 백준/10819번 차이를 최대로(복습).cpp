#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int cnt;
	int ans = 0;
	cin >> cnt;
	vector<int> num(cnt);
	for (int i = 0; i < cnt; i++) {
		cin >> num[i];
	}
	sort(num.begin(), num.end());
	do {
		int sum = 0;
		for (int i = 0; i <= cnt - 2; i++) {
			int diff = num[i] - num[i + 1];
			if (diff < 0) {
				diff = -diff;
			}
			sum += diff;
		}
		if (sum > ans) {
			ans = sum;
		}
	} while (next_permutation(num.begin(), num.end()) == true);
	cout << ans;
	return 0;
}