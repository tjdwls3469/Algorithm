#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> ans;
	queue<int> q;
	for (int i = 0; i < progresses.size(); i++) {
		if ((100 - progresses[i]) % speeds[i] == 0) {
			q.push((100 - progresses[i]) / speeds[i]);
		}
		else {
			q.push((100 - progresses[i]) / speeds[i] + 1);
		}
	}
	while (!q.empty()) {
		int cnt = 1;
		int cur = q.front();
		q.pop();
		while (!q.empty() && q.front() <= cur) {
			q.pop();
			cnt++;
		}
		ans.push_back(cnt);
	}
	return ans;
}