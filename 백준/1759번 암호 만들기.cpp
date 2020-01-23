#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int goal;
int cnt;
int vowel;
int consonant;
bool check[15];

bool cal(vector<char> &ans) {
	vowel = consonant = 0;
	for (int i = 0; i < goal; i++) {
		if (ans[i] == 'a' || ans[i] == 'e' || ans[i] == 'i' || ans[i] == 'o' || ans[i] == 'u') {
			vowel++;
		}
		else {
			consonant++;
		}
	}
	if (vowel >= 1 && consonant >= 2) {
		return true;
	}
	return false;
}

void solve(vector<char> &alpha, vector<char> &ans, int selectCnt, int start) {
	if (selectCnt == goal) {
		if (cal(ans) == true) {
			for (int i = 0; i < goal; i++) {
				cout << ans[i];
			}
			cout << '\n';
		}
		return;
	}
	for (int i = start; i < cnt; i++) {
		if (check[i] == true) {
			continue;
		}
		check[i] = true;
		ans[selectCnt]= alpha[i];
		solve(alpha, ans, selectCnt + 1, i);
		check[i] = false;
	}
}

int main() {
	cin >> goal >> cnt;
	vector<char> alpha(cnt);
	vector<char> ans(goal);
	for (int i = 0; i < cnt; i++) {
		cin >> alpha[i];
	}
	sort(alpha.begin(), alpha.end());
	solve(alpha, ans, 0, 0);
	return 0;
}