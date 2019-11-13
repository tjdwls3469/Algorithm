#include <iostream>
using namespace std;

int result[11];

int main() {
	int cnt;
	int num;
	result[1] = 1;
	result[2] = 2;
	result[3] = 4;
	cin >> cnt;
	for (int i = 4; i <= 11; i++) {
		result[i] = result[i - 3] + result[i - 2] + result[i - 1];
	}
	for (int i = 0; i < cnt; i++) {
		cin >> num;
		cout << result[num] << '\n';
	}

	return 0;
}