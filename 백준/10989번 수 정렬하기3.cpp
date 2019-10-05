#include <stdio.h>
#pragma warning (disable:4996)

int count[10000];

int main() {
	int cnt;
	int num;
	scanf("%d", &cnt);

	for (int i = 0; i < cnt; i++) {
		scanf("%d", &num);
		count[num - 1]++;
	}

	for (int i = 0; i < 10000; i++) {
		for (int j = 0; j < count[i]; j++) {
			printf("%d\n", i + 1);
		}
	}

	return 0;
}