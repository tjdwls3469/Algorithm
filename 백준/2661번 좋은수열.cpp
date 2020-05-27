/*
DFS�� �̿��ؼ� ������ ����µ�
������������ ���ۼ������� �Ǵ��� ������ ���ݱ����� �ϸ�ȴ�
*/
#include <iostream>
#include <string>
using namespace std;

int len;
bool ok = false;

bool check(int node, string origin) {
	for (int i = 0; i < origin.length(); i++) {
		string temp = ""; // temp�� ������ 2��, 3��, 4��, n/2�� ���̱����� ���ڿ�
		for (int j = origin.length() - 2 - i; j < origin.length(); j++) {
			temp += origin[j];
		}
		if (temp.length() > origin.length() / 2) {
			break;
		}
		string com = ""; // com�� temp�� �ٷξ� 2��, 3��, 4��, n/2�� ���̱����� ���ڿ�
		for (int j = origin.length() - 2 - i - temp.length(); j < origin.length() - 2 - i; j++) {
			com += origin[j];
		}
		if (com == temp) { // com�� temp�� ������ ���ۼ���
			return false;
		}
	}
	return true;
}

void dfs(int node, string ans) {
	if (ok == true) { // ������ ���������� DFS Ż��
		return;
	}
	if (ans.length() == len) { // ������ ���������� �� ���
		cout << ans;
		ok = true;
		return;
	}
	for (int i = 1; i <= 3; i++) {
		if (i == node) { // �������� ���� �� ���°� ����
			continue;
		}
		if (check(i, ans + to_string(i)) == true) { // ���� ������ ���� ���ΰ� üũ
			dfs(i, ans + to_string(i));
		}
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> len;
	dfs(1, "1"); // ���� ���� ���ϱ� 1�� ����
	return 0;
}