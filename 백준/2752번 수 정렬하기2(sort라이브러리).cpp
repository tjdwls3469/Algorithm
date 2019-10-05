#include <stdio.h>
#include <algorithm>

#pragma warning(disable:4996)

int ary[1000000];

int main() {
	int cnt;
	int i;

	scanf("%d", &cnt);
	for (i = 0; i < cnt; i++) {
		scanf("%d", &ary[i]);
	}

	// std::sort(ary, ary + cnt, std::greater<int>()); // 내림차순
	std::sort(ary, ary + cnt);
	for (i = 0; i < cnt; i++) {
		printf("%d\n", ary[i]);
	}

	return 0;
}