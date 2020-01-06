#include <iostream>
using namespace std;

int num[100];

int gcd(int x, int y) {
	if (y == 0) {
		return x;
	}
	else {
		return gcd(y, x%y);
	}
}

int main() {
	int tc;
	int cnt;
	long long ans;
	cin >> tc;
	for (int i = 0; i < tc; i++) {
		ans = 0;
		cin >> cnt;
		for (int j = 0; j < cnt; j++) {
			cin >> num[j];
		}
		for (int j = 0; j < cnt - 1; j++) {
			for (int k = j + 1; k < cnt; k++) {
				ans += gcd(num[j], num[k]);
			}
		}
		cout << ans << '\n';
	}
	return 0;
}