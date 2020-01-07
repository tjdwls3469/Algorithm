#include <iostream>
using namespace std;

int ans[11];

int main() {
	int cnt;
	int num;
	cin >> cnt;
	ans[1] = 1;
	ans[2] = 2;
	ans[3] = 4;
	for (int i = 4; i <= 10; i++) {
		ans[i] = ans[i - 1] + ans[i - 2] + ans[i - 3];
	}
	for (int i = 0; i < cnt; i++) {
		cin >> num;
		cout << ans[num] << '\n';
	}
	return 0;
}