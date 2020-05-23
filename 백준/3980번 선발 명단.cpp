#include <iostream>
#include <algorithm>
using namespace std;

int map[11][11];
int ans[11][11];
bool check[11];

int main() {
	int tc;
	cin >> tc;
	for (int z = 0; z < tc; z++) {
		for (int i = 0; i < 11; i++) {
			for (int j = 0; j < 11; j++) {
				cin >> map[i][j];
			}
		}
		for (int i = 0; i < 11; i++) {
			ans[0][i] = map[i][0];
		}
		for (int i = 1; i < 11; i++) {
			for (int j = 0; j < 11; j++) {
				int max = -1;
				for (int k = 0; k < 11; k++) {
					if (j != k) {
						if (max == -1 || ans[i - 1][k] > max) {
							max = ans[i - 1][k];
						}
					}
				}
				ans[i][j] = max + map[j][i];
			}
		}
	}
	int result = -1;
	for (int i = 0; i < 11; i++) {
		if (result == -1 || ans[10][i] > result) {
			result = ans[10][i];
		}
	}
	cout << result;
	return 0;
}