#include <iostream>
using namespace std;

int num[100000];
int result[100000];

int main() {
	int cnt;
	cin >> cnt;
	for (int i = 0; i < cnt; i++) {
		cin >> num[i];
	}
	result[0] = num[0];
	for (int i = 1; i < cnt; i++) {
		result[i] = num[i];
		if (result[i] < result[i - 1] + num[i]) {
			result[i] = result[i - 1] + num[i];
		}
	}
	int max = result[0];
	for (int i = 1; i < cnt; i++) {
		if (result[i] > max) {
			max = result[i];
		}
	}
	cout << max;

	return 0;
}