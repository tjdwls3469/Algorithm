#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

bool compare(pair<int, pair<int, string>> a, pair<int, pair<int, string>> b) {
	if (a.second.first == b.second.first) {
		return a.first > b.first;
	}
	else {
		return a.second.first > b.second.first;
	}
}

int main() {
	/*vector<pair<int, string>> v;
	v.push_back(pair<int, string>(50, "���"));
	v.push_back(pair<int, string>(80, "����"));
	v.push_back(pair<int, string>(70, "�ܱ���"));
	v.push_back(pair<int, string>(90, "��Ž"));
	v.push_back(pair<int, string>(60, "�ѱ���"));

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++) {
		cout << v[i].second << " ";
	}

	return 0;*/



	vector<pair<int, pair<int, string>>> v;
	v.push_back(pair<int, pair<int, string>>(2012335008, pair<int, string>(50, "���")));
	v.push_back(pair<int, pair<int, string>>(2013335008, pair<int, string>(80, "����")));
	v.push_back(pair<int, pair<int, string>>(2014335008, pair<int, string>(80, "�ܱ���")));
	v.push_back(pair<int, pair<int, string>>(2015335008, pair<int, string>(90, "��Ž")));
	v.push_back(pair<int, pair<int, string>>(2016335008, pair<int, string>(60, "�ѱ���")));

	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < v.size(); i++) {
		cout << v[i].first << " ";
	}

	return 0;
}