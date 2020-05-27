#include <iostream>
using namespace std;

int n = 7;
int ary[7] = { 7,7,7,4,7,6,5 };

void sort(int start, int end) {
	if (start >= end) {
		return;
	}
	int p = start;
	int left = start + 1;
	int right = end;
	int temp;
	while (true) {
		while (ary[left] <= ary[p]) {
			left++;
		}
		while (ary[right] >= ary[p]) {
			right--;
		}
		if (left > right) {
			break;
		}
		temp = ary[left];
		ary[left] = ary[right];
		ary[right] = temp;
	}
	temp = ary[p];
	ary[p] = ary[right];
	ary[right] = temp;
	sort(start, right - 1);
	sort(right + 1, end);
}

//void sort(int begin, int end) {
//	if (begin >= end) {
//		return;
//	}
//	int pivot = begin;
//	int left = begin + 1;
//	int right = end;
//	int temp;
//	while (left <= right) {
//		while (ary[left] <= ary[pivot]) {
//			left++;
//		}
//		while (ary[right] >= ary[pivot]) {
//			right--;
//		}
//		if (left > right) {
//			temp = ary[right];
//			ary[right] = ary[pivot];
//			ary[pivot] = temp;
//			break;
//		}
//		else{
//			temp = ary[left];
//			ary[left] = ary[right];
//			ary[right] = temp;
//		}
//	}
//	sort(begin, right - 1);
//	sort(right + 1, end);
//}

int main() {
	for (int i = 0; i < n; i++) {
		cout << ary[i] << ' ';
	}
	cout << '\n';
	sort(0, n - 1);
	for (int i = 0; i < n; i++) {
		cout << ary[i] << ' ';
	}
	return 0;
}