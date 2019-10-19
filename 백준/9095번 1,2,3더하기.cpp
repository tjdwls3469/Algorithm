#include <iostream>
using namespace std;

int solve(int sum, int goal) {
	if (sum > goal) {
		return 0;
	}
	if (sum == goal) {
		return 1;
	}
	int result = 0;
	for (int i = 1; i <= 3; i++) {
		result += solve(sum + i, goal);
	}
	return result;
}

int main() {
	int cnt;
	int goal;
	cin >> cnt;
	for (int i = 0; i < cnt; i++) {
		cin >> goal;
		cout << solve(0, goal) << '\n';
	}

	return 0;
}