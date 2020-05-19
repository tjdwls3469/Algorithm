#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int cnt;
int goal;
int ans = -1;

void solve(int left, int right, vector<int>&tree) { // left와 right는 인덱스가 아닌 최소, 최대 값
	if (left > right) { // 탈출조건
		return;
	}
	long long sum = 0;
	int mid = (left + right) / 2;
	for (int i = cnt - 1; i >= 0; i--) { // 오른차순으로 tree백터를 정렬했으므로
		if (tree[i] <= mid) { // mid높이 보다 작은 나무는 자르지 못하니 탈출
			break;
		}
		sum += (tree[i] - mid);
	}
	if (sum == goal) {
		ans = mid;
		return;
	}
	if (sum < goal) { // sum이 goal보다 작으면 설정한 높이를 줄여야한다
		solve(left, mid - 1, tree);
	}
	if (sum > goal) { // sum이 goal보다 크면 설정한 높이를 늘려야한다
		if (ans == -1 || mid > ans) {
			ans = mid;
		}
		solve(mid + 1, right, tree);
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> cnt >> goal;
	vector<int> tree(cnt);
	for (int i = 0; i < cnt; i++) {
		cin >> tree[i];
	}
	sort(tree.begin(), tree.end());
	solve(0, tree[cnt - 1], tree); // 인덱스가 아닌 0과 나무의 최대값을 보내준다
	cout << ans;
	return 0;
}