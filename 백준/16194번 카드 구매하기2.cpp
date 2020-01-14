#include <iostream>
#include <vector>
using namespace std;

int main() {
	int cnt;
	cin >> cnt;
	vector<int> price(cnt + 1);
	vector<int> ans(cnt + 1);
	for (int i = 1; i <= cnt; i++) {
		cin >> price[i];
	}
	for (int i = 1; i <= cnt; i++) {
		ans[i] = price[i];
		for (int j = 1; j < i; j++) {
			if (ans[i - j] + price[j] < ans[i]) {
				ans[i] = ans[i - j] + price[j];
			}
		}
	}
	cout << ans[cnt];
	return 0;
}