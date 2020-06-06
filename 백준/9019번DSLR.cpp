/*
그냥 문제 주어진대로 구현하자
*/
#include <iostream>
#include <cstring>
#include <queue>
#include <string>
using namespace std;

int start;
int goal;
bool check[10000];
int from[10000];
char how[10000];

void bfs() {
	check[start] = true;
	queue<int> q;
	q.push(start);
	from[start] = start;
	while (!q.empty()) {
		int fx = q.front();
		q.pop();
		if (fx == goal) {
			break;
		}
		int d = (fx * 2) % 10000;
		if(check[d] == false){
			check[d] = true;
			from[d] = fx;
			how[d] = 'D';
			q.push(d);
		}
		int s = fx - 1;
		if (s < 0) {
			s = 9999;
		}
		if(check[s] == false){
			check[s] = true;
			from[s] = fx;
			how[s] = 'S';
			q.push(s);
		}
		int l = (fx % 1000) * 10 + fx / 1000;
		if(check[l] == false){
			check[l] = true;
			from[l] = fx;
			how[l] = 'L';
			q.push(l);
		}
		int r = (fx / 10) + (fx % 10) * 1000;
		if(check[r] == false){
			check[r] = true;
			from[r] = fx;
			how[r] = 'R';
			q.push(r);
		}
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int tc;
	cin >> tc;
	for (int i = 0; i < tc; i++) {
		memset(check, false, sizeof(check));
		cin >> start >> goal;
		bfs();
		int temp = goal;
		string ans = "";
		ans += how[goal];
		while (true) {
			if (start == from[temp]) {
				break;
			}
			int pre = from[temp];
			ans += how[pre];
			temp = pre;
		}
		for (int j = ans.length() - 1; j >= 0; j--) {
			cout << ans[j];
		}
		cout << '\n';
	}
	return 0;
}