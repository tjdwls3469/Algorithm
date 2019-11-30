#include <iostream>
using namespace std;

int ans[10001];

int main() {
	int limit = 10000;
	int cnt;
	ans[0] = 1;
	for (int i = 1; i <= limit; i++) {
		ans[i] += ans[i - 1];
	}
	for (int i = 2; i <= limit; i++) {
		ans[i] += ans[i - 2];
	}
	for (int i = 3; i <= limit; i++) {
		ans[i] += ans[i - 3];
	}
	cin >> cnt;
	for (int i = 0; i < cnt; i++) {
		int num;
		cin >> num;
		cout << ans[num] << '\n';
	}

	return 0;
}