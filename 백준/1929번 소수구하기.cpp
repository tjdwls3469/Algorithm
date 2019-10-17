#include <iostream>
using namespace std;

int prime[1000000];
int pNum;
bool check[1000001];

int main() {
	int first;
	int end;
	cin >> first >> end;

	for (int i = 2; i <= end; i++) {
		if (check[i] == false) {
			prime[pNum] = i;
			pNum++;
			for (int j = i * 2; j <= end; j += i) {
				check[j] = true;
			}
		}
	}

	for (int i = 0; i < end; i++) {
		if (prime[i] >= first) {
			cout << prime[i] << '\n';
		}
	}

	return 0;
}