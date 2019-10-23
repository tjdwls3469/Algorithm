#include <iostream>
using namespace std;

int time[15];
int pay[15];
int result;
int endTime;

void solve(int day, int sum) {
	if (day == endTime) {
		if (sum > result) {
			result = sum;
		}
		return;
	}
	if (day > endTime) {
		return;
	}
	solve(day + time[day], sum + pay[day]);
	solve(day + 1, sum);
}

int main() {
	cin >> endTime;
	for (int i = 0; i < endTime; i++) {
		cin >> time[i] >> pay[i];
	}
	solve(0, 0);
	cout << result;

	return 0;
}