/*
ans[i][j] = (i,j)�� �����ִ� ����� ����
*/
#include <iostream>
using namespace std;

int map[100][100];
long long ans[100][100]; // ó���� int�� �ߴٰ� Ʋ��;;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int rc;
	cin >> rc;
	for (int i = 0; i < rc; i++) {
		for (int j = 0; j < rc; j++) {
			cin >> map[i][j];
		}
	}
	ans[0][0] = 1;
	for (int i = 0; i < rc; i++) {
		for (int j = 0; j < rc; j++) {
			if (map[i][j] == 0) {
				continue;
			}
			if (j + map[i][j] < rc) { // ���������� �̵�
				ans[i][j + map[i][j]] += ans[i][j];
			}
			if (i + map[i][j] < rc) { // �Ʒ��� �̵�
				ans[i + map[i][j]][j] += ans[i][j];
			}
		}
	}
	cout << ans[rc - 1][rc - 1];
	return 0;
}