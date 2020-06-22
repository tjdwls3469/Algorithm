#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

// first : 재생횟수, second : 인덱스
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
	map<string, int> m; // 장르, 장르별 재생횟수 총합 저장
	vector<pair<int, string>> rank; // map에 있던거 (재생횟수, 장르)로 저장
	for (int i = 0; i < plays.size(); i++) {
		m[genres[i]] += plays[i]; // 장르별 총 재생횟수 구하기
	}
	map<string, int>::iterator i;
	for (i = m.begin(); i != m.end(); i++) {
		rank.push_back({ i->second, i->first }); // rank백터에 (재생횟수, 장르)로 저장
	}
	sort(rank.begin(), rank.end()); // 재생횟수 기준으로 오름차순
	for (int i = rank.size() - 1; i >= 0; i--) { // 제일 많이 재생된 장르부터 for문 수행
		vector<pair<int, int>> index; // 재생횟수와 인덱스 저장
		for (int j = 0; j < genres.size(); j++) {
			if (genres[j] == rank[i].second) { // 장르가 같으면
				index.push_back({ plays[j], j }); // 재생횟수와 인덱스 저장
			}
		}
		sort(index.begin(), index.end(), cmp); // 2,3번 조건대로 정렬
		for (int i = 0; i < index.size(); i++) {
			if (i >= 2) {
				break;
			}
			ans.push_back(index[i].second);
		}
	}
	return ans;
}