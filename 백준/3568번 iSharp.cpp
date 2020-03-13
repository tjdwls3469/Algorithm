#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	string str;
	vector<string> v;
	while (true) {
		string str;
		cin >> str;
		v.push_back(str);
		if (str.at(str.length()-1) == ';') {
			break;
		}
	}
	for (int i = 1; i < v.size(); i++) {
		bool ok = true;
		cout << v[0];
		for (int j = v[i].length() - 2; j >= 0; j--) {
			if (v[i][j] == '[') {
				continue;
			}
			if (v[i][j] == '*' || v[i][j] == '&') {
				cout << v[i][j];
			}
			else if (v[i][j] == ']') {
				cout << "[]";
			}
			else {
				if (ok) {
					ok = false;
					cout << ' ';
				}
				cout << v[i][j];
			}
		}
		cout << '\n';
	}
	return 0;
}