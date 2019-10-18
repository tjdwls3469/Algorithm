#include <iostream>
using namespace std;

int main() {
	int E;
	int S;
	int M;
	int e;
	int s;
	int m;
	e = s = m = 1;
	cin >> E >> S >> M;

	for (int i = 1;; i++) {
		if (e == E && s == S && m == M) {
			cout << i;
			break;
		}
		e++;
		s++;
		m++;
		if (e == 16) {
			e = 1;
		}
		if (s == 29) {
			s = 1;
		}
		if (m == 20) {
			m = 1;
		}
	}

	return 0;
}