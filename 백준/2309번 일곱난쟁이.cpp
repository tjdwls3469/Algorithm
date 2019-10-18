#include <iostream>
#include <algorithm>
using namespace std;

int ary[9];

int main() {
	int sum = 0;
	for (int i = 0; i < 9; i++) {
		cin >> ary[i];
		sum += ary[i];
	}
	sort(ary, ary + 9);

	for (int i = 0; i < 9; i++) {
		for (int j = i + 1; j < 9; j++) {
			if (sum - ary[i] - ary[j] == 100) {
				for (int k = 0; k < 9; k++) {
					if (k == i || k == j) {
						continue;
					}
					cout << ary[k] << '\n';
				}
				return 0;
			}
		}
	}

	return 0;
}