#include <string>
#include <vector>
#include <queue>

using namespace std;

int check[10];

int solution(vector<int> priorities, int location) {
	int ans = 0;
	queue<pair<int, int>> q;
	for (int i = 0; i < priorities.size(); i++) {
		check[priorities[i]]++;
		if (i == location) {
			q.push({ priorities[i], 1 });
		}
		else {
			q.push({ priorities[i], 0 });
		}
	}
	while (!q.empty()) {
		bool big = false;
		int cur = q.front().first;
		int key = q.front().second;
		q.pop();
		for (int i = cur + 1; i < 10; i++) {
			if (check[i] > 0) {
				big = true;
				break;
			}
		}
		if (big == true) {
			q.push({ cur, key });
		}
		else {
			ans++;
			check[cur]--;
			if (key == 1) {
				break;
			}
		}
	}
	return ans;
}