#include <iostream>
using namespace std;

int result[1001];

int main() {
	int n;
	cin >> n;
	result[1] = 1;
	result[2] = 3;
	result[3] = 5;
	for(int i = 4; i <= n; i++) {
		result[i] = result[i - 1] + (2 * result[i - 2]);
		result[i] = result[i] % 10007;
	}
	cout << result[n];

	return 0;
}