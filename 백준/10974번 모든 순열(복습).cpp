#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int cnt;
	cin >> cnt;
	vector<int> num(cnt);
	for (int i = 0; i < cnt; i++) {
		num[i] = i + 1;
	}
	do {
		for (int i = 0; i < cnt; i++) {
			cout << num[i] << ' ';
		}
		cout << '\n';
	} while (next_permutation(num.begin(), num.end()) == true);
	return 0;
}