#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int cnt;
	cin >> cnt;
	vector<int> ary;
	ary.push_back(0);
	for (int i = 1; i <= cnt; i++) {
		int val;
		cin >> val;
		if (val > ary.back()) {
			ary.push_back(val);
		}
		else {
			auto temp = lower_bound(ary.begin(), ary.end(), val);
			*temp = val;
		}
	}
	cout << ary.size() - 1;
	return 0;
}