#include <iostream>
using namespace std;

int wine[1001];
int result[1001];

int main() {
	int cnt;
	cin >> cnt;
	for (int i = 1; i <= cnt; i++) {
		cin >> wine[i];
	}
	result[1] = wine[1];
	result[2] = wine[1] + wine[2];
	for (int i = 3; i <= cnt; i++) {
		result[i] = result[i - 1];
		if (result[i - 2] + wine[i] > result[i]) {
			result[i] = result[i - 2] + wine[i];
		}
		if (result[i - 3] + wine[i - 1] + wine[i] > result[i]) {
			result[i] = result[i - 3] + wine[i - 1] + wine[i];
		}
	}
	cout << result[cnt];

	return 0;
}