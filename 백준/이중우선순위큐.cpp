#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<string> operations) {
	vector<int> ans;
	priority_queue<int> maxQ;
	priority_queue<int, vector<int>, greater<int>> minQ;
	for (int i = 0; i < operations.size(); i++) {
		bool maxDel = false;
		bool minDel = false;
		switch (operations[i][0]) {
		case 'I':
			maxQ.push(stoi(operations[i].substr(2, operations[i].length() - 2)));
			minQ.push(stoi(operations[i].substr(2, operations[i].length() - 2)));
			break;
		default:
			if (operations[i].length() == 3) {
				if (!maxQ.empty()) {
					maxQ.pop();
					maxDel = true;
				}
			}
			else {
				if (!minQ.empty()) {
					minQ.pop();
					minDel = true;
				}
			}
			break;
		}
		if (maxDel == true) {
			priority_queue<int, vector<int>, greater<int>> temp;
			for (int i = 0; i < minQ.size() - 1; i++) {
				temp.push(minQ.top());
				minQ.pop();
			}
			minQ.swap(temp);
		}
		if (minDel == true) {
			priority_queue<int> temp;
			for (int i = 0; i < maxQ.size() - 1; i++) {
				temp.push(maxQ.top());
				maxQ.pop();
			}
			maxQ.swap(temp);
		}
	}
	if (!maxQ.empty()) {
		ans.push_back(maxQ.top());
	}
	else {
		ans.push_back(0);
	}
	if (!minQ.empty()) {
		ans.push_back(minQ.top());
	}
	else {
		ans.push_back(0);
	}
	return ans;
}