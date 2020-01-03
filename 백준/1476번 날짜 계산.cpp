#include <iostream>
using namespace std;

int main() {
	int e;
	int s;
	int m;
	int earth;
	int sun;
	int moon;
	int year = 0;
	earth = sun = moon = 0;
	cin >> e >> s >> m;
	while (true) {
		year++;
		earth++;
		if (earth == 16) {
			earth = 1;
		}
		sun++;
		if (sun == 29) {
			sun = 1;
		}
		moon++;
		if (moon == 20) {
			moon = 1;
		}
		if (earth == e && sun == s && moon == m) {
			cout << year;
			break;
		}
	}
	return 0;
}