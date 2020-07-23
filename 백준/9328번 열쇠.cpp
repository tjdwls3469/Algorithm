#include <iostream>
#include <cstring>
#include <string>
#include <queue>
using namespace std;

/*
	테스트 케이스 입력받는다
	테스트 케이스만큼 while문을 돌린다
	row, col 입력받는다
	row x col 만큼 for문 돌려서 map 입력받는다
	key 입력받는다
	key 배열에 체크한다
		(1,1)부터 4방향 탐색하면서
		'.'이면 큐에 넣는다
		'$'이면 정답+1 하고 큐에 넣는다
		'A' ~ 'Z'일때 키가 존재하면 큐에 넣는다
					  키가 없으면 도어큐에 넣는다
		'a' ~ 'z'이면 큐에 넣고 키가 처음 발견된거면
		key 배열에 체크하고 key로 열수있는 문에 해당하는 도어큐
		안에 있는 모든 좌표를 pop하여 큐에 넣어준다
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
	cin >> tc;		// 테스트 케이스 입력받는다
	int row = 0;
	int col = 0;
	while (tc--) {		// 테스트 케이스만큼 while문을 돌린다
		cin >> row >> col;		// row, col 입력받는다
		for (int i = 2; i < row + 2; i++) {		// row x col 만큼 for문 돌려서 map 입력받는다
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
		cin >> keyStr;		// key 입력받는다
		if (keyStr[0] != '0') {
			for (int i = 0; i < keyStr.length(); i++) {
				key[keyStr[i] - 'a'] = true;		// key 배열에 체크한다
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
			for (int k = 0; k < 4; k++) {		// (1,1)부터 4방향 탐색하면서
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
				if (w == '.') {		// '.'이면 큐에 넣는다
					q.push({ nx, ny });
				}
				else if (w == '$') {		// '$'이면 정답+1 하고 큐에 넣는다
					ans += 1;
					q.push({ nx, ny });
				}
				else if (w >= 'A' && w <= 'Z') {		// 'A' ~ 'Z'일때 키가 존재하면 큐에 넣는다
					if (key[w - 'A']) {
						q.push({ nx, ny });
					}
					else {
						door[w - 'A'].push({ nx, ny });		// 키가 없으면 도어큐에 넣는다
					}
				}
				else if (w >= 'a' && w <= 'z') {		// 'a' ~ 'z'이면 큐에 넣고 키가 처음 발견된거면
					q.push({ nx, ny });
					if (!key[w - 'a']) {
						key[w - 'a'] = true;
						while (!door[w - 'a'].empty()) {		// key 배열에 체크하고 key로 열수있는 문에 해당하는 도어큐
							q.push(door[w - 'a'].front());		// 안에 있는 모든 좌표를 pop하여 큐에 넣어준다
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