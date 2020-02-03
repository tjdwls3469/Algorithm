#include <iostream>
#include <string>
using namespace std;

int main() {
	int cnt;
	string command;
	int num;
	int ans = 0;
	cin >> cnt;
	for (int i = 0; i < cnt; i++) {
		cin >> command;
		if (command == "add") {
			cin >> num;
			num--;
			ans = (ans | (1 << num));
		}
		else if (command == "remove") {
			cin >> num;
			num--;
			ans = (ans & ~(1 << num));
		}
		else if (command == "check") {
			cin >> num;
			num--;
			if ((ans & (1 << num))) {
				cout << 1 << '\n';
			}
			else {
				cout << 0 << '\n';
			}
		}
		else if (command == "toggle") {
			cin >> num;
			num--;
			ans = (ans ^ (1 << num));
		}
		else if (command == "all") {
			ans = (1 << 20) - 1;
		}
		else if (command == "empty") {
			ans = 0;
		}
		else {
			;
		}
	}
	return 0;
}