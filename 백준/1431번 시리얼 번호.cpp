#include <iostream>
#include <algorithm>
#include <string>
#pragma warning(disable:4996)

using namespace std;

string ary[1000];

bool compare(string a, string b) {
	int sumA = 0;
	int sumB = 0;

	if (a.length() != b.length()) {
		return a.length() < b.length();
	}
	else {
		for (int i = 0; i < a.length(); i++) {
			if (a[i] - '0' >= 0 && a[i] - '0' <= 9) {
				sumA += a[i] - '0';
			}
		}
		for (int i = 0; i < b.length(); i++) {
			if (b[i] - '0' >= 0 && b[i] - '0' <= 9) {
				sumB += b[i] - '0';
			}
		}
		if (sumA != sumB) {
			return sumA < sumB;
		}
		return a < b;
	}
}

int main() {
	int cnt;
	int i;

	scanf("%d", &cnt);
	for (i = 0; i < cnt; i++) {
		cin >> ary[i];
	}

	sort(ary, ary + cnt, compare);

	for (i = 0; i < cnt; i++) {
		cout << ary[i] << '\n';
	}

	return 0;
}