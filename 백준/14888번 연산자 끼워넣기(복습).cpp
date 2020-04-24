#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int maxAns = INT_MIN;
	int minAns = INT_MAX;
	int cnt;
	cin >> cnt;
	vector<int> num(cnt);
	for (int i = 0; i < cnt; i++) {
		cin >> num[i];
	}
	int operCnt[4];
	for (int i = 0; i < 4; i++) {
		cin >> operCnt[i];
	}
	vector<int> oper;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < operCnt[i]; j++) {
			oper.push_back(i);
		}
	}
	do {
		int sum = num[0];
		for (int i = 0; i < oper.size(); i++) {
			switch (oper[i]) {
			case 0:
				sum += num[i + 1];
				break;
			case 1:
				sum -= num[i + 1];
				break;
			case 2:
				sum *= num[i + 1];
				break;
			default:
				sum /= num[i + 1];
				break;
			}
		}
		maxAns = max(sum, maxAns);
		minAns = min(sum, minAns);
	} while (next_permutation(oper.begin(), oper.end()) == true);
	cout << maxAns << '\n' << minAns;
	return 0;
}