#include <iostream>
using namespace std;

int result[1001];

int main() {
	int n;
	cin >> n;
	result[1] = 1;
	result[2] = 2;
	for (int i = 3; i <= n; i++) {
		result[i] = result[i - 2] + result[i - 1];
		result[i] = result[i] % 10007;
	}
	cout << result[n];

	return 0;
}