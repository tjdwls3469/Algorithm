#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

bool check[26];

int main() {
	int cnt;
	int alphCnt = 0;
	int index = 0;
	cin >> cnt;
	vector<string> word(cnt);
	map<char, int> m;
	for (int i = 0; i < cnt; i++) {
		cin >> word[i];
		for (int j = 0; j < word[i].length(); j++) {
			/*if (check[word[i][j] - 'A'] == false) {
				check[word[i][j] - 'A'] = true;
				alphCnt++;
			}*/
			m[word[i][j]] = -1;
		}
	}
	cout << m.size();
	vector<int> num(m.size());
	/*vector<int> num(alphCnt);
	for (int i = 0; i < alphCnt; i++) {
		num[i] = 9 - i;
	}
	do {
		for (int i = 0; i < cnt; i++) {
			if (i > 0) {
				index += word[i - 1].length();
			}
			for (int j = 0; j < word[i].length(); j++) {
				m[word[i][j]] = num[j + index];
			}
		}
		for (int i = 0; i < m.size(); i++) {
			cout << m[i];
		}
	} while (prev_permutation(num.begin(), num.end()) == true);*/
	return 0;
}