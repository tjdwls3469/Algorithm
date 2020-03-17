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
		int temp = 0;
		for (int j = i; j < cnt; j++) {
			temp += num[j];
			if (temp == goal) {
				ans++;
				break;
			}
			if (temp > goal) {
				break;
			}
		}
	}
	cout << ans;
	return 0;
}