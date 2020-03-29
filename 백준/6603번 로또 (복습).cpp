#include <iostream>
using namespace std;

int num[12];

bool next_permutation(int *ary, int len) {
	int i = len - 1;
	while (i > 0 && ary[i - 1] >= ary[i]) {
		i -= 1;
	}
	if (i <= 0) {
		return false;
	}
	int j = len - 1;
	while (ary[j] <= ary[i - 1]) {
		j -= 1;
	}
	int temp = ary[i - 1];
	ary[i - 1] = ary[j];
	ary[j] = temp;
	j = len - 1;
	while (i < j) {
		temp = ary[i];
		ary[i] = ary[j];
		ary[j] = temp;
		i += 1;
		j -= 1;
	}
	return true;
}

int main() {
	while (true) {
		int cnt;
		cin >> cnt;
		if (cnt == 0) {
			break;
		}
		for (int i = 0; i < cnt; i++) {
			cin >> num[i];
		}
		int lotto[12];
		for (int i = 0; i < 6; i++) {
			lotto[i] = 0;
		}
		for (int i = 6; i < cnt; i++) {
			lotto[i] = 1;
		}
		do {
			int temp[6];
			int j = 0;
			for (int i = 0; i < cnt; i++) {
				if (lotto[i] == 0) {
					temp[j] = num[i];
					j++;
				}
			}
			for (int i = 0; i < 6; i++) {
				cout << temp[i] << ' ';
			}
			cout << '\n';
		} while (next_permutation(lotto, cnt) == true);
		cout << '\n';
	}
	return 0;
}