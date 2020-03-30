#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void print(vector<int> &A) {
	for (int i = 0; i < A.size(); i++) {
		cout << A[i] << ' ';
	}
	cout << '\n';
}

int main() {
	vector<int> A;
	/*A.push_back(3);
	A.push_back(8);
	A.push_back(2);
	A.push_back(3);
	A.push_back(3);
	A.push_back(2);*/
	A.push_back(5);
	A.push_back(5);
	A.push_back(5);
	A.push_back(5);
	A.push_back(5);
	print(A);
	sort(A.begin(), A.end());
	print(A);

	int val = A[0];
	int cnt = 0;
	int maxCnt = 0;
	int maxVal = A[0];
	for (int i = 0; i < A.size(); i++) {
		if (A[i] == val) {
			cnt++;
			continue;
		}
		if (cnt >= maxCnt) {
			maxCnt = cnt;
			maxVal = A[i - 1];
			val = A[i];
			cnt = 1;
		}
	}
	if (maxCnt == 0) {
		maxCnt = cnt;
	}
	cout << "최대 개수 : " << maxCnt << " 최대 값 : " << maxVal << '\n';
	cout << A.size();

	if (maxCnt == maxVal) {
		return maxVal;
	}
	else {
		return 0;
	}
	return 0;
}