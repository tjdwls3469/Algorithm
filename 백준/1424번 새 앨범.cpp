#include <iostream>
using namespace std;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int cnt;
	int len;
	int cd;
	cin >> cnt >> len >> cd;
	len++;
	cd++;
	int record = cd / len;
	if (record % 13 == 0) {
		record--;
	}
	int ans = cnt / record;
	if ((cd%record) % 13 == 0) {
		ans += 2;
	}
	else if (cd%record != 0) {
		ans++;
	}
	cout << ans;
	return 0;
}