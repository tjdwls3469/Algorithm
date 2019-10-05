#include <stdio.h>
#pragma warning(disable:4996)

int main() {
	int ary[3];

	int i;
	int j;
	int min;
	int temp;
	int index;

	for (i = 0; i < 3; i++) {
		scanf("%d", &ary[i]);
	}

	for (i = 0; i < 3; i++) {
		min = 4;
		for (j = i; j < 3; j++) {
			if (ary[j] < min) {
				min = ary[j];
				index = j;
			}
		}
		temp = ary[i];
		ary[i] = min;
		ary[index] = temp;
	}

	for (i = 0; i < 3; i++) {
		printf("%d ", ary[i]);
	}

	return 0;
}