#include <iostream>
#include <algorithm>
using namespace std;

int a[100000];
int cntA;
int cntNum;

void solve(int left, int right, int target) {
	int mid = (left + right) / 2;
	if (a[mid] == target) {
		cout << '1' << '\n';
		return;
	}
	if (left > right) {
		cout << '0' << '\n';
		return;
	}
	if (a[mid] > target) {
		solve(left, mid - 1, target);
	}
	else {
		solve(mid + 1, right, target);
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> cntA;
	for (int i = 0; i < cntA; i++) {
		cin >> a[i];
	}
	sort(a, a + cntA);
	cin >> cntNum;
	for (int i = 0; i < cntNum; i++) {
		int num;
		cin >> num;
		solve(0, cntA - 1, num);
	}
	return 0;
}