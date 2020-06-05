#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

map<string, int> mm;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;
	vector<string> v(n+1);
	for (int i = 1; i <= n; i++) {
		string temp;
		cin >> temp;
		mm[temp] = i;
		v[i] = temp;
	}
	for (int i = 0; i < m; i++) {
		string temp;
		cin >> temp;
		if (temp[0] >= 'A' && temp[0] <= 'Z') {
			cout << mm[temp] << '\n';
		}
		else {
			cout << v[stoi(temp)] << '\n';
		}
	}
	return 0;
}