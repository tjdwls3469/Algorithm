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
	for (int i = 2; i <= n; i++) { // 2���� N���� �����߿���
		if (check[i] == false) { // �������� ������ �Ҽ��̴�
			check[i] = true; // �Ҽ��� �����
			num[cnt] = i;
			cnt++;
			for (int j = i * i; j <= n; j += i) { // �Ҽ��� ����� ũ������� �����
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