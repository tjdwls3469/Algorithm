#include <iostream>
using namespace std;

int ary[1000];
int dist[1000];
int from[1000];

void solve(int index) {
	if (index == from[index]) {
		cout << ary[index] << ' ';
		return;
	}
	solve(from[index]);
	cout << ary[index] << ' ';
}

int main() {
	int cnt;
	cin >> cnt;
	for (int i = 0; i < cnt; i++) {
		cin >> ary[i];
	}
	for (int i = 0; i < cnt; i++) {
		dist[i] = 1;
		from[i] = i;
		for (int j = 0; j < i; j++) {
			if (ary[i] > ary[j] && dist[i] < dist[j] + 1) {
				dist[i] = dist[j] + 1;
				from[i] = j;
			}
		}
	}
	int max = 0;
	int index = 0;
	for (int i = 0; i < cnt; i++) {
		if (dist[i] > max) {
			max = dist[i];
			index = i;
		}
	}
	cout << max << '\n';
	solve(index);
	return 0;
}