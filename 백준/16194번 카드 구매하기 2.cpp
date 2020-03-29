#include <iostream>
using namespace std;

int num[1001];
int ans[1001];

int main() {
	int cnt;
	cin >> cnt;
	for (int i = 1; i <= cnt; i++) {
		cin >> num[i];
	}
	for (int i = 1; i <= cnt; i++) {
		ans[i] = -1;
	}
	for (int i = 1; i <= cnt; i++) {
		for (int j = 1; j <= i; j++) {
			if (num[j] + ans[i - j] < ans[i] || ans[i] == -1) {
				ans[i] = num[j] + ans[i - j];
			}
		}
	}
	cout << ans[cnt];
	return 0;
}