#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int testCnt;
	cin >> testCnt;
	for (int i = 0; i < testCnt; i++) {
		int cnt;
		int val;
		cin >> cnt;
		vector<int> num;
		vector<int> ans;
		for (int j = 0; j < cnt; j++) {
			cin >> val;
			num.push_back(val);
		}
		while (true) {
			sort(num.begin(), num.end());
			int temp = num[0] + num[1];
			ans.push_back(temp);
			num.push_back(temp);
			num.erase(num.begin(), num.begin() + 2);
			cout << "=====================" << '\n';
			for (int j = 0; j < num.size(); j++) {
				cout << num[j] << ' ';
			}
			cout << '\n';
			for (int j = 0; j < ans.size(); j++) {
				cout << ans[j] << ' ';
			}
			cout << '\n';
			cout << "=====================" << '\n';
			if (num.size() < 2) {
				break;
			}
		}
		int result = 0;
		for (int j = 0; j < ans.size(); j++) {
			result += ans[j];
		}
		cout << result << '\n';
	}
	return 0;
}