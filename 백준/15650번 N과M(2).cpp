#include <iostream>
using namespace std;

int num;
int cnt;
int result[8];

void solve(int index, int selected, int num, int cnt) {
	if (selected == cnt) {
		for (int i = 0; i < cnt; i++) {
			cout << result[i] << ' ';
		}
		cout << '\n';
		return;
	}
	if (index > num) {
		return;
	}
	result[selected] = index;
	solve(index + 1, selected + 1, num, cnt);
	result[selected] = 0;
	solve(index + 1, selected, num, cnt);
}

int main() {
	cin >> num >> cnt;
	solve(1, 0, num, cnt);

	return 0;
}