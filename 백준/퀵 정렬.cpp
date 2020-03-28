#include <iostream>
using namespace std;

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

void dec(int *ary, int begin, int end) {
	if (begin >= end) {
		return;
	}
	int pivot = ary[(begin + end) / 2];
	int left = begin;
	int right = end;
	while (left <= right) {
		while (ary[left] > pivot) {
			left++;
		}
		while (ary[right] < pivot) {
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
	dec(ary, begin, right);
	dec(ary, left, end);
}

void print(int *ary) {
	for (int i = 0; i < 10; i++) {
		cout << ary[i] << ' ';
	}
	cout << '\n';
}

int main() {
	int ary[10] = { 9,9,9,9,4,4,5,5,1,1 };
	print(ary);
	sort(ary, 0, 9);
	print(ary);
	dec(ary, 0, 9);
	print(ary);

	return 0;
}