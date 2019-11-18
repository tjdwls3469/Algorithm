#include <iostream>
using namespace std;

int main() {
	int cnt;
	cin >> cnt;
	for (int i = 0; i < cnt; i++) {
		int m;
		int n;
		int x;
		int y;
		cin >> m >> n >> x >> y;
		x = x - 1;
		y = y - 1;
		bool result = false;
		for (int j = x; j < n*m; j += m) {
			if (j%n == y) {
				cout << j + 1 << '\n';
				result = true;
				break;
			}
		}
		if (result == false) {
			cout << -1 << '\n';
		}
	}
	return 0;
}