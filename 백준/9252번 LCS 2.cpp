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
				ans[i][j] = max(ans[i][j - 1], ans[i - 1][j]);
			}
		}
	}
	string strAns = "";
	int x = row;
	int y = col;
	/*
	LCS 구하기
	1. 다른 숫자가 나올때까지 왼쪽으로 이동
	2. 왼쪽에 다른 숫자가 나오면 바로 위의 숫자랑 비교
	   같으면 위로 한칸 이동 후 1번으로 
	   다르면 문자 저장하고 i-1, j-1로 이동 후 1번으로
	*/
	while (true) {
		if (ans[x][y] == 0) {
			break;
		}
		if (ans[x][y] == ans[x][y - 1]) {
			y--;
		}
		else if (ans[x][y] == ans[x - 1][y]) {
			x--;
		}
		else {
			strAns += str1[x - 1];
			x--;
			y--;
		}
	}
	cout << ans[row][col] << '\n';
	for (int i = strAns.length() - 1; i >= 0; i--) {
		cout << strAns[i];
	}
	return 0;
}