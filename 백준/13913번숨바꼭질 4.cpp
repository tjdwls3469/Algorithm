/*
�ð��̶� ��� �Դ��� ����ϸ鼭 BFS����
*/
#include <iostream>
#include <queue>
using namespace std;

int map[200001];
bool check[200001];
int from[200001]; // ���� �ε����� ��� �Դ����� ������ ������ �ִ� �迭
int subin;
int sister;

void pathPrint(int start, int end) {
	if (start != end) {
		pathPrint(start, from[end]);
	}
	cout << end << ' ';
}

void bfs(int point) {
	queue<pair<int, int>> q; // first - ��ġ, second - �ð�
	check[point] = true;
	q.push({ point,0 });
	while (!q.empty()) {
		int cur = q.front().first;
		int time = q.front().second;
		q.pop();
		if (cur == sister) { // ����� ������ ������
			cout << time << '\n';
			pathPrint(subin, cur); // ��� ������ִ� �Լ�
			break;
		}

		int back = cur - 1;
		if (back >= 0 && check[back] == false) {
			check[back] = true;
			q.push({ back, time + 1 });
			from[back] = cur; // back�� cur���� ����
		}

		int go = cur + 1;
		if (go <= 200000 && check[go] == false) {
			check[go] = true;
			q.push({ go, time + 1 });
			from[go] = cur; // go�� cur���� ����
		}

		int jump = cur * 2;
		if (jump <= 200000 && check[jump] == false) {
			check[jump] = true;
			q.push({ jump,time + 1 });
			from[jump] = cur; // jump�� cur���� ����
		}
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> subin >> sister;
	from[subin] = subin; // from[subin] == subin �ε����� ���� ������ �����ų����
	bfs(subin);
	return 0;
}