#include <iostream>
#include <queue>
using namespace std;

int subin;
int sister;
int check[100001];
int ans[100001];
int from[100001];

void bfs(int start) {
	queue<int> q;
	check[start] = true;
	q.push(start);
	while (!q.empty()) {
		int node = q.front();
		if (node == sister) {
			break;
		}
		q.pop();
		int go = node + 1;
		if (go <= 100000 && check[go] == false) {
			check[go] = true;
			q.push(go);
			ans[go] = ans[node] + 1;
			from[go] = node;
		}
		int back = node - 1;
		if (back >= 0 && check[back] == false) {
			check[back] = true;
			q.push(back);
			ans[back] = ans[node] + 1;
			from[back] = node;
		}
		int telpo = node * 2;
		if (telpo <= 100000 && check[telpo] == false) {
			check[telpo] = true;
			q.push(telpo);
			ans[telpo] = ans[node] + 1;
			from[telpo] = node;
		}
	}
}

void solve(int subin, int sister) {
	if (subin != sister) {
		solve(subin, from[sister]);
	}
	cout << sister << ' ';
}

int main() {
	cin >> subin >> sister;
	bfs(subin);
	cout << ans[sister] << '\n';
	solve(subin, sister);
	return 0;
}