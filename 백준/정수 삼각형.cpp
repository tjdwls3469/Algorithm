#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int d[500][500];

int solution(vector<vector<int>> triangle) {
	int ans = 0;
	for (int i = 0; i < triangle[triangle.size() - 1].size(); i++) {
		d[triangle.size() - 1][i] = triangle[triangle.size() - 1][i];
	}
	for (int i = triangle.size() - 2; i >= 0; i--) {
		for (int j = 0; j < triangle[i].size(); j++) {
			d[i][j] = max(d[i + 1][j], d[i + 1][j + 1]) + triangle[i][j];
		}
	}
	ans = d[0][0];
	return ans;
}