#include <iostream>
using namespace std;

int ans[1000001];

int main() {
	int num;
	cin >> num;
	ans[1] = 0;
	for (int i = 2; i <= num; i++) {
		ans[i] = ans[i - 1] + 1;
		if (i % 2 == 0 && ans[i / 2] + 1 < ans[i]) {
			ans[i] = ans[i / 2] + 1;
		}
		if (i % 3 == 0 && ans[i / 3] + 1 < ans[i]) {
			ans[i] = ans[i / 3] + 1;
		}
	}
	cout << ans[num];
	return 0;
}