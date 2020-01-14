#include <iostream>
using namespace std;

int cnt;
int ans[8];
bool check[9];

void solve(int index, int max) {
	if (index == cnt) {
		for (int i = 0; i < cnt; i++) {
			cout << ans[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = 1; i <= max; i++) {
		if (check[i] == true) {
			continue;
		}
		check[i] = true;
		ans[index] = i;
		solve(index + 1, max);
		check[i] = false;
	}
}

int main() {
	int max;
	cin >> max >> cnt;
	solve(0, max);
	return 0;
}