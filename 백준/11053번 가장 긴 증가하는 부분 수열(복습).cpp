#include <iostream>
#include <vector>
using namespace std;

int main() {
	int cnt;
	cin >> cnt;
	vector<int> num(cnt);
	vector<int> part(cnt);
	for (int i = 0; i < cnt; i++) {
		cin >> num[i];
	}
	for (int i = 0; i < cnt; i++) {
		part[i] = 1;
		for (int j = 0; j < i; j++) {
			if (num[i] > num[j] && part[i] < part[j] + 1) {
				part[i] = part[j] + 1;
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < cnt; i++) {
		if (part[i] > ans) {
			ans = part[i];
		}
	}
	cout << ans;
	return 0;
}