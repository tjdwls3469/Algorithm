/*
시간이랑 어디서 왔는지 계산하면서 BFS돌림
*/
#include <iostream>
#include <queue>
using namespace std;

int map[200001];
bool check[200001];
int from[200001]; // 현재 인덱스가 어디서 왔는지를 값으로 가지고 있는 배열
int subin;
int sister;

void pathPrint(int start, int end) {
	if (start != end) {
		pathPrint(start, from[end]);
	}
	cout << end << ' ';
}

void bfs(int point) {
	queue<pair<int, int>> q; // first - 위치, second - 시간
	check[point] = true;
	q.push({ point,0 });
	while (!q.empty()) {
		int cur = q.front().first;
		int time = q.front().second;
		q.pop();
		if (cur == sister) { // 수빈과 동생이 만나면
			cout << time << '\n';
			pathPrint(subin, cur); // 경로 출력해주는 함수
			break;
		}

		int back = cur - 1;
		if (back >= 0 && check[back] == false) {
			check[back] = true;
			q.push({ back, time + 1 });
			from[back] = cur; // back은 cur에서 왔음
		}

		int go = cur + 1;
		if (go <= 200000 && check[go] == false) {
			check[go] = true;
			q.push({ go, time + 1 });
			from[go] = cur; // go는 cur에서 왔음
		}

		int jump = cur * 2;
		if (jump <= 200000 && check[jump] == false) {
			check[jump] = true;
			q.push({ jump,time + 1 });
			from[jump] = cur; // jump는 cur에서 왔음
		}
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> subin >> sister;
	from[subin] = subin; // from[subin] == subin 인덱스와 값이 같으면 종료시킬꺼임
	bfs(subin);
	return 0;
}