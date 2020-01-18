#include <iostream>
#include <queue>
using namespace std;

int subin;
int sister;
bool check[200001];
int ans[200001];

int main() {
	cin >> subin >> sister;
	queue<int> q;
	check[subin] = true;
	q.push(subin);
	while (!q.empty()) {
		int fx = q.front();
		q.pop();
		int telpo = fx * 2;
		if (telpo <= 100000 && check[telpo] == false) {
			check[telpo] = true;
			q.push(telpo);
			ans[telpo] = ans[fx];
		}
		int back = fx - 1;
		if (back >= 0 && check[back] == false) {
			check[back] = true;
			q.push(back);
			ans[back] = ans[fx] + 1;
		}
		int go = fx + 1;
		if (go <= 100000 && check[go] == false) {
			check[go] = true;
			q.push(go);
			ans[go] = ans[fx] + 1;
		}
		if (back == sister || go == sister || telpo == sister) {
			cout << ans[sister];
			break;
		}
	}
	return 0;
}