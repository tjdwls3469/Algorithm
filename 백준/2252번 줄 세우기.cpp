#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int studentCnt;
int cnt;
vector<int> student[32001];
int degree[32001];
vector<int> ans;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> studentCnt >> cnt;
	int start;
	int end;
	for (int i = 0; i < cnt; i++) {
		cin >> start >> end;
		student[end].push_back(start);
		student[start].push_back(end);
		degree[end]++;
	}
	queue<int> q;
	for (int i = 1; i <= studentCnt; i++) {
		if (degree[i] == 0) {
			q.push(i);
		}
	}
	for (int i = 1; i <= studentCnt; i++) {
		if (q.empty() == true) {
			cout << "오답입니다.";
		}
		int people = q.front();
		q.pop();
		ans.push_back(people);
		for (int j = 0; j < student[people].size(); j++) {
			int temp = student[people][j];
			degree[temp]--;
			if (degree[temp] == 0) {
				q.push(temp);
			}
		}
	}
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << ' ';
	}
	return 0;
}