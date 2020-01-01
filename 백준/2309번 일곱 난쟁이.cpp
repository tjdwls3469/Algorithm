#include <iostream>
#include <algorithm>
using namespace std;

int dwarf[9];
int n = 9;

int main() {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> dwarf[i];
		sum += dwarf[i];
	}
	sort(dwarf, dwarf + n);
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (sum - dwarf[i] - dwarf[j] == 100) {
				for (int k = 0; k < n; k++) {
					if (k == i || k == j) {
						continue;
					}
					cout << dwarf[k] << '\n';
				}
				return 0;
			}
		}
	}
}