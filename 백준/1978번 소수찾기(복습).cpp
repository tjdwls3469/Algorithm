#include <iostream>
using namespace std;

bool prime(int num) {
	if (num < 2) {
		return false;
	}
	for (int i = 2; i*i <= num; i++) {
		if (num%i == 0) {
			return false;
		}
	}
	return true;
}

int main() {
	int cnt;
	int num;
	int result = 0;
	cin >> cnt;
	for (int i = 0; i < cnt; i++) {
		cin >> num;
		if (prime(num) == true) {
			result++;
		}
	}
	cout << result;

	return 0;
}