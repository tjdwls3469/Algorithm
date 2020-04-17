#include <iostream>
#include <queue>
using namespace std;

bool check[200002];
int ans[200002];

int main() {
	int subin;
	int sister;
	cin >> subin >> sister;
	queue<int> q;
	check[subin] = true;
	q.push(subin);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		int go = cur + 1;
		if (go <= 100000 && check[go] == false) {
			check[go] = true;
			q.push(go);
			ans[go] = ans[cur] + 1;
		}
		int back = cur - 1;
		if (back >= 0 && check[back] == false) {
			check[back] = true;
			q.push(back);
			ans[back] = ans[cur] + 1;
		}
		int telpo = cur * 2;
		if (telpo <= 200001 && check[telpo] == false) {
			check[telpo] = true;
			q.push(telpo);
			ans[telpo] = ans[cur] + 1;
		}
	}
	cout << ans[sister];
	return 0;
}