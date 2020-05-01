#include <iostream>
#include <algorithm>
using namespace std;

int ary[1000];
int inc[1000];
int red[1000];
int dist[1000];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int cnt;
	cin >> cnt;
	for (int i = 0; i < cnt; i++) {
		cin >> ary[i];
	}
	for (int i = 0; i < cnt; i++) {
		inc[i] = 1;
		for (int j = 0; j < i; j++) {
			if (ary[i] > ary[j] && inc[i] < inc[j] + 1) {
				inc[i] = inc[j] + 1;
			}
		}
	}
	for (int i = cnt - 1; i >= 0; i--) {
		for (int j = cnt - 1; j > i; j--) {
			if (ary[i] > ary[j] && red[i] < red[j] + 1) {
				red[i] = red[j] + 1;
			}
		}
		dist[i] = inc[i] + red[i];
	}
	cout << *max_element(dist, dist + cnt);
	return 0;
}