#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
	int cnt;
	int result = INT_MIN;
	cin >> cnt;
	vector<int> num(cnt + 1);
	vector<int> ans(cnt + 1);
	for (int i = 1; i <= cnt; i++) {
		cin >> num[i];
	}
	ans[1] = num[1];
	for (int i = 2; i <= cnt; i++) {
		ans[i] = max(ans[i - 1] + num[i], num[i]);
	}
	for (int i = 1; i <= cnt; i++) {
		if (ans[i] > result) {
			result = ans[i];
		}
	}
	cout << result;
	return 0;
}