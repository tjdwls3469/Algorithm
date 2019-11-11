#include <iostream>
using namespace std;

int result[1000001];

int solve(int num) {
	if (num == 1) {
		return 0;
	}
	for (int i = 2; i <= num; i++) {
		result[i] = result[i - 1] + 1;
		if (i % 2 == 0 && result[i / 2] + 1 < result[i]) {
			result[i] = result[i / 2] + 1;
		}
		if (i % 3 == 0 && result[i / 3] + 1 < result[i]) {
			result[i] = result[i / 3] + 1;
		}
	}
	return result[num];
}

int main() {
	int num;
	cin >> num;
	cout << solve(num);

	return 0;
}