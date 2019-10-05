#include <stdio.h>

int main() {
	int ary[30] = { 1,2,3,4,5,1,2,3,4,5,
					1,2,3,4,5,1,2,3,4,5,
					1,2,3,4,5,1,2,3,4,5 };
	int count[5] = { 0, };
	int i;

	for (i = 0; i < 30; i++) {
		count[ary[i] - 1]++;
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < count[i]; j++) {
			printf("%d", i + 1);
		}
	}

	return 0;
}