#include <iostream>
using namespace std;

int result[100001];

int main() {
	int num;
	cin >> num;
	for (int i = 1; i <= num; i++) {
		result[i] = i;
		for (int j = 1; j*j <= i; j++) {
			if (result[i] > result[i - j * j] + 1) {
				result[i] = result[i - j * j] + 1;
			}
		}
	}
	cout << result[num];

	return 0;
}