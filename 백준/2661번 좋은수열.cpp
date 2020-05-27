/*
DFS를 이용해서 수열을 만드는데
좋은수열인지 나쁜수열인지 판단은 길이의 절반까지만 하면된다
*/
#include <iostream>
#include <string>
using namespace std;

int len;
bool ok = false;

bool check(int node, string origin) {
	for (int i = 0; i < origin.length(); i++) {
		string temp = ""; // temp는 끝에서 2개, 3개, 4개, n/2의 길이까지의 문자열
		for (int j = origin.length() - 2 - i; j < origin.length(); j++) {
			temp += origin[j];
		}
		if (temp.length() > origin.length() / 2) {
			break;
		}
		string com = ""; // com은 temp의 바로앞 2개, 3개, 4개, n/2의 길이까지의 문자열
		for (int j = origin.length() - 2 - i - temp.length(); j < origin.length() - 2 - i; j++) {
			com += origin[j];
		}
		if (com == temp) { // com과 temp가 같으면 나쁜수열
			return false;
		}
	}
	return true;
}

void dfs(int node, string ans) {
	if (ok == true) { // 수열이 구해졌으면 DFS 탈출
		return;
	}
	if (ans.length() == len) { // 수열이 구해졌으면 답 출력
		cout << ans;
		ok = true;
		return;
	}
	for (int i = 1; i <= 3; i++) {
		if (i == node) { // 연속으로 같은 수 오는거 방지
			continue;
		}
		if (check(i, ans + to_string(i)) == true) { // 현재 수열에 수를 붙인거 체크
			dfs(i, ans + to_string(i));
		}
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> len;
	dfs(1, "1"); // 가장 작은 수니깐 1로 시작
	return 0;
}