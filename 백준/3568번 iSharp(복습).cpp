#include <iostream>
#include <string>
using namespace std;

int main() {
	string str = "";
	getline(cin, str);
	string temp = "";
	string preType = "";
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == ' ') {
			preType = temp;
			temp = "";
			continue;
		}
		else if (str[i] == ',' || str[i] == ';') {
			i++;
			string ans = "";
			ans += preType;
			bool first = false;
			for (int j = temp.length() - 1; j >= 0; j--) {
				if (temp[j] == '&' || temp[j] == '*') {
					ans += temp[j];
				}
				else if (temp[j] == ']') {
					ans += "[]";
					j--;
				}
				else {
					if (first == false) {
						ans += " ";
						first = true;
					}
					ans += temp[j];
				}
			}
			cout << ans << '\n';
			temp = "";
			continue;
		}
		temp += str[i];
	}
	return 0;
}