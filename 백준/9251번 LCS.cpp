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
	/*
	LCS길이 구하기
	DP표를 만들때 각 문자열 앞에 0을 추가해서 첫번째 행과 열을 모두 0으로 만든다
	str1[i]와 str2[j]를 비교하여
	같으면 (i,j) = (i-1,j-1)+1
	다르면 (i,j) = max( (i-1,j), (i,j-1) )
	*/
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