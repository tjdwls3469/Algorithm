#include <iostream>
#include <vector>
using namespace std;

int main() {
	int cnt;
	cin >> cnt;
	vector<long long> ans(cnt + 1);
	for (int i = 1; i <= cnt; i++) {
		ans[i] = ans[i - 1] + 1;
		for (int j = 3; j < i; j++) {
			if (ans[i - j] * (j - 1) > ans[i]) {
				ans[i] = ans[i - j] * (j - 1);
			}
		}
	}
	cout << ans[cnt];
	return 0;
}