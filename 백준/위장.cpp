#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
	int ans = 1;
	map<string, int> m;
	for (int i = 0; i < clothes.size(); i++) {
		m[clothes[i][1]]++;
	}
	map<string, int>::iterator i;
	for (i = m.begin(); i != m.end(); i++) {
		ans *= i->second + 1;
	}
	return (ans - 1);
}