#include <iostream>
#include <vector>
using namespace std;

int main() {
	int cnt;
	cin >> cnt;
	vector<int> candidate(cnt);
	for (int i = 0; i < cnt; i++) {
		cin >> candidate[i];
	}
	int firstMan;
	int secondMan;
	cin >> firstMan >> secondMan;
	long long ans = 0;
	for (int i = 0; i < cnt; i++) {
		int num = candidate[i];
		num -= firstMan;
		ans++;
		if (num <= 0) {
			continue;
		}
		ans += num / secondMan;
		if (num % secondMan != 0) {
			ans++;
		}
	}
	cout << ans;
	return 0;
}