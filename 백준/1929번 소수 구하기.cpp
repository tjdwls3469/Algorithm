#include <iostream>
using namespace std;

int check[1000001];

int main() {
	int x;
	int y;
	cin >> x >> y;
	check[0] = check[1] = true;
	for (int i = 2; i <= y; i++) {
		if (check[i] == false) {
			for (int j = i * 2; j <= y; j += i) {
				check[j] = true;
			}
		}
	}
	for (int i = x; i <= y; i++) {
		if (check[i] == false) {
			cout << i << '\n';
		}
	}
	return 0;
}