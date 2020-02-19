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
	for (int i = 0; i < cnt; i++) {
		cin >> num;
		for (int j = 4; j <= num; j++) {
			ans[j] = ans[j - 1] + ans[j - 2] + ans[j - 3];
		}
		cout << ans[num] << '\n';
	}
	return 0;
}