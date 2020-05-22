#include <iostream>
#include <algorithm>
using namespace std;

int cnt;
int goal;
long long ans = -1;
long long len[10000];

void solve(long long left, long long right) {
	long long mid = (left + right) / 2;
	int sum = 0;
	bool check = true;
	if (left > right) {
		return;
	}
	for (int i = cnt - 1; i >= 0; i--) {
		if (len[i] < mid) {
			check = false;
			break;
		}
		sum += (len[i] / mid);
	}
	if (sum < goal || check == false) {
		solve(left, mid - 1);
	}
	else {
		if (ans == -1 || mid > ans) {
			ans = mid;
		}
		solve(mid + 1, right);
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> cnt >> goal;
	for (int i = 0; i < cnt; i++) {
		cin >> len[i];
	}
	sort(len, len + cnt);
	solve(1, len[cnt - 1]);
	cout << ans;
	return 0;
}