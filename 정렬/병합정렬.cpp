#include <stdio.h>

int sorted[8];

void merge(int *ary, int first, int middle, int end);
void mergeSort(int *ary, int first, int end);

int main() {
	int ary[8] = { 7,6,5,8,3,5,9,1 };
	mergeSort(ary, 0, 7);
	for (int i = 0; i < 8; i++) {
		printf("%d ", ary[i]);
	}

	return 0;
}

void merge(int *ary, int first, int middle, int end) {
	int i = first;
	int j = middle + 1;
	int k = first;
	int l;

	while (i <= middle && j <= end) {
		if (ary[i] < ary[j]) {
			sorted[k] = ary[i];
			i++;
		}
		else {
			sorted[k] = ary[j];
			j++;
		}
		k++;
	}

	if (i > middle) {
		for (l = j; l <= end; l++) {
			sorted[k] = ary[l];
			k++;
		}
	}
	else {
		for (l = i; l <= middle; l++) {
			sorted[k] = ary[l];
			k++;
		}
	}

	for (i = 0; i <= end; i++) {
		ary[i] = sorted[i];
	}

	return;
}

void mergeSort(int *ary, int first, int end){
	int middle;

	if (first < end) {
		middle = (first + end) / 2;
		mergeSort(ary, first, middle);
		mergeSort(ary, middle + 1, end);
		merge(ary, first, middle, end);
	}

	return;
}