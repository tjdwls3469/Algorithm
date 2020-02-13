#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	int cnt;
	vector<int> num(10);
	cin >> cnt;
	vector<char> oper(cnt);
	for (int i = 0; i < cnt; i++) {
		cin >> oper[i];
	}
	for (int i = 0; i < 10; i++) {
		num[i] = 9 - i;
	}
	do {
		bool ok = true;
		for (int i = 0; i < cnt; i++) {
			if (oper[i] == '<') {
				if (num[i] > num[i + 1]) {
					ok = false;
					break;
				}
			}
			else {
				if (num[i] < num[i + 1]) {
					ok = false;
					break;
				}
			}
		}
		if (ok == true) {
			break;
		}
	} while (prev_permutation(num.begin(), num.end()));
	string maxAns = "";
	for (int i = 0; i < cnt + 1; i++) {
		maxAns += to_string(num[i]);
	}
	sort(num.begin(), num.end());
	do {
		bool ok = true;
		for (int i = 0; i < cnt; i++) {
			if (oper[i] == '<') {
				if (num[i] > num[i + 1]) {
					ok = false;
					break;
				}
			}
			else {
				if (num[i] < num[i + 1]) {
					ok = false;
					break;
				}
			}
		}
		if (ok == true) {
			break;
		}
	} while (next_permutation(num.begin(), num.end()));
	string minAns = "";
	for (int i = 0; i < cnt + 1; i++) {
		minAns += to_string(num[i]);
	}
	cout << maxAns << '\n' << minAns;
	return 0;
}