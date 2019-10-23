#include <iostream>
using namespace std;

int num;
int cnt;
bool check[9];
int result[8];

void solve(int index, int num, int cnt) {
	if (index == cnt) {
		for (int i = 0; i < cnt; i++) {
			cout << result[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = 1; i <= num; i++) {
		if (check[i] == true) {
			continue;
		}
		check[i] = true;
		result[index] = i;
		solve(index + 1, num, cnt);
		check[i] = false;
	}
}

int main() {
	cin >> num >> cnt;
	solve(0, num, cnt);

	return 0;
}