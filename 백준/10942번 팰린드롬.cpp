#include <iostream>
using namespace std;

int sequence[2000];
int ans[2000][2000];

int solve(int start, int end) {
	if (start == end) {
		return 1;
	}
	else if (start + 1 == end) {
		if (sequence[start] == sequence[end]) {
			return 1;
		}
		else {
			return 0;
		}
	}
	if (ans[start][end] != -1) {
		return ans[start][end];
	}
	if (sequence[start] != sequence[end]) {
		return ans[start][end] = 0;
	}
	else {
		return ans[start][end] = solve(start + 1, end - 1);
	}
}

int main() {
	int size;
	int cnt;
	cin >> size;
	for (int i = 0; i < size; i++) {
		cin >> sequence[i];
	}
	memset(ans, -1, sizeof(ans));
	cin >> cnt;
	for (int i = 0; i < cnt; i++) {
		int start;
		int end;
		cin >> start >> end;
		cout << solve(start - 1, end - 1) << '\n';
	}

	return 0;
}