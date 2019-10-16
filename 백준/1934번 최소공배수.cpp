#include <iostream>

using namespace std;

int gcd(int a, int b) {
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int lcm[1000];

int main() {
	int num;
	int a;
	int b;
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> a >> b;
		lcm[i] = a * b / gcd(a, b);
	}

	for (int i = 0; i < num; i++) {
		cout << lcm[i] << '\n';
	}

	return 0;
}