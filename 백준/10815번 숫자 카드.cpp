#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve(int left, int right, int target, vector<int> &sang) {
	int mid = (left + right) / 2;
	if (sang[mid] == target) {
		cout << 1 << ' ';
		return;
	}
	if (left > right) {
		cout << 0 << ' ';
		return;
	}
	if (sang[mid] > target) {
		solve(left, mid - 1, target, sang);
	}
	else {
		solve(mid + 1, right, target, sang);
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	vector<int> sang(n);
	for (int i = 0; i < n; i++) {
		cin >> sang[i];
	}
	sort(sang.begin(), sang.end());
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int target;
		cin >> target;
		solve(0, n - 1, target, sang);
	}
	return 0;
}