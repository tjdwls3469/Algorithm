#include <iostream>
#include <vector>
using namespace std;

int main() {
	int cnt;
	int goal;
	int ans = 0;
	cin >> cnt >> goal;
	vector<int> num(cnt);
	for (int i = 0; i < cnt; i++) {
		cin >> num[i];
	}
	for (int i = 0; i < cnt; i++) {
		int sum = 0;
		for (int j = i; j < cnt; j++) {
			sum += num[j];
			if (sum >= goal) {
				int temp = j - i + 1;
				if (ans == 0 || temp < ans) {
					ans = temp;
				}
				break;
			}
		}
	}
	cout << ans;
	return 0;
}