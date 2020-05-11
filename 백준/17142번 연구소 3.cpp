/*
�����ҿ� �����ϴ� ���̷������� M���� ��� BFS������ ������
*/
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int n;
int cnt;
int map[50][50];
int temp[50][50];
bool check[50][50];
int dx[] = { 0, -1, 0, 1 };
int dy[] = { -1, 0, 1, 0 };
vector<pair<int, int>> virus;
vector<pair<int, int>> choice;
int ans = -1;

void bfs(vector<pair<int, int>> &choice) {
	memset(check, false, sizeof(check));
	memcpy(temp, map, sizeof(map));
	// ť���� (x,y)��ǥ�� �ð� ����
	queue<pair<pair<int, int>, int>> q;
	// choice���Ϳ��� ������ ��ü�� ���̷����� M���� �������
	for (int i = 0; i < choice.size(); i++) {
		int x = choice[i].first;
		int y = choice[i].second;
		check[x][y] = true;
		// BFS�� ������ǥ�̱⶧���� �ð��� 0���� ����
		q.push({ {x, y}, 0 });
	}
	while (!q.empty()) {
		int fx = q.front().first.first;
		int fy = q.front().first.second;
		int d = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = fx + dx[i];
			int ny = fy + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
				// ��ĭ�̸� 
				if (temp[nx][ny] == 0 && check[nx][ny] == false) {
					check[nx][ny] = true;
					q.push({ {nx, ny}, d + 1 });
					temp[nx][ny] = d + 1; // temp�� �ð��� ������Ʈ
				}
				// ��Ȱ��ȭ ���̷����̸�
				if (temp[nx][ny] == -2 && check[nx][ny] == false) {
					check[nx][ny] = true;
					q.push({ {nx, ny}, d + 1});
				}
			}
		}
	}
}

// ���õ� M���� ���̷����� choice���Ϳ� �ִ´�
void selectCnt(int index, int select) {
	if (select == cnt) {
		// M���� ���̷������� ���۵Ǵ� BFS
		bfs(choice);
		int max = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				// BFS�� ���� �� �� temp��� �����ҿ� �ð��� ������Ʈ �ȴ�
				// BFS���� �� temp�� 0�� �����ϸ� 
				// ��� �� ĭ�� ���̷����� �۶߸� �� ���� �����
				if (temp[i][j] == 0) {
					return;
				}
				// BFS���� �� �ɸ� �ð��� max������ ����
				if (temp[i][j] > max) {
					max = temp[i][j];
				}
			}
		}
		// ans == -1�� BFS�� ó�� ����Ǿ�����
		// max���� BFS�ѹ� ���� �� ���������� �ɸ� �ð�
		// max���� ans���� ������ ans�� ������Ʈ
		if (ans == -1 || max < ans) {
			ans = max;
		}
		return;
	}
	if (index >= virus.size()) {
		return;
	}
	choice.push_back(make_pair(virus[index].first, virus[index].second));
	selectCnt(index + 1, select + 1);
	choice.pop_back();
	selectCnt(index + 1, select);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> cnt;
	// ���� -1, ���̷����� -2�� �ٲ��ְ� 
	// �����ҿ� �ִ� ��� ���̷����� ��ǥ�� virus���Ϳ� �־��ش�
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) {
				map[i][j] = -1;
			}
			if (map[i][j] == 2) {
				virus.push_back(make_pair(i, j));
				map[i][j] = -2;
			}
		}
	}
	// �ʿ� �ִ� ���̷����� M���� �����ؼ� BFS������ �Լ�
	selectCnt(0, 0);
	cout << ans;
	return 0;
}