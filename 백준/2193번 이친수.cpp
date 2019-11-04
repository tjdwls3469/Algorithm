#include <iostream>
using namespace std;

long long result[91];

int main() {
	int num;
	cin >> num;
	result[1] = 1;
	result[2] = 1;
	for (int i = 3; i <= num; i++) {
		result[i] = result[i - 2] + result[i - 1];
	}
	cout << result[num];

	return 0;
}