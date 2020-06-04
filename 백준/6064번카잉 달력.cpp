/*
그냥 아무생각없이 하면 시간초과뜬다
첫번째 해가 <1,1>이 아니라 <0,0>으로 시작해서
k번째 해는 <k%m,k%n>이 된다
x가 k%m, y가 k%n이 되면 정답
x부터 시작해서 m씩 증가하면서 k%n이 y가 되는지 찾는다
*/
#include <iostream>
using namespace std;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int tc;
	int m, n, x, y;
	cin >> tc;
	for (int i = 0; i < tc; i++) {
		bool check = false;
		cin >> m >> n >> x >> y;
		x--;
		y--;
		for (int j = x; j < m*n; j += m) {
			if (j%n == y) {
				check = true;
				cout << j + 1 << '\n';
				break;
			}
		}
		if (check == false) {
			cout << -1 << '\n';
		}
	}
	return 0;
}