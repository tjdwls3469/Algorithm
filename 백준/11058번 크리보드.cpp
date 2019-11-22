#include <iostream>
using namespace std;

long long result[101];

int main() {
	int num;
	cin >> num;
	for (int i = 1; i <= num; i++) {
		result[i] = result[i - 1] + 1;
		for (int j = 1; j <= i - 3; j++) {
			if (result[i - (j + 2)] * (j + 1) > result[i]) {
				result[i] = result[i - (j + 2)] * (j + 1);
			}
		}
	}
	cout << result[num];

	return 0;
}