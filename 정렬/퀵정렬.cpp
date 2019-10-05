#include <stdio.h>

int partition(int *ary, int start, int end);
void quickSort(int *ary, int start, int end);

int main() {
	int ary[10] = { 1, 10, 5, 8, 7, 6, 4, 3, 2, 9 };
	int i;

	quickSort(ary, 0, 9);
	for (i = 0; i < 10; i++) {
		printf("%d ", ary[i]);
	}
	return 0;
}

int partition(int *ary, int start, int end) {
	int i = start;
	int p = ary[start]; // 피봇은 값이어야한다.
	int j;
	int temp;

	for (j = i + 1; j <= end; j++) {
		if (ary[j] < p) { // 피벗보다 크다면 i를 1증가시키고 swap (오름차순)
		//if (ary[j] > p) { // 내림차순
			i++;
			temp = ary[i];
			ary[i] = ary[j];
			ary[j] = temp;
		}
	}
	temp = ary[start]; // for문이 종료되면 pibot과 ary[i]를 swap
	ary[start] = ary[i];
	ary[i] = temp;

	return i;
}

void quickSort(int *ary, int start, int end) {
	int p;

	if (start < end) {
		p = partition(ary, start, end);
		quickSort(ary, start, p - 1);
		quickSort(ary, p+1, end);
	}

	return;
}