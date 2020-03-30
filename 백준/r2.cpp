#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

int main() {
	string S = "John Doe; Peter Benjamin Parker; Mary Jane Watson-Parker; John Elvis Doe; John Evan Doe; Jane Doe; Peter Brian Parker";
	string C = "Example";

	transform(C.begin(), C.end(), C.begin(), tolower);
	C += ".com";
	cout << C << '\n';

	stringstream ss(S);
	string temp;
	vector<string> name;
	vector<string> trans;
	vector<string> id;
	vector<string> transId;
	while (getline(ss, temp, ';')) {
		name.push_back(temp);
	}
	trans.push_back(" " + name[0]);
	for (int i = 1; i < name.size(); i++) {
		trans.push_back(name[i]);
	}
	/*for (int i = 0; i < name.size(); i++) {
		cout << name[i] << '\n';
	}*/
	for (int i = 0; i < trans.size(); i++) {
		cout << trans[i] << '\n';
	}
	for (int i = 0; i < trans.size(); i++) {
		stringstream ss(trans[i]);
		string temp;
		while (getline(ss, temp, ' ')) {
			id.push_back(temp);
		}
	}
	for (int i = 0; i < id.size(); i++) {
		cout << id[i] << '\n';
	}
	/*for (int i = 0; i < id.size(); i++) {
		stringstream ss(id[i]);
		string temp;
		while (getline(ss, temp, '-')) {
			transId.push_back(temp);
		}
	}
	for (int i = 0; i < transId.size(); i++) {
		cout << transId[i] << '\n';
	}*/
	
	return 0;
}