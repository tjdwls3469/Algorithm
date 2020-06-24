#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

struct cmp {
	bool operator() (vector<int> &x, vector<int> &y) {
		return x[1] > y[1];
	}
};

int solution(vector<vector<int>> jobs) {
	int ans = 0;
	int time = 0;
	int index = 0;
	int check = jobs.size();
	priority_queue<int, vector<vector<int>>, cmp> q;
	sort(jobs.begin(), jobs.end());
	while (check != 0) {
		for (int i = index; i < jobs.size(); i++) {
			if (jobs[i][0] <= time) {
				q.push({ jobs[i][0], jobs[i][1] });
				index = i + 1;
			}
			else {
				index = i;
				break;
			}
		}

		if (!q.empty()) {
			time += q.top()[1];
			ans += time - q.top()[0];
			q.pop();
			check--;
			continue;
		}

		time = jobs[index][0];
	}
	return ans / jobs.size();
}