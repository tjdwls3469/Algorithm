#pragma warning(disable:4996)
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
#include <string>
using namespace std;

string map[2];

int main() {
	int col;
	int k;
	cin >> col >> k;
	vector<vector<int>> time(2, vector<int>(col));
	for (int i = 0; i < 2; i++) {
		cin >> map[i];
	}
	queue<pair<int, int>> q;
	q.push(make_pair(0, 0));
	time[0][0] = 0;
	while (!q.empty()) {
		int fx;
		int fy;
		tie(fx, fy) = q.front();
		q.pop();
		if (fy + 1 == col || fy + k >= col) {
			cout << 1;
			return 0;
		}
		if (map[fx][fy + 1] == '1') {
			q.push(make_pair(fx, fy + 1));
			time[fx][fy + 1] = time[fx][fy] + 1;
		}
		if (fy - 1 > time[fx][fy] && map[fx][fy - 1] == '1') {
			q.push(make_pair(fx, fy - 1));
			time[fx][fy - 1] = time[fx][fy] + 1;
		}
		if (fx == 0 && map[fx + 1][fy + k] == '1') {
			q.push(make_pair(fx + 1, fy + k));
			time[fx + 1][fy + k] = time[fx][fy] + 1;
		}
		else if (fx == 1 && map[fx - 1][fy + k] == '1') {
			q.push(make_pair(fx - 1, fy + k));
			time[fx - 1][fy + k] = time[fx][fy] + 1;
		}
	}
	cout << 0;
	return 0;
}