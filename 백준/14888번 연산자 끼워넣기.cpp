#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int num[100];
int operCnt[4];

int main() {
	int max = INT_MIN;
	int min = INT_MAX;
	int cnt;
	cin >> cnt;
	for (int i = 0; i < cnt; i++) {
		cin >> num[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> operCnt[i];
	}
	vector<int> oper;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < operCnt[i]; j++) {
			oper.push_back(i + 1);
		}
	}
	do {
		int result = num[0];
		for (int i = 1; i < cnt; i++) {
			switch (oper[i-1]) {
			case 1:
				result += num[i];
				break;
			case 2:
				result -= num[i];
				break;
			case 3:
				result *= num[i];
				break;
			case 4:
				result /= num[i];
				break;
			default:;
				break;
			}
		}
		if (result > max) {
			max = result;
		}
		if (result < min) {
			min = result;
		}
	} while (next_permutation(oper.begin(), oper.end()) == true);
	cout << max << '\n' << min;
	return 0;
}