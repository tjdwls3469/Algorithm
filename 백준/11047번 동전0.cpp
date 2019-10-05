#include <iostream>
#pragma warning(disable:4996)

using namespace std;

int main() {
	int cnt;
	int money;
	int result = 0;
	scanf("%d %d", &cnt, &money);

	int ary[11] = { 0, };
	for (int i = 1; i <= cnt; i++) {
		scanf("%d", &ary[i]);
	}

	for (int i = cnt; i >= 1; i--) {
		result += money / ary[i];
		money = money % ary[i];
	}

	cout << result;

	return 0;
}