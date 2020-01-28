#include <iostream>
#include <vector>
using namespace std;

int ans;
int cnt;
int goal;
int num[20];
int part[20];

void solve(int index, int selectCnt, int max) {
	if (selectCnt == max) {
		int sum = 0;
		for (int i = 0; i < max; i++) {
			sum += part[i];
		}
		if (sum == goal) {
			ans++;
		}
		return;
	}
	if (index == cnt) {
		return;
	}
	part[selectCnt] = num[index];
	solve(index + 1, selectCnt + 1, max);
	part[selectCnt] = 0;
	solve(index + 1, selectCnt, max);
}

int main() {
	cin >> cnt >> goal;
	for (int i = 0; i < cnt; i++) {
		cin >> num[i];
	}
	for (int i = 1; i <= cnt; i++) {
		solve(0, 0, i);
	}
	cout << ans;
	return 0;
}