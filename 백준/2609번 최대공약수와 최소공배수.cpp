#include <iostream>

using namespace std;

int main() {
	int a;
	int b;
	cin >> a >> b;
	int mul = a * b;

	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	int lcm = mul / a;

	cout << a << '\n';
	cout << lcm;

	return 0;
}