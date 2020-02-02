#include <iostream>
#include <queue>
using namespace std;

int subin;
int sister;
bool check[100001];
int ans[100001];
int cnt[100001];

void bfs(int start) {
	queue<int> q;
	check[start] = true;
	q.push(start);
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		int go = node + 1;
		if (go <= 100000 && check[go] == false) {
			check[go] = true;
			q.push(go);
			ans[go] = ans[node] + 1;
			cnt[go] = cnt[node];
		}
		else if (ans[go] == ans[node] + 1) {
			cnt[go] += cnt[node];
		}
		int back = node - 1;
		if (back >= 0 && check[back] == false) {
			check[back] = true;
			q.push(back);
			ans[back] = ans[node] + 1;
			cnt[back] = cnt[node];
		}
		else if (ans[back] == ans[node] + 1) {
			cnt[back] += cnt[node];
		}
		int telpo = node * 2;
		if (telpo <= 100000 && check[telpo] == false) {
			check[telpo] = true;
			q.push(telpo);
			ans[telpo] = ans[node] + 1;
			cnt[telpo] = cnt[node];
		}
		else if (ans[telpo] == ans[node] + 1) {
			cnt[telpo] += cnt[node];
		}
		if (go == sister || back == sister || telpo == sister) {
			break;
		}
	}
}

int main() {
	cin >> subin >> sister;
	cnt[subin] = 1;
	bfs(subin);
	cout << ans[sister] << '\n' << cnt[sister];
	return 0;
}