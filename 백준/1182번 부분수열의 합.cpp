#include <iostream>
using namespace std;

int cnt;
int s;
int result;
int ary[20];

void solve(int index, int sum) {
	if (sum == s && index == cnt) {
		result++;
	}
	if (index >= cnt) {
		return;
	}
	solve(index + 1, sum + ary[index]);
	solve(index + 1, sum);
}

int main() {
	cin >> cnt >> s;
	for (int i = 0; i < cnt; i++) {
		cin >> ary[i];
	}
	solve(0, 0);
	if (s == 0) {
		result--;
	}
	cout << result;

	return 0;
}