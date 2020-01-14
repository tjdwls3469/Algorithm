#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int wage[11][11];
long long ans = LLONG_MAX;

int main() {
	int cnt;
	cin >> cnt;
	vector<int> city(cnt);
	for (int i = 0; i < cnt; i++) {
		city[i] = i + 1;
	}
	for (int i = 1; i <= cnt; i++) {
		for (int j = 1; j <= cnt; j++) {
			cin >> wage[i][j];
		}
	}
	do {
		long long sum = 0;
		bool zero = false;
		for (int i = 0; i < cnt-1; i++) {
			if(wage[city[i]][city[i+1]] == 0){
				zero = true;
				break;
			}
			else {
				sum += wage[city[i]][city[i + 1]];
			}
		}
		if (zero == false && wage[city[cnt-1]][city[0]] != 0) {
			sum += wage[city[cnt - 1]][city[0]];
			if (sum < ans) {
				ans = sum;
			}
		}
	} while (next_permutation(city.begin(), city.end()));
	cout << ans;
	return 0;
}