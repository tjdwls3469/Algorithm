#include <iostream>
using namespace std;

bool check[1001];
int num[1001];
int cnt;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	int k;
	cin >> n >> k;
	for (int i = 2; i <= n; i++) { // 2부터 N까지 정수중에서
		if (check[i] == false) { // 가장작은 정수는 소수이다
			check[i] = true; // 소수를 지우고
			num[cnt] = i;
			cnt++;
			for (int j = i * i; j <= n; j += i) { // 소수의 배수를 크기순으로 지운다
				if (check[j] == false) {
					check[j] = true;
					num[cnt] = j;
					cnt++;
				}
			}
		}
	}
	cout << num[k - 1];
	return 0;
}