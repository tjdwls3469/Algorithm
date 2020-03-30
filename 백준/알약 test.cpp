#include <iostream>
#include <vector>
using namespace std;

bool check[100001];

int main() {
	vector<int> A;
	for (int i = 0; i < A.size(); i++) {
		check[A[i]] = true;
	}
	for (int i = 1; i < 100001; i++) {
		if (check[i] == false) {
			cout << i;
			break;
		}
	}
}