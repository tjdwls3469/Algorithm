//#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#pragma warning(disable:4996)

using namespace std;

string ary[20000];

bool compare(string a, string b) {
	if (a.length() < b.length()) {
		return 1;
	}
	else if (a.length() > b.length()){
		return 0;
	}
	else {
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

	sort(ary, ary+cnt, compare);

	for (i = 0; i < cnt; i++) {
		if (i > 0 && ary[i] == ary[i - 1]) {
			continue;
		}
		cout << ary[i] << '\n';
	}

	return 0;
}