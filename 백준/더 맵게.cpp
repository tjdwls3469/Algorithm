#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
	int ans = 0;
	priority_queue<int, vector<int>, greater<int>> q;
	for (int i = 0; i < scoville.size(); i++) {
		q.push(scoville[i]);
	}
	while (q.top() < K) {
		if (q.size() < 2) {
			return -1;
		}
		int one = q.top();
		q.pop();
		int two = q.top();
		q.pop();
		int newFood = one + two * 2;
		q.push(newFood);
		ans++;
	}
	return ans;
}