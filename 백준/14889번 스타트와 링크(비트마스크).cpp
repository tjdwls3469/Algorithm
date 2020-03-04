#include <iostream>
#include <vector>
using namespace std;

int main() {
	int size;
	cin >> size;
	vector<vector<int>> val(size, vector<int>(size));
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cin >> val[i][j];
		}
	}
	int ans = -1;
	for (int i = 0; i < (1 << size); i++) {
		vector<int> start;
		vector<int> link;
		for (int j = 0; j < size; j++) {
			if (i&(1 << j)) {
				start.push_back(j);
			}
			else {
				link.push_back(j);
			}
		}
		if (start.size() != size / 2) {
			continue;
		}
		int startVal = 0;
		int linkVal = 0;
		for (int j = 0; j < size / 2; j++) {
			for (int k = 0; k < size / 2; k++) {
				if (j == k) {
					continue;
				}
				startVal += val[start[j]][start[k]];
				linkVal += val[link[j]][link[k]];
			}
		}
		int diff = startVal - linkVal;
		if (diff < 0) {
			diff = -diff;
		}
		if (ans == -1 || diff < ans) {
			ans = diff;
		}
	}
	cout << ans;
	return 0;
}