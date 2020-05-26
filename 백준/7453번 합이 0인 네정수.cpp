/*
무든 경우를 다해보면 시간초과뜸
c, d 배열을 묶은 후 오름차순으로 정렬하고
a, b 배열을 더한 모든 경우를 타겟으로 이분탐색 돌려서 찾는다
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
			cd.push_back(ary[i][2] + ary[j][3]); // 배열 c, d 합치기
		}
	}
	sort(cd.begin(), cd.end());
	for (int i = 0; i < cnt; i++) {
		for (int j = 0; j < cnt; j++) {
			long long target = ary[i][0] + ary[j][1]; // a, b 배열을 더한 모든 경우를 타겟
			long long startIndex = lower_bound(cd.begin(), cd.end(), -target) - cd.begin();
			long long endIndex = upper_bound(cd.begin(), cd.end(), -target) - cd.begin();
			/*
			startIndex는 target을 값으로 하는 가장 작은 인덱스 
			만약 target이 없다면 target보다 큰 가장 작은 index

			endIndex는 target값을 초과하는 인덱스
			*/
			if (cd[startIndex] == -target) {
				ans += endIndex - startIndex;
			}
		}
	}
	cout << ans;
	return 0;
}