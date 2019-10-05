#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int cnt;
	vector<int> weight;
	int max = 0;
	int temp = 0;

	cin >> cnt;

	for (int i = 0; i < cnt; i++) {
		int x;
		cin >> x;
		weight.push_back(x);
	}

	sort(weight.begin(), weight.end(), greater<int>());

	for (int i = 0; i < cnt; i++) {
		temp = weight[i] * (i+1);
		if (temp > max) {
			max = temp;
		}
	}

	cout << max;
	
	return 0;
}