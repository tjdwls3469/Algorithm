#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> heights) {
	vector<int> ans;
	for (int i = 0; i < heights.size(); i++) {
		int cur = heights[i];
		bool check = false;
		for (int j = i - 1; j >= 0; j--) {
			if (heights[j] > cur) {
				check = true;
				ans.push_back(j + 1);
				break;
			}
		}
		if (check == false) {
			ans.push_back(0);
		}
	}
	return ans;
}