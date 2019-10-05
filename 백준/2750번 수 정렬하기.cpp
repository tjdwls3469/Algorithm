#include <stdio.h>
#pragma warning(disable:4996)

int main() {
	int ary[1000];

	int i;
	int j;
	int min;
	int temp;
	int index;
	int cnt;

	scanf("%d", &cnt);

	for (i = 0; i < cnt; i++) {
		scanf("%d", &ary[i]);
	}

	for (i = 0; i < cnt; i++) {
		min = 1001;
		for (j = i; j < cnt; j++) {
			if (ary[j] < min) {
				min = ary[j];
				index = j;
			}
		}
		temp = ary[i];
		ary[i] = min;
		ary[index] = temp;
	}

	for (i = 0; i < cnt; i++) {
		printf("%d\n", ary[i]);
	}

	return 0;
}