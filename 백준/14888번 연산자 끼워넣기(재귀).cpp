#include <iostream>
#include <vector>
#include <climits>
using namespace std;

bool check[10];
int ans[10];
int cnt;
int maxVal = INT_MIN;
int minVal = INT_MAX;

void solve(int index, int selectCnt, vector<int> &num, vector<int> &oper) {
	if (selectCnt == cnt - 1) {
		int result = num[0];
		for (int i = 0; i < cnt - 1; i++) {
			switch (ans[i]) {
			case 0:
				result += num[i + 1];
				break;
			case 1:
				result -= num[i + 1];
				break;
			case 2:
				result *= num[i + 1];
				break;
			case 3:
				result /= num[i + 1];
				break;
			default:
				;
				break;
			}
		}
		if (result > maxVal) {
			maxVal = result;
		}
		if (result < minVal) {
			minVal = result;
		}
		return;
	}
	if (index == cnt - 1) {
		return;
	}
	for (int i = 0; i < cnt - 1; i++) {
		if (check[i] == false) {
			check[i] = true;
			ans[selectCnt] = oper[i];
			solve(index + 1, selectCnt + 1, num, oper);
			check[i] = false;
			ans[selectCnt] = 0;
		}
		solve(index + 1, selectCnt, num, oper);
	}
}

int main() {
	int operCnt;
	vector<int> oper;
	cin >> cnt;
	vector<int> num(cnt);
	for (int i = 0; i < cnt; i++) {
		cin >> num[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> operCnt;
		for (int j = 0; j < operCnt; j++) {
			oper.push_back(i);
		}
	}
	solve(0, 0, num, oper);
	cout << maxVal << '\n' << minVal;
	return 0;
}