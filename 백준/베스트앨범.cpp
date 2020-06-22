#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

// first : ���Ƚ��, second : �ε���
bool cmp(pair<int, int> x, pair<int, int> y) {
	if (x.first == y.first) {
		return x.second < y.second;
	}
	else {
		return x.first > y.first;
	}
}

vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<int> ans;
	map<string, int> m; // �帣, �帣�� ���Ƚ�� ���� ����
	vector<pair<int, string>> rank; // map�� �ִ��� (���Ƚ��, �帣)�� ����
	for (int i = 0; i < plays.size(); i++) {
		m[genres[i]] += plays[i]; // �帣�� �� ���Ƚ�� ���ϱ�
	}
	map<string, int>::iterator i;
	for (i = m.begin(); i != m.end(); i++) {
		rank.push_back({ i->second, i->first }); // rank���Ϳ� (���Ƚ��, �帣)�� ����
	}
	sort(rank.begin(), rank.end()); // ���Ƚ�� �������� ��������
	for (int i = rank.size() - 1; i >= 0; i--) { // ���� ���� ����� �帣���� for�� ����
		vector<pair<int, int>> index; // ���Ƚ���� �ε��� ����
		for (int j = 0; j < genres.size(); j++) {
			if (genres[j] == rank[i].second) { // �帣�� ������
				index.push_back({ plays[j], j }); // ���Ƚ���� �ε��� ����
			}
		}
		sort(index.begin(), index.end(), cmp); // 2,3�� ���Ǵ�� ����
		for (int i = 0; i < index.size(); i++) {
			if (i >= 2) {
				break;
			}
			ans.push_back(index[i].second);
		}
	}
	return ans;
}