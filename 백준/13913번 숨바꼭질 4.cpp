#include <iostream>
#include <queue>
#include <vector>
using namespace std;

bool check[200001];
int time[200001];
int from[200001];

int main() {
	int subin;
	int brother;
	cin >> subin >> brother;
	queue<int> q;
	check[subin] = true;
	q.push(subin);
	while (!q.empty()) {
		int present = q.front();
		q.pop();
		if (present - 1 >= 0 && check[present - 1] == false) {
			int next = present - 1;
			check[next] = true;
			q.push(next);
			time[next] = time[present] + 1;
			from[next] = present;
		}
		if (present + 1 <= 200000 && check[present + 1] == false) {
			int next = present + 1;
			check[next] = true;
			q.push(next);
			time[next] = time[present] + 1;
			from[next] = present;
		}
		if (present * 2 <= 200000 && check[present * 2] == false) {
			int next = present * 2;
			check[next] = true;
			q.push(next);
			time[next] = time[present] + 1;
			from[next] = present;
		}
	}
	cout << time[brother] << '\n';
	vector<int> result;
	for (int i = brother; i != subin; i = from[i]) {
		result.push_back(i);
	}
	result.push_back(subin);
	for (int i = result.size() - 1; i >= 0; i--) {
		cout << result[i] << ' ';
	}

	return 0;
}