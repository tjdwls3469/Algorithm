#include <iostream>
#include <cstring>
#include <string>
#include <queue>
using namespace std;

/*
	�׽�Ʈ ���̽� �Է¹޴´�
	�׽�Ʈ ���̽���ŭ while���� ������
	row, col �Է¹޴´�
	row x col ��ŭ for�� ������ map �Է¹޴´�
	key �Է¹޴´�
	key �迭�� üũ�Ѵ�
		(1,1)���� 4���� Ž���ϸ鼭
		'.'�̸� ť�� �ִ´�
		'$'�̸� ����+1 �ϰ� ť�� �ִ´�
		'A' ~ 'Z'�϶� Ű�� �����ϸ� ť�� �ִ´�
					  Ű�� ������ ����ť�� �ִ´�
		'a' ~ 'z'�̸� ť�� �ְ� Ű�� ó�� �߰ߵȰŸ�
		key �迭�� üũ�ϰ� key�� �����ִ� ���� �ش��ϴ� ����ť
		�ȿ� �ִ� ��� ��ǥ�� pop�Ͽ� ť�� �־��ش�
*/
char map[104][104];
bool check[104][104];
bool key[26];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int tc;
	cin >> tc;		// �׽�Ʈ ���̽� �Է¹޴´�
	int row = 0;
	int col = 0;
	while (tc--) {		// �׽�Ʈ ���̽���ŭ while���� ������
		cin >> row >> col;		// row, col �Է¹޴´�
		for (int i = 2; i < row + 2; i++) {		// row x col ��ŭ for�� ������ map �Է¹޴´�
			cin >> map[i] + 2;
		}
		row += 4;
		col += 4;
		for (int i = 0; i < row; i++) {
			map[i][0] = '*';
			map[i][1] = '.';
			map[i][col - 2] = '.';
			map[i][col - 1] = '*';
		}
		for (int i = 1; i < col-1; i++) {
			map[0][i] = '*';
			map[1][i] = '.';
			map[row - 2][i] = '.';
			map[row - 1][i] = '*';
		}

		memset(key, false, sizeof(key));
		string keyStr = "";
		cin >> keyStr;		// key �Է¹޴´�
		if (keyStr[0] != '0') {
			for (int i = 0; i < keyStr.length(); i++) {
				key[keyStr[i] - 'a'] = true;		// key �迭�� üũ�Ѵ�
			}
		}

		int ans = 0;
		memset(check, false, sizeof(check));
		queue<pair<int, int>> q;
		queue<pair<int, int>> door[26];
		q.push({1, 1});
		check[1][1] = true;
		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			for (int k = 0; k < 4; k++) {		// (1,1)���� 4���� Ž���ϸ鼭
				int nx = x + dx[k];
				int ny = y + dy[k];
				if (check[nx][ny]) {
					continue;
				}
				char w = map[nx][ny];
				if (w == '*') {
					continue;
				}
				check[nx][ny] = true;
				if (w == '.') {		// '.'�̸� ť�� �ִ´�
					q.push({ nx, ny });
				}
				else if (w == '$') {		// '$'�̸� ����+1 �ϰ� ť�� �ִ´�
					ans += 1;
					q.push({ nx, ny });
				}
				else if (w >= 'A' && w <= 'Z') {		// 'A' ~ 'Z'�϶� Ű�� �����ϸ� ť�� �ִ´�
					if (key[w - 'A']) {
						q.push({ nx, ny });
					}
					else {
						door[w - 'A'].push({ nx, ny });		// Ű�� ������ ����ť�� �ִ´�
					}
				}
				else if (w >= 'a' && w <= 'z') {		// 'a' ~ 'z'�̸� ť�� �ְ� Ű�� ó�� �߰ߵȰŸ�
					q.push({ nx, ny });
					if (!key[w - 'a']) {
						key[w - 'a'] = true;
						while (!door[w - 'a'].empty()) {		// key �迭�� üũ�ϰ� key�� �����ִ� ���� �ش��ϴ� ����ť
							q.push(door[w - 'a'].front());		// �ȿ� �ִ� ��� ��ǥ�� pop�Ͽ� ť�� �־��ش�
							door[w - 'a'].pop();
						}
					}
				}
			}
		}
		cout << ans << '\n';
	}	// end of while
	return 0;
}	// end of main