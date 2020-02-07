#include <iostream>
using namespace std;

int main() {
	int cnt;
	int m, n, x, y;
	cin >> cnt;
	for (int i = 0; i < cnt; i++) {
		cin >> m >> n >> x >> y;
		x -= 1;
		y -= 1;
		bool check = false;
		for (int j = x; j < (n*m); j += m) {
			if ((j%n) == y) {
				cout << j + 1 << '\n';
				check = true;
				break;
			}
		}
		if (check == false) {
			cout << -1 << '\n';
		}
	}
	return 0;
}