#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m, l;
	cin >> n >> m >> l;
	vector<int> rest;
	int temp;
	rest.push_back(0);
	for (int i = 0; i < n; i++) {
		cin >> temp;
		rest.push_back(temp);
	}
	rest.push_back(l);
	sort(rest.begin(), rest.end());

	int left = 1;
	int right = l - 1;
	int mid = 0;
	while (left <= right) {
		mid = (left + right) / 2;
		int newRest = 0;
		for (int i = 1; i < rest.size(); i++) {
			int dist = rest[i] - rest[i - 1];
			newRest += dist / mid;
			if (dist%mid == 0) {
				newRest--;
			}
		}
		if (newRest > m) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	cout << left;
	return 0;
}