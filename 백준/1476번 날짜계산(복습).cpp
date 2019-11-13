#include <iostream>
using namespace std;

int main() {
	int earthNum;
	int sunNum;
	int moonNum;
	int earth;
	int sun;
	int moon;
	int result = 0;
	earth = sun = moon = 1;
	cin >> earthNum >> sunNum >> moonNum;
	while (true) {
		result++;
		if (earth == earthNum && sun == sunNum && moon == moonNum) {
			cout << result;
			break;
		}
		earth++;
		sun++;
		moon++;
		if (earth == 16) {
			earth = 1;
		}
		if (sun == 29) {
			sun = 1;
		}
		if (moon == 20) {
			moon = 1;
		}
	}

	return 0;
}