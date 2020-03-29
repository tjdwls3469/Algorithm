#include <iostream>
using namespace std;

int num[10000];

bool next_permutation(int *ary, int len) {
	int i = len - 1;
	while (i>0 && ary[i - 1] >= ary[i]) {
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
	int cnt;
	cin >> cnt;
	for (int i = 0; i < cnt; i++) {
		cin >> num[i];
	}
	if (next_permutation(num, cnt) == false) {
		cout << -1;
	}
	else {
		for (int i = 0; i < cnt; i++) {
			cout << num[i] << ' ';
		}
	}
	return 0;
}