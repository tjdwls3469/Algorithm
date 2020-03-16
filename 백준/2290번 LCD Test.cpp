#include <iostream>
#include <string>
using namespace std;

int main() {
	int s;
	string num;
	cin >> s >> num;
	for (int i = 0; i < num.length(); i++) {
		if (num.at(i) == '1' || num.at(i) == '4') {
			for (int j = 0; j < s + 2; j++) {
				cout << ' ';
			}
			cout << ' ';
			continue;
		}
		cout << ' ';
		for (int j = 0; j < s; j++) {
			cout << '-';
		}
		cout << ' ';
		cout << ' ';
	}
	cout << '\n';
	for (int k = 0; k < s; k++) {
		for (int i = 0; i < num.length(); i++) {
			if (num.at(i) == '1' || num.at(i) == '2' || num.at(i) == '3' || num.at(i) == '7') {
				for (int j = 0; j < s + 1; j++) {
					cout << ' ';
				}
				cout << '|';
				cout << ' ';
			}
			else if (num.at(i) == '5' || num.at(i) == '6') {
				cout << '|';
				for (int j = 0; j < s + 1; j++) {
					cout << ' ';
				}
				cout << ' ';
			}
			else {
				cout << '|';
				for (int j = 0; j < s; j++) {
					cout << ' ';
				}
				cout << '|';
				cout << ' ';
			}
		}
		cout << '\n';
	}
	for (int i = 0; i < num.length(); i++) {
		if (num.at(i) == '1' || num.at(i) == '7' || num.at(i) == '0') {
			for (int j = 0; j < s + 2; j++) {
				cout << ' ';
			}
			cout << ' ';
			continue;
		}
		cout << ' ';
		for (int j = 0; j < s; j++) {
			cout << '-';
		}
		cout << ' ';
		cout << ' ';
	}
	cout << '\n';
	for (int k = 0; k < s; k++) {
		for (int i = 0; i < num.length(); i++) {
			if (num.at(i) == '0' || num.at(i) == '6' || num.at(i) == '8') {
				cout << '|';
				for (int j = 0; j < s; j++) {
					cout << ' ';
				}
				cout << '|';
				cout << ' ';
			}
			else if (num.at(i) == '2') {
				cout << '|';
				for (int j = 0; j < s + 1; j++) {
					cout << ' ';
				}
				cout << ' ';
			}
			else {
				for (int j = 0; j < s + 1; j++) {
					cout << ' ';
				}
				cout << '|';
				cout << ' ';
			}
		}
		cout << '\n';
	}
	for (int i = 0; i < num.length(); i++) {
		if (num.at(i) == '1' || num.at(i) == '4' || num.at(i) == '7') {
			for (int j = 0; j < s + 2; j++) {
				cout << ' ';
			}
			cout << ' ';
			continue;
		}
		cout << ' ';
		for (int j = 0; j < s; j++) {
			cout << '-';
		}
		cout << ' ';
		cout << ' ';
	}
	cout << '\n';
	return 0;
}