#include <iostream>
#include <vector>
using namespace std;

vector<int> lotto;
void solve(vector<int> &ary, int index, int cnt) {
	if (cnt == 6) {
		for (int result : lotto) {
			cout << result << ' ';
		}
		cout << '\n';
		return;
	}
	if (index == ary.size()) {
		return;
	}
	lotto.push_back(ary[index]);
	solve(ary, index + 1, cnt + 1);
	lotto.pop_back();
	solve(ary, index + 1, cnt);
}

int main() {
	while (true) {
		int cnt;
		cin >> cnt;
		if (cnt == 0) {
			break;
		}
		vector<int> ary(cnt);
		for (int i = 0; i < cnt; i++) {
			cin >> ary[i];
		}
		solve(ary, 0, 0);
		cout << '\n';
	}

	return 0;
}