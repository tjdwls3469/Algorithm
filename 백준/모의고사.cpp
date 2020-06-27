#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
	vector<int> ans;
	int rule1[5] = { 1,2,3,4,5 };
	int rule2[8] = { 2,1,2,3,2,4,2,5 };
	int rule3[10] = { 3,3,1,1,2,2,4,4,5,5 };
	int one, two, three;
	one = two = three = 0;
	for (int i = 0; i < answers.size(); i++) {
		if (rule1[i % 5] == answers[i]) {
			one++;
		}

		if (rule2[i % 8] == answers[i]) {
			two++;
		}

		if (rule3[i % 10] == answers[i]) {
			three++;
		}
	}
	int maxVal = max(max(one, two), three);
	if (one == maxVal) {
		ans.push_back(1);
	}
	if (two == maxVal) {
		ans.push_back(2);
	}
	if (three == maxVal) {
		ans.push_back(3);
	}
	return ans;
}