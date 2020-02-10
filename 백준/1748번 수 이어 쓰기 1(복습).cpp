#include <iostream>
using namespace std;

int main() {
	int num;
	cin >> num;
	int len = 1;
	int ten = 1;
	int division = 1;
	int result = 0;
	while (true) {
		if (num / division < 10) {
			break;
		}
		division = division * 10;
		len++;
	}
	for (int i = 0; i < len - 1; i++) {
		result += 9 * ten*(i + 1);
		ten *= 10;
	}
	result += (num - ten + 1)*len;
	cout << result;

	return 0;
}