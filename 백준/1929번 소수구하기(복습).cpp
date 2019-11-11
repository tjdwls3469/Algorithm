#include <iostream>
using namespace std;

bool prime(int num) {
	if(num == 1) {
		return false;
	}
	for (int i = 2; i*i <= num; i++) {
		if (num % i == 0) {
			return false;
		}
	}
	return true;
}

int main() {
	int min;
	int max;
	cin >> min >> max;
	for (int i = min; i <= max; i++) {
		if (prime(i) == true) {
			cout << i << '\n';
		}
	}

	return 0;
}