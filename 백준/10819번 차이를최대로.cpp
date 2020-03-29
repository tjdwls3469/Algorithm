#include <iostream>
using namespace std;

int num[8];

void sort(int *ary, int begin, int end) {
	if (begin >= end) {
		return;
	}
	int pivot = ary[(begin + end) / 2];
	int left = begin;
	int right = end;
	while (left <= right) {
		while (ary[left] < pivot) {
			left++;
		}
		while (ary[right] > pivot) {
			right--;
		}
		if (left <= right) {
			int temp;
			temp = ary[left];
			ary[left] = ary[right];
			ary[right] = temp;
			left++;
			right--;
		}
	}
	sort(ary, begin, right);
	sort(ary, left, end);
}

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
	int cnt;
	int ans = -1;
	cin >> cnt;
	for (int i = 0; i < cnt; i++) {
		cin >> num[i];
	}
	sort(num, 0, cnt - 1);
	do {
		int sum = 0;
		for (int i = 0; i < cnt - 1; i++) {
			int temp = num[i] - num[i + 1];
			if (temp < 0) {
				temp = -temp;
			}
			sum += temp;
		}
		if (sum > ans) {
			ans = sum;
		}
	} while (next_permutation(num, cnt) == true);
	cout << ans;
	return 0;
}