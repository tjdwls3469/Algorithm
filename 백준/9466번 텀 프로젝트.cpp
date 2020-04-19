#include <iostream>
#include <cstring>
using namespace std;

const int CNT = 100001;
int student[CNT];
bool check[CNT];
bool real[CNT];
int member;

void dfs(int start) {
	check[start] = true;
	int next = student[start];
	if (check[next] == false) {
		dfs(next);
	}
	else {
		if (real[next] == false) {
			for (int i = next; i != start; i = student[i]) {
				member++;
			}
			member++;
		}
	}
	real[start] = true;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int tc;
	cin >> tc;
	for (int i = 0; i < tc; i++) {
		int cnt;
		cin >> cnt;
		member = 0;
		for (int j = 1; j <= cnt; j++) {
			cin >> student[j];
		}
		for (int j = 1; j <= cnt; j++) {
			if (check[j] == false) {
				dfs(j);
			}
		}
		cout << cnt - member << '\n';
		memset(check, false, sizeof(check));
		memset(real, false, sizeof(real));
	}
	return 0;
}