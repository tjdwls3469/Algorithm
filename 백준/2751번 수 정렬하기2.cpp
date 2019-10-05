#include <stdio.h>
#pragma warning(disable:4996)

int partition(int *ary, int start,int end);
void quickSort(int *ary, int start, int end);
int ary[1000000];

int main() {
	int cnt;
	int i;

	scanf("%d", &cnt);
	for (i = 0; i < cnt; i++) {
		scanf("%d", &ary[i]);
	}
	quickSort(ary, 0, cnt-1);
	for (i = 0; i < cnt; i++) {
		printf("%d\n", ary[i]);
	}
	
	return 0;
}

int partition(int *ary, int start, int end) {
	int pivot = ary[start];
	int i = start;
	int j;
	int temp;

	for (j = i + 1; j <= end; j++) {
		if (ary[j] < pivot) {
			i++;
			temp = ary[i];
			ary[i] = ary[j];
			ary[j] = temp;
		}
	}
	temp = ary[start];
	ary[start] = ary[i];
	ary[i] = temp;

	return i;
}

void quickSort(int *ary, int start, int end) {
	int pivot;

	if (start < end) {
		pivot = partition(ary, start, end);
		
		quickSort(ary, start, pivot - 1);
		quickSort(ary, pivot + 1, end);
	}

	return;
}