#include <iostream>
#include <algorithm>
using namespace std;

int n, k;
int ans;

void solve(int left, int right) {
	int mid = (left + right) / 2; // mid�� �ε����� �ƴ� ��
	int cnt = 0;
	if (left > right) {
		return;
	}
	for (int i = 1; i <= n; i++) { // cnt�� N*N����� ������ mid���� �۰ų� ���� ����
		cnt += min(mid / i, n);
	}
	if (cnt < k) {
		solve(mid + 1, right);
	}
	else {
		ans = mid;
		solve(left, mid - 1);
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k;
	solve(1, k);
	cout << ans;
	return 0;
}