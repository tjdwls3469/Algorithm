#include <iostream>
using namespace std;

int valueAry[101];
int ansAry[10001];

int main() {
	int cnt, value;
	cin >> cnt >> value;
	for (int i = 1; i <= cnt; i++) {
		cin >> valueAry[i];
	}
	for (int i = 0; i <= value; i++) {
		ansAry[i] = -1;
	}
	ansAry[0] = 0;
	for (int i = 1; i <= cnt; i++) {
		for (int j = 0; j <= value; j++) {
			if (j - valueAry[i] >= 0 && ansAry[j - valueAry[i]] != -1) {
				if (ansAry[j] == -1 || ansAry[j - valueAry[i]] + 1 < ansAry[j]) {
					ansAry[j] = ansAry[j - valueAry[i]] + 1;
				}
			}
		}
	}
	cout << ansAry[value];

	return 0;
}