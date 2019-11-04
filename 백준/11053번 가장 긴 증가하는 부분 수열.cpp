#include <iostream>
using namespace std;

int sequence[1001];
int result[1001];

int main() {
	int cnt;
	cin >> cnt;
	for (int i = 1; i <= cnt; i++) {
		cin >> sequence[i];
	}
	for (int i = 1; i <= cnt; i++) {
		result[i] = 1;
		for (int j = 1; j < cnt; j++) {
			if (sequence[i] > sequence[j] && result[i] < result[j] + 1) {
				result[i] = result[j] + 1;
			}
		}
	}
	int max = 0;
	for (int i = 1; i <= cnt; i++) {
		if (result[i] > max) {
			max = result[i];
		}
	}
	cout << max;

	return 0;
}