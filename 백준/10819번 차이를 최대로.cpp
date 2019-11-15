#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

int cnt;
int result;

void cal(vector<int> &number) {
	int sum = 0;
	for (int i = 0; i < cnt - 1; i++) {
		sum += abs(number[i] - number[i + 1]);
	}
	if (sum > result) {
		result = sum;
	}
}

int main() {
	cin >> cnt;
	vector<int> number(cnt);
	for (int i = 0; i < cnt; i++) {
		cin >> number[i];
	}
	sort(number.begin(), number.end());
	cal(number);
	while (true) {
		if (next_permutation(number.begin(), number.end()) == false) {
			break;
		}
		cal(number);
	}
	cout << result;

	return 0;
}