#include <iostream>
using namespace std;

bool breakdown[10];

int cal(int num) {
	if (num == 0) {
		if (breakdown[num] == true) {
			return 0;
		}
		else {
			return 1;
		}
	}
	int len = 0;
	while (true) {
		if (num == 0) {
			break;
		}
		if (breakdown[num % 10] == true) {
			return 0;
		}
		num = num / 10;
		len++;
	}
	return len;
}

int main() {
	int channel;
	int cnt;
	int result;
	cin >> channel;
	result = channel - 100;
	if (result < 0) {
		result = -result;
	}
	cin >> cnt;
	for (int i = 0; i < cnt; i++) {
		int num;
		cin >> num;
		breakdown[num] = true;
	}
	for (int i = 0; i <= 1000000; i++) {
		int len = cal(i);
		if (len != 0) {
			int press = channel - i;
			if (press < 0) {
				press = -press;
			}
			if (len + press < result) {
				result = len + press;
			}
		}
	}
	cout << result;

	return 0;
}