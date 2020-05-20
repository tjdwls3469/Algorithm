#include <iostream>
#include <algorithm>
using namespace std;

int n, k;
int ans;

void solve(int left, int right) {
	int mid = (left + right) / 2; // mid는 인덱스가 아닌 값
	int cnt = 0;
	if (left > right) {
		return;
	}
	for (int i = 1; i <= n; i++) { // cnt는 N*N행렬의 값에서 mid보다 작거나 같은 갯수
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