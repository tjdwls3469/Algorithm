#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(string &x, string &y) {
	return x + y > y + x;
}

string solution(vector<int> numbers) {
	string ans = "";
	vector<string> temp;
	for (int i = 0; i < numbers.size(); i++) {
		temp.push_back(to_string(numbers[i]));
	}
	sort(temp.begin(), temp.end(), comp);
	if (temp[0] == "0") {
		return "0";
	}
	for (int i = 0; i < temp.size(); i++) {
		ans += temp[i];
	}
	return ans;
}