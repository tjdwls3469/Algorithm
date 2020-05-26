/*
���� ��츦 ���غ��� �ð��ʰ���
c, d �迭�� ���� �� ������������ �����ϰ�
a, b �迭�� ���� ��� ��츦 Ÿ������ �̺�Ž�� ������ ã�´�
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long ary[4000][4];
vector<long long> cd;
long long ans;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int cnt;
	cin >> cnt;
	for (int i = 0; i < cnt; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> ary[i][j];
		}
	}
	for (int i = 0; i < cnt; i++) {
		for (int j = 0; j < cnt; j++) {
			cd.push_back(ary[i][2] + ary[j][3]); // �迭 c, d ��ġ��
		}
	}
	sort(cd.begin(), cd.end());
	for (int i = 0; i < cnt; i++) {
		for (int j = 0; j < cnt; j++) {
			long long target = ary[i][0] + ary[j][1]; // a, b �迭�� ���� ��� ��츦 Ÿ��
			long long startIndex = lower_bound(cd.begin(), cd.end(), -target) - cd.begin();
			long long endIndex = upper_bound(cd.begin(), cd.end(), -target) - cd.begin();
			/*
			startIndex�� target�� ������ �ϴ� ���� ���� �ε��� 
			���� target�� ���ٸ� target���� ū ���� ���� index

			endIndex�� target���� �ʰ��ϴ� �ε���
			*/
			if (cd[startIndex] == -target) {
				ans += endIndex - startIndex;
			}
		}
	}
	cout << ans;
	return 0;
}