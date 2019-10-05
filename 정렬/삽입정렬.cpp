#include <stdio.h>

int main() {
	int ary[10] = { 1, 10, 5, 8, 7, 6, 4, 3, 2, 9 };

	int i;
	int j;
	int temp;

	for (i = 1; i <= 9; i++) {
		j = i;
		while (j>=0 && ary[j] < ary[j - 1]) {
			temp = ary[j];
			ary[j] = ary[j - 1];
			ary[j - 1] = temp;
			j--;
		}
	}

	for (i = 0; i < 10; i++) {
		printf("%d ", ary[i]);
	}

	return 0;
}