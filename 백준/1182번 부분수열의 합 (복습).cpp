#include <iostream>
#include <vector>
using namespace std;

int ans;
int cnt;
int goal;
int num[20];

void solve(int index, int sum) {
	if (sum == goal && index == cnt) {
		ans++;
		return;
	}
	if (index >= cnt) {
		return;
	}
	solve(index + 1, sum + num[index]);
	solve(index + 1, sum);
}

int main() {
	cin >> cnt >> goal;
	for (int i = 0; i < cnt; i++) {
		cin >> num[i];
	}
	solve(0, 0);
	if (goal == 0) {
		ans--;
	}
	cout << ans;
	return 0;
}