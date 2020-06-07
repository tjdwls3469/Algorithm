/*
단위 신경써주고 블록들 오름차순으로 정렬해서 양쪽끝에서 더하면서
더한값이 목표값보다 크면 큰값의 인덱스를 내려주고
작으면 작은값의 인덱스를 올려준다
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int goal;
	while (cin >> goal) {
		int cnt;
		cin >> cnt;
		vector<int> lego(cnt);
		for (int i = 0; i < cnt; i++) {
			cin >> lego[i];
		}
		sort(lego.begin(), lego.end());
		int left = 0;
		int right = cnt - 1;
		bool check = false;
		goal *= 10000000; // 단위 맞춤
		while (left < right) {
			int sum = lego[left] + lego[right];
			if (sum == goal) {
				check = true;
				break;
			}
			if (sum > goal) {
				right--;
			}
			else {
				left++;
			}
		}
		if (check == true) {
			cout << "yes " << lego[left] << ' ' << lego[right] << '\n';
		}
		else {
			cout << "danger" << '\n';
		}
	}
	return 0;
}