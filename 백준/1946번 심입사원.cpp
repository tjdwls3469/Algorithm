#include <iostream>
#include <vector>
using namespace std;

int main() {
	int tc;
	cin >> tc;
	for (int i = 0; i < tc; i++) {
		int cnt;
		cin >> cnt;
		vector<int> doc(cnt);
		vector<int> inter(cnt);
		for (int j = 0; j < cnt; j++) {
			cin >> doc[j] >> inter[j];
		}
		int ans = 0;
		for (int j = 0; j < cnt; j++) {
			for (int k = j + 1; k < cnt; k++) {
				if (doc[j] < doc[k] && inter[j] < inter[k]) {
					ans++;
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}