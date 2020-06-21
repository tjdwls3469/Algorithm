#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(string arrangement) {
	vector<int> laser; // ������ ��ǥ ����
	vector<pair<int, int>> line; // �踷��� (������, ����) ����
	stack<int> s; // '(' -> push , ')' -> pop
	int ans = 0;
	for (int i = 0; i < arrangement.length(); i++) {
		if (arrangement[i] == '(') {
			s.push(i);
		}
		else {
			int start = s.top(); // start�� ������, i�� ����
			s.pop();
			if (i - start == 1) { // ���̰� 1�ΰ� ������
				laser.push_back(i);
			}
			else { // �ƴϸ� �踷���
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