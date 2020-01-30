#include <iostream>
using namespace std;

int cnt;
int ans;
int task[15];
int price[15];

void solve(int index, int sum) {
	if (index == cnt) {
		if (sum > ans) {
			ans = sum;
		}
		return;
	}
	if (index > cnt) {
		return;
	}
	solve(index + task[index], sum + price[index]);
	solve(index + 1, sum);
}

int main() {
	cin >> cnt;
	for (int i = 0; i < cnt; i++) {
		cin >> task[i] >> price[i];
	}
	solve(0, 0);
	cout << ans;
	return 0;
}