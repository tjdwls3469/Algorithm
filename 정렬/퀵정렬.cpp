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
	int p = ary[start]; // �Ǻ��� ���̾���Ѵ�.
	int j;
	int temp;

	for (j = i + 1; j <= end; j++) {
		if (ary[j] < p) { // �ǹ����� ũ�ٸ� i�� 1������Ű�� swap (��������)
		//if (ary[j] > p) { // ��������
			i++;
			temp = ary[i];
			ary[i] = ary[j];
			ary[j] = temp;
		}
	}
	temp = ary[start]; // for���� ����Ǹ� pibot�� ary[i]�� swap
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