#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int ary[100000][3];
int d[2][3]; // 메모리 제한때문에 d[100000][3] 으로 선언 못함

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int cnt;
	cin >> cnt;
	for (int i = 0; i < cnt; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> ary[i][j];
		}
	}
	for (int i = 0; i < 3; i++) {
		d[0][i] = ary[0][i];
	}
	for (int i = 1; i < cnt; i++) {
		d[1][0] += max(d[0][0], d[0][1]) + ary[i][0];
		d[1][2] += max(d[0][2], d[0][1]) + ary[i][2];
		d[1][1] += max(max(d[0][0], d[0][1]), d[0][2]) + ary[i][1];

		d[0][0] = d[1][0];
		d[0][1] = d[1][1];
		d[0][2] = d[1][2];

		d[1][0] = 0;
		d[1][1] = 0;
		d[1][2] = 0;
	}
	cout << max(max(d[0][0], d[0][1]), d[0][2]) << ' ';
	memset(d, 0, sizeof(d));
	for (int i = 0; i < 3; i++) {
		d[0][i] = ary[0][i];
	}
	for (int i = 1; i < cnt; i++) {
		d[1][0] += min(d[0][0], d[0][1]) + ary[i][0];
		d[1][2] += min(d[0][2], d[0][1]) + ary[i][2];
		d[1][1] += min(min(d[0][0], d[0][1]), d[0][2]) + ary[i][1];

		d[0][0] = d[1][0];
		d[0][1] = d[1][1];
		d[0][2] = d[1][2];

		d[1][0] = 0;
		d[1][1] = 0;
		d[1][2] = 0;
	}
	cout << min(min(d[0][0], d[0][1]), d[0][2]);
	return 0;
}