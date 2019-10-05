#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int cnt;
	vector<int> v;
	int result = 0;
	cin >> cnt;

	for (int i = 0; i < cnt; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}

	sort(v.begin(), v.end());
	for (int i = 0; i < cnt ; i++) {
		for (int j = 0; j <= i; j++) {
			result += v[j];
		}
	}
	cout << result;

	return 0;
}