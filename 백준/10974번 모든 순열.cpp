#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int cnt;
	cin >> cnt;
	vector<int> number(cnt);
	for (int i = 0; i < cnt; i++) {
		number[i] = i + 1;
		cout << number[i] << ' ';
	}
	cout << '\n';
	while (next_permutation(number.begin(), number.end())) {
		for (int i = 0; i < cnt; i++) {
			cout << number[i] << ' ';
		}
		cout << '\n';
	}

	return 0;
}