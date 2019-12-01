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
	ansAry[0] = 1;
	for (int i = 1; i <= cnt; i++) {
		for (int j = 1; j <= value; j++) {
			if (j - valueAry[i] >= 0) {
				ansAry[j] += ansAry[j - valueAry[i]];
			}
		}
	}
	cout << ansAry[value];

	return 0;
}