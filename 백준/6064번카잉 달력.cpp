/*
�׳� �ƹ��������� �ϸ� �ð��ʰ����
ù��° �ذ� <1,1>�� �ƴ϶� <0,0>���� �����ؼ�
k��° �ش� <k%m,k%n>�� �ȴ�
x�� k%m, y�� k%n�� �Ǹ� ����
x���� �����ؼ� m�� �����ϸ鼭 k%n�� y�� �Ǵ��� ã�´�
*/
#include <iostream>
using namespace std;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int tc;
	int m, n, x, y;
	cin >> tc;
	for (int i = 0; i < tc; i++) {
		bool check = false;
		cin >> m >> n >> x >> y;
		x--;
		y--;
		for (int j = x; j < m*n; j += m) {
			if (j%n == y) {
				check = true;
				cout << j + 1 << '\n';
				break;
			}
		}
		if (check == false) {
			cout << -1 << '\n';
		}
	}
	return 0;
}