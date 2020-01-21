#include <iostream>
using namespace std;

int ans;

void solve(int sum, int goal) {
	if (sum == goal) {
		ans++;
		return;
	}
	if (sum > goal) {
		return;
	}
	for (int i = 1; i <= 3; i++) {
		solve(sum + i, goal);
	}
}

int main() {
	int cnt;
	int goal;
	cin >> cnt;
	for (int i = 0; i < cnt; i++) {
		cin >> goal;
		ans = 0;
		solve(0, goal);
		cout << ans << '\n';
	}
	return 0;
}