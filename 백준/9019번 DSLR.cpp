#include <iostream>
#include <cstring>
#include <queue>
#include <string>
using namespace std;

int start;
int goal;
int map[10000];
int from[10000];
char how[10000];

//int shiftL(int a) {
//	int m = a / 1000;
//	a = (a % 1000) * 10 + m;
//	return a;
//}
//int shiftR(int a) {
//	int m = (a % 10) * 1000;
//	a = (a / 10) + m;
//	return a;
//}

//int shiftL(int fx) {
//	string temp = to_string(fx);
//	string before = "";
//	for (int i = 0; i < 4 - temp.length(); i++) {
//		before += "0";
//	}
//	before += temp;
//	string mid = "";
//	for (int i = 1; i <= 3; i++) {
//		mid += before[i];
//	}
//	mid += before[0];
//	bool check = false;
//	string after = "";
//	for (int i = 0; i < 4; i++) {
//		if (mid[i] != '0') {
//			check = true;
//		}
//		if (check == true) {
//			after += mid[i];
//		}
//	}
//	if (after == "") {
//		after += "0";
//	}
//	return stoi(after);
//}
//
//int shiftR(int fx) {
//	string temp = to_string(fx);
//	string before = "";
//	for (int i = 0; i < 4 - temp.length(); i++) {
//		before += "0";
//	}
//	before += temp;
//	string mid = "";
//	mid += before[3];
//	for (int i = 0; i < 3; i++) {
//		mid += before[i];
//	}
//	bool check = false;
//	string after = "";
//	for (int i = 0; i < 4; i++) {
//		if (mid[i] != '0') {
//			check = true;
//		}
//		if (check == true) {
//			after += mid[i];
//		}
//	}
//	if (after == "") {
//		after += "0";
//	}
//	return stoi(after);
//}

void bfs() {
	map[start] = 1;
	queue<int> q;
	q.push(start);
	from[start] = start;
	while (!q.empty()) {
		int fx = q.front();
		q.pop();
		if (fx == goal) {
			break;
		}
		int d = (fx * 2) % 10000;
		if (map[d] == 0) {
			map[d] = map[fx] + 1;
			from[d] = fx;
			how[d] = 'D';
			q.push(d);
		}
		int s = fx - 1;
		if (s < 0) {
			s = 9999;
		}
		if (map[s] == 0) {
			map[s] = map[fx] + 1;
			from[s] = fx;
			how[s] = 'S';
			q.push(s);
		}
		//int l = shiftL(fx);
		int l = (fx % 1000) * 10 + fx / 1000;
		if (map[l] == 0) {
			map[l] = map[fx] + 1;
			from[l] = fx;
			how[l] = 'L';
			q.push(l);
		}
		//int r = shiftL(fx);
		int r = (fx / 10) + (fx % 10) * 1000;
		if (map[r] == 0) {
			map[r] = map[fx] + 1;
			from[r] = fx;
			how[r] = 'R';
			q.push(r);
		}
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int tc;
	cin >> tc;
	for (int i = 0; i < tc; i++) {
		memset(map, 0, sizeof(map));
		cin >> start >> goal;
		bfs();
		int temp = goal;
		string ans = ""; 
		ans += how[goal];
		while (true) {
			int pre = from[temp];
			ans += how[pre];
			if (temp == from[temp]) {
				break;
			}
			temp = pre;
		}
		for (int j = ans.size() - 3; j >= 0; j--) {
			cout << ans[j];
		}
		cout << '\n';
	}
	return 0;
}