#include <iostream>
using namespace std;

int cnt;
int ans[8];

void solve(int index, int start, int max) {
	if (index == cnt) {
		for (int i = 0; i < cnt; i++) {
			cout << ans[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = start; i <= max; i++) {
		ans[index] = i;
		solve(index + 1, i, max);
	}
}

int main() {
	int max;
	cin >> max >> cnt;
	solve(0, 1, max);
	return 0;
}