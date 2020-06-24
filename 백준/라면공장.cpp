#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
	int ans = 0;
	priority_queue<int> q;
	int index = 0;
	for (int i = 0; i < k; i++) {
		if (dates[index] <= i) {
			q.push(supplies[index]);
			index++;
		}
		if (stock == 0) {
			stock += q.top();
			q.pop();
			ans++;
		}
		stock--;
	}
	return ans;
}