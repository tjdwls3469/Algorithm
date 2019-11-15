#include <iostream>
#include <vector>
using namespace std;

vector<int> result(9);
void solve(int index, int max, int cnt) {
	if (index == cnt) {
		for (int i = 0; i < cnt; i++) {
			cout << result[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = 1; i <= max; i++) {
		result[index] = i;
		solve(index + 1, max, cnt);
	}
}

int main() {
	int max;
	int cnt;
	cin >> max >> cnt;
	solve(0, max, cnt);

	return 0;
}