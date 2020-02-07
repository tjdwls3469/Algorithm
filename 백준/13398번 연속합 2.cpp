#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
	int cnt;
	cin >> cnt;
	vector<int> num(cnt);
	vector<int> left(cnt);
	vector<int> right(cnt);
	for (int i = 0; i < cnt; i++) {
		cin >> num[i];
	}
	left[0] = num[0];
	for (int i = 1; i < cnt; i++) {
		left[i] = max(left[i - 1] + num[i], num[i]);
	}
	right[cnt - 1] = num[cnt - 1];
	for (int i = cnt - 2; i >= 0; i--) {
		right[i] = max(right[i + 1] + num[i], num[i]);
	}
	int ans = left[0];
	for (int i = 1; i < cnt; i++) {
		ans = max(ans, left[i]);
	}
	for (int i = 1; i < cnt - 1; i++) {
		int temp = left[i - 1] + right[i + 1];
		ans = max(ans, temp);
	}
	cout << ans;
	return 0;
}