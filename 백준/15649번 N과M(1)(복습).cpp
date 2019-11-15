#include <iostream>
#include <vector>
using namespace std;

bool check[9];
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
		if (check[i] == true) {
			continue;
		}
		check[i] = true;
		result[index] = i;
		solve(index + 1, max, cnt);
		check[i] = false;
	}
}

int main() {
	int max;
	int cnt;
	cin >> max >> cnt;
	solve(0, max, cnt);

	return 0;
}