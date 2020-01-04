#include <iostream>
using namespace std;

int gcd(int num1, int num2) {
	if (num2 == 0) {
		return num1;
	}
	else {
		return gcd(num2, num1%num2);
	}
}

int main() {
	int cnt;
	cin >> cnt;
	for (int i = 0; i < cnt; i++) {
		int num1;
		int num2;
		cin >> num1 >> num2;
		int g = gcd(num1, num2);
		cout << num1 * num2 / g << '\n';
	}
	return 0;
}