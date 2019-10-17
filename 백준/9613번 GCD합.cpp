#include <iostream>
using namespace std;

int ary[100];
int gcd(int a, int b) {
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main() {
	int tc;
	int num;
	long long sum;
	cin >> tc;
	for (int i = 0; i < tc; i++) {
		sum = 0;
		cin >> num;
		for (int j = 0; j < num; j++) {
			cin >> ary[j];
		}
		for (int j = 0; j < num-1; j++) {
			for (int k = j + 1; k < num; k++) {
				sum += gcd(ary[j], ary[k]);
			}
		}
		cout << sum << '\n';
	}

	return 0;
}