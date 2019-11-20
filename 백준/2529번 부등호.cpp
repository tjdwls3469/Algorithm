#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int cnt;
	cin >> cnt;
	vector<char> sign(cnt);
	vector<int> minAry(cnt + 1);
	vector<int> maxAry(cnt + 1);
	for (int i = 0; i < cnt; i++) {
		cin >> sign[i];
	}
	for (int i = 0; i <= cnt; i++) {
		minAry[i] = i;
		maxAry[i] = 9 - i;
	}
	int max = 0;
	int min = 999999999;
	for (int i = 0; i < cnt; i++) {
		if (sign[i] == '<') {
			minAry[i]
		}
		else {
		
		}
	}


	return 0;
}