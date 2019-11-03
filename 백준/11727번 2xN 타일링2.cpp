#include <iostream>
using namespace std;

int d[1001];

int main() {
	int num;
	cin >> num;
	d[0] = 1;
	d[1] = 1;
	for (int i = 2; i <= num; i++) {
		d[i] = d[i - 1] + d[i - 2] * 2;
		d[i] = d[i] % 10007;
	}
	cout << d[num];

	return 0;
}