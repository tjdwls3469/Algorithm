#include <iostream>
using namespace std;

int p[10001];
int d[1001];

int main() {
	int cnt;
	cin >> cnt;
	for (int i = 1; i <= cnt; i++) {
		cin >> p[i];
	}
	d[0] = 0;
	for (int i = 1; i <= cnt; i++) {
		for (int j = 1; j <= i; j++) {
			int temp = d[i - j] + p[j];
			if (temp > d[i]) {
				d[i] = temp;
			}
		}
	}
	cout << d[cnt];

	return 0;
}