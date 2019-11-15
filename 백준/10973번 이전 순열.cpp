#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int cnt;
	cin >> cnt;
	vector<int> number(cnt);
	for (int i = 0; i < cnt; i++) {
		cin >> number[i];
	}
	if (prev_permutation(number.begin(), number.end()) == true) {
		for (int i = 0; i < cnt; i++) {
			cout << number[i] << ' ';
		}
	}
	else {
		cout << -1;
	}

	return 0;
}