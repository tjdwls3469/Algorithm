#include <iostream>
using namespace std;

int d[11];

int main() {
	int cnt;
	int num;
	cin >> cnt;
	d[0] = 1;
	d[1] = 1;
	d[2] = 2;
	for (int i = 0; i < cnt; i++) {
		cin >> num;
		for (int j = 3; j <= num; j++) {
			d[j] = d[j - 1] + d[j - 2] + d[j - 3];
		}
		cout << d[num] << '\n';
	}

	return 0;
}