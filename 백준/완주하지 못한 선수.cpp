#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	string ans = "";
	bool check = false;
	sort(participant.begin(), participant.end());
	sort(completion.begin(), completion.end());
	for (int i = 0; i < completion.size(); i++) {
		if (participant[i] != completion[i]) {
			check = true;
			ans = participant[i];
			break;
		}
	}
	if (check == true) {
		return ans;
	}
	else {
		return participant[participant.size() - 1];
	}
}