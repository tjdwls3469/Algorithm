#include <iostream>
#include <algorithm>
using namespace std;

int ary[1000];
int dist[1000];

int main() {
	int cnt;
	cin >> cnt;
	for (int i = 0; i < cnt; i++) {
		cin >> ary[i];
	}
	for (int i = 0; i < cnt; i++) {
		dist[i] = 1;
		for (int j = 0; j < i; j++) {
			if (ary[i] < ary[j] && dist[i] < dist[j] + 1) {
				dist[i] = dist[j] + 1;
			}
		}
	}
	cout << *max_element(dist, dist + cnt);
	return 0;
}