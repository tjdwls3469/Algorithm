#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int cnt;
int leftCard[2000];
int rightCard[2000];
int ans[2000][2000];

int solve(int l, int r) {
	if (l >= cnt || r >= cnt) {
		return 0;
	}
	int &result = ans[l][r];
	if (result != -1) {
		return result;
	}
	result = 0;
	if (leftCard[l] > rightCard[r]) {
		result += rightCard[r] + solve(l, r + 1);
	}
	else {
		result += max(solve(l + 1, r), solve(l + 1, r + 1));
	}
	return result;
}

int main() {
	cin >> cnt;
	for (int i = 0; i < cnt; i++) {
		cin >> leftCard[i];
	}
	for (int i = 0; i < cnt; i++) {
		cin >> rightCard[i];
	}
	memset(ans, -1, sizeof(ans));
	cout << solve(0, 0);
	return 0;
}