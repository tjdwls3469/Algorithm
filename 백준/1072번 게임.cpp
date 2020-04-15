#include <iostream>
using namespace std;

int main() {
	long long gameCnt;
	long long win;
	cin >> gameCnt >> win;
	long long before = win * 100 / gameCnt;
	if (before >= 99) {
		cout << -1;
		return 0;
	}
	long long after;
	int begin = 0;
	int end = 1000000000;
	int mid;
	int ans;
	while (begin <= end) {
		mid = (begin + end) / 2;
		after = (win + mid) * 100 / (gameCnt + mid);
		if (after > before) {
			end = mid - 1;
			ans = mid;
		}
		else {
			begin = mid + 1;
		}
	}
	cout << ans;
	return 0;
}