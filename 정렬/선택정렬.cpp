#include <stdio.h>

int main() {
	int ary[10] = { 1, 10, 5, 8, 7, 6, 4, 3, 2, 9 };

	int i;
	int j;
	int min;
	int index;
	int temp;

	for (i = 0; i < 10; i++) {
		min = 100;
		for (j = i; j < 10; j++) { // 최소값과 최소값이 있는 인덱스를 구한다.
			if (ary[j] < min) {
				min = ary[j];
				index = j;
			}
		}
		temp = ary[i];
		ary[i] = min;
		ary[index] = temp;
	}

	for (i = 0; i < 10; i++) {
		printf("%d ", ary[i]);
	}

	return 0;
}