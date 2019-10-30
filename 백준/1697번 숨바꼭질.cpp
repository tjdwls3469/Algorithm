#include <iostream>
#include <queue>
using namespace std;

int n;
int k;
int result[200001];
bool check[200001];
int path;

void bfs(int x) {
	queue<int> q;
	q.push(x);
	check[x] = true;
	result[x] = path + 1;
	//result[x] = 0;
	
	while (!q.empty()) {
		x = q.front();
		q.pop();
		int minus = x - 1;
		if (minus >= 0 && check[minus] == false) {
			q.push(minus);
			check[minus] = true;
			path = result[x];
			result[minus] = result[x] + 1;
		}

		int plus = x + 1;
		if (plus < 200000 && check[plus] == false) {
			q.push(plus);
			check[plus] = true;
			path = result[x];
			result[plus] = result[x] + 1;
		}
		int mul = x * 2;
		if (mul < 200000 && check[mul] == false) {
			q.push(mul);
			check[mul] = true;
			path = result[x];
			result[mul] = result[x] + 1;
		}
	}
}

int main() {
	cin >> n >> k;

	for (int i = n; i <= k; i++) {
		if (check[i] == false) {
			bfs(i);
		}
	}

	cout << result[k] - 1;
	return 0;
}