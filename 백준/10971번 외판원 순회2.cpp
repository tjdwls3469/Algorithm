#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

int cnt;
int cost[11][11];
int result = 2147483647;

void cal(vector<int> &number) {
	int sum = 0;
	if (cost[number[cnt - 1]][number[0]] == 0) {
		return;
	}
	for (int i = 0; i < cnt - 1; i++) {
		if (cost[number[i]][number[i + 1]] == 0) {
			return;
		}
		sum += cost[number[i]][number[i + 1]];
	}
	sum += cost[number[cnt - 1]][number[0]];
	if (sum < result) {
		result = sum;
	}
}

int main() {
	cin >> cnt;
	vector<int> number(cnt);
	for (int i = 1; i <= cnt; i++) {
		number[i-1] = i;
		for (int j = 1; j <= cnt; j++) {
			cin >> cost[i][j];
		}
	}
	cal(number);
	while (true) {
		if (next_permutation(number.begin(), number.end()) == true) {
			cal(number);
		}
		else {
			break;
		}
	}
	cout << result;

	return 0;
}