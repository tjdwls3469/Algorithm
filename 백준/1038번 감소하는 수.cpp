#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> ans;

void solve(long long num, int cnt) {
	if (cnt > 10) {
		return;
	}
	ans.push_back(num);
	for (int i = 0; i <= 9; i++) {
		if (i < num % 10) {
			solve(num * 10 + i, cnt + 1);
		}
	}
	return;
}

int main() {
	int num;
	cin >> num;
	for (int i = 0; i <= 9; i++) {
		solve(i, 1);
	}
	sort(ans.begin(), ans.end());
	if (num >= ans.size()) {
		cout << -1;
	}
	else {
		cout << ans[num];
	}
	return 0;
}