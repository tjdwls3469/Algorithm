#include <iostream>
using namespace std;

bool prime(int x) {
	for (int i = 2; i*i <= x; i++) {
		if (x%i == 0) {
			return false;
		}
	}
	return true;
}

int main() {
	int goal;
	cin >> goal;
	if (goal == 1) {
		cout << 0;
		return 0;
	}
	int cnt = 0;
	for (int i = 2; i <= goal; i++) {
		int sum = 0;
		for (int j = i; j <= goal; j++) {
			if (prime(j) == true) {
				sum += j;
			}
			if (sum == goal) {
				cnt++;
				break;
			}
			else if (sum > goal) {
				break;
			}
			else {
				;
			}
		}
	}
	cout << cnt;
	return 0;
}