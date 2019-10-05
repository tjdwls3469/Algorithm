#include <iostream>
#include <string>

using namespace std;

int main() {
	string exp;
	cin >> exp;
	char num[100];
	int j = 0;
	int result = 0;
	int temp = 0;
	int check = 0;
	int first = 0;

	// 주석 추가
	// test123

	for (int i = 0; i <= exp.size(); i++) {
		if (exp[i] == '\0') {
			num[j] = '\0';
			temp = stoi(num);
			if (check == 1) {
				result -= temp;
			}
			else {
				result += temp;
			}
			break;
		}
		else if (exp[i] == '+' || exp[i] == '-') {
			num[j] = '\0';
			j = 0;
			temp = stoi(num);
			
			if (exp[i] == '-') {
				if (first == 0) {
					result += temp;
					temp = 0;
					first = 1;
					check = 1;
					continue;
				}
				check = 1;
			}
			if (check == 1) {
				result -= temp;
				temp = 0;
				continue;
			}
			else {
				result += temp;
				temp = 0;
			}
		}
		else {
			num[j] = exp[i];
			j++;
		}
	}

	cout << result;

	return 0;
}