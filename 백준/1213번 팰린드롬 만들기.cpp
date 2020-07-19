#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int alph[26];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int oddNumCnt = 0;
	string front = "";
	string ans = "";
	char center = '\0';
	string name;
	cin >> name;

	for (int i = 0; i < name.length(); i++) {
		alph[name[i] - 65]++;		// 알파벳 개수 저장
	}

	for (int i = 0; i < 26; i++) {
		//cout << alph[i] << ' ';
		if (alph[i] % 2 != 0) {		// 홀수인거 저장
			oddNumCnt++;
		}
	}

	if (oddNumCnt > 1) {
		cout << "I'm Sorry Hansoo";
		return 0;
	}
	else {
		for (int i = 0; i < 26; i++) {
			if (alph[i] == 0) {
				continue;
			}
			if (alph[i] % 2 != 0) {		// 홀수 이면 center 문자로 저장
				center = char(i + 65);
			}
			for (int j = 0; j < alph[i] / 2; j++) {		// 사전순
				front += char(i + 65);
			}
		}
	}

	ans += front;
	if (oddNumCnt != 0) {
		ans += center;
	}
	reverse(front.begin(), front.end());
	ans += front;

	cout << ans;

	return 0;
}