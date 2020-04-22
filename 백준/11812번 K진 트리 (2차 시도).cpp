#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long n;
	int k;
	int tc;
	cin >> n >> k >> tc;
	if (k == 1) {
		for (int i = 0; i < tc; i++) {
			long long start;
			long long goal;
			cin >> start >> goal;
			cout << abs(start - goal) << '\n';
		}
		return 0;
	}
	for (int i = 0; i < tc; i++) {
		long long start;
		long long goal;
		long long ans = 0;
		cin >> start >> goal;
		while (start != goal) {
			ans++;
			if (start > goal) {
				start = (start + k - 2) / k;
			}
			else {
				goal = (goal + k - 2) / k;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}