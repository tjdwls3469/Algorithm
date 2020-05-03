#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int ans[1001][1001];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string str1;
	string str2;
	cin >> str1 >> str2;
	int row = str1.length();
	int col = str2.length();
	for (int i = 1; i <= row; i++) {
		for (int j = 1; j <= col; j++) {
			if (str1[i - 1] == str2[j - 1]) {
				ans[i][j] = ans[i - 1][j - 1] + 1;
			}
			else {
				ans[i][j] = max(ans[i - 1][j], ans[i][j - 1]);
			}
		}
	}
	cout << ans[row][col];
	return 0;
}