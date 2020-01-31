#include <iostream>
#include <vector>
using namespace std;

void solve(int start, vector<int> &num, vector<int> &seq) {
	if (start == -1) {
		return;
	}
	solve(seq[start], num, seq);
	cout << num[start] << ' ';
}

int main() {
	int cnt;
	cin >> cnt;
	vector<int> num(cnt);
	vector<int> part(cnt);
	vector<int> seq(cnt);
	for (int i = 0; i < cnt; i++) {
		cin >> num[i];
	}
	for (int i = 0; i < cnt; i++) {
		part[i] = 1;
		seq[i] = -1;
		for (int j = 0; j < i; j++) {
			if (num[i] > num[j] && part[i] < part[j] + 1) {
				part[i] = part[j] + 1;
				seq[i] = j;
			}
		}
	}
	int ans = 0;
	int index = 0;
	for (int i = 0; i < cnt; i++) {
		if (part[i] > ans) {
			ans = part[i];
			index = i;
		}
	}
	cout << ans << '\n';
	solve(index, num, seq);
	return 0;
}