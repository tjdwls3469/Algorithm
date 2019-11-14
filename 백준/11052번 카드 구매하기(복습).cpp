#include <iostream>
using namespace std;

int result[1001];
int price[1001];

int main() {
	int cnt;
	cin >> cnt;
	for (int i = 1; i <= cnt; i++) {
		cin >> price[i];
	}
	for (int i = 1; i <= cnt; i++) {
		for (int j = 1; j <= i; j++) {
			if (price[j] + result[i - j] > result[i]) {
				result[i] = price[j] + result[i - j];
			}
		}
	}
	cout << result[cnt];

	return 0;
}