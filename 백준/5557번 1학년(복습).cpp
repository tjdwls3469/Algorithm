#include <iostream>
#include <vector>
using namespace std;

int main() {
	int cnt;
	cin >> cnt;
	vector<int> num(cnt);
	for (int i = 0; i < cnt; i++) {
		cin >> num[i];
	}
	vector<vector<int>> ans;
	vector<int> first;
	first.push_back(num[0]);
	ans.push_back(first);
	for (int i = 1; i < cnt; i++) {
		bool ok = false;
		for (int j = 0; j < ans[i - 1].size(); j++) {
			if (ans[i - 1][j] + num[j] <= 20) {
				if (ans.size() == i - 1) {

				}
			}
			if (ans[i - 1][j] - num[j] >= 0) {

			}
		}
	}
}