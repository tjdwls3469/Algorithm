#include <iostream>
#include <vector>
using namespace std;

int main() {
	int size;
	cin >> size;
	vector<vector<int>> num(4, vector<int>(4));
	vector<vector<long long>> ans(4, vector<long long>(4));
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cin >> num[i][j];
		}
	}
	ans[0][0] = 1;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			for (int k = 0; k < j; k++) {
				if (num[i][k] + k == j) {
					ans[i][j] += ans[i][k];
				}
			}
			for (int k = 0; k < i; k++) {
				if (num[k][j] + k == i) {
					ans[i][j] += ans[k][j];
				}
			}
		}
	}
	cout << ans[size - 1][size - 1];
	return 0;
}