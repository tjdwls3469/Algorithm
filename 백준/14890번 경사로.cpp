#include <iostream>
#include <vector>
using namespace std;

int main() {
	int size;
	int slopeLen;
	int ans = 0;
	cin >> size >> slopeLen;
	vector<vector<int>> map(size, vector<int>(size));
	vector<vector<bool>> check(size, vector<bool>(size));
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < size; i++) {
		int num = map[i][0];
		bool ok = true;
		for (int j = 1; j < size; j++) {
			if (map[i][j] == num) {
				continue;
			}
			if (map[i][j] == num - 1) {
				if (j + slopeLen - 1 >= size) {
					ok = false;
					break;
				}
				for (int k = j; k <= j + slopeLen - 1; k++) {
					if (map[i][k] != num - 1 || check[i][k] == true) {
						ok = false;
						break;
					}
				}
				if (ok == false) {
					break;
				}
				num = map[i][j];
				for (int k = j; k <= j + slopeLen - 1; k++) {
					check[i][k] = true;
				}
			}
			else if (map[i][j] == num + 1) {
				if (j - slopeLen < 0) {
					ok = false;
					break;
				}
				for (int k = j - 1; k >= j - slopeLen; k--) {
					if (map[i][k] != num || check[i][k] == true) {
						ok = false;
						break;
					}
				}
				if (ok == false) {
					break;
				}
				num = map[i][j];
				for (int k = j - 1; k >= j - slopeLen; k--) {
					check[i][k] = true;
				}
			}
			else {
				ok = false;
				break;
			}
		}
		if (ok == true) {
			ans++;
		}
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			check[i][j] = false;
		}
	}
	for (int i = 0; i < size; i++) {
		int num = map[0][i];
		bool ok = true;
		for (int j = 1; j < size; j++) {
			if (map[j][i] == num) {
				continue;
			}
			if (map[j][i] == num - 1) {
				if (j + slopeLen - 1 >= size) {
					ok = false;
					break;
				}
				for (int k = j; k <= j + slopeLen - 1; k++) {
					if (map[k][i] != num - 1 || check[k][i] == true) {
						ok = false;
						break;
					}
				}
				if (ok == false) {
					break;
				}
				num = map[j][i];
				for (int k = j; k <= j + slopeLen - 1; k++) {
					check[k][i] = true;
				}
			}
			else if (map[j][i] == num + 1) {
				if (j - slopeLen < 0) {
					ok = false;
					break;
				}
				for (int k = j - 1; k >= j - slopeLen; k--) {
					if (map[k][i] != num || check[k][i] == true) {
						ok = false;
						break;
					}
				}
				if (ok == false) {
					break;
				}
				num = map[j][i];
				for (int k = j - 1; k >= j - slopeLen; k--) {
					check[k][i] = true;
				}
			}
			else {
				ok = false;
				break;
			}
		}
		if (ok == true) {
			ans++;
		}
	}
	cout << ans;
	return 0;
}