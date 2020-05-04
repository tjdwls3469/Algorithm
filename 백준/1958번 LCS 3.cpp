#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int ans[101][101][101];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string str1;
	string str2;
	string str3;
	cin >> str1 >> str2 >> str3;
	int z = str1.length();
	int x = str2.length();
	int y = str3.length();
	for (int i = 1; i <= z; i++) {
		for (int j = 1; j <= x; j++) {
			for (int k = 1; k <= y; k++) {
				if (str1[i - 1] == str2[j - 1] && str2[j - 1] == str3[k - 1] && str3[k - 1] == str1[i - 1]) {
					ans[i][j][k] = ans[i - 1][j - 1][k - 1] + 1;
				}
				else {
					ans[i][j][k] = max(max(ans[i - 1][j][k], ans[i][j - 1][k]), ans[i][j][k - 1]);
				}
			}
		 }
	}
	cout << ans[z][x][y];
	return 0;
}