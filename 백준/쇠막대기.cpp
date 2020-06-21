#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(string arrangement) {
	vector<int> laser; // 레이저 좌표 저장
	vector<pair<int, int>> line; // 쇠막대기 (시작점, 끝점) 저장
	stack<int> s; // '(' -> push , ')' -> pop
	int ans = 0;
	for (int i = 0; i < arrangement.length(); i++) {
		if (arrangement[i] == '(') {
			s.push(i);
		}
		else {
			int start = s.top(); // start는 시작점, i는 끝점
			s.pop();
			if (i - start == 1) { // 길이가 1인건 레이저
				laser.push_back(i);
			}
			else { // 아니면 쇠막대기
				line.push_back({ start,i });
			}
		}
	}
	for (int i = 0; i < line.size(); i++) {
		int cnt = 0;
		for (int j = 0; j < laser.size(); j++) {
			if (laser[j] >= line[i].first && laser[j] <= line[i].second) {
				cnt++;
			}
			else if (laser[j] > line[i].second) {
				break;
			}
		}
		ans += cnt + 1;
	}
	return ans;
}