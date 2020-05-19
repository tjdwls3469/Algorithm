#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int cnt;
int goal;
int ans = -1;

void solve(int left, int right, vector<int>&tree) { // left�� right�� �ε����� �ƴ� �ּ�, �ִ� ��
	if (left > right) { // Ż������
		return;
	}
	long long sum = 0;
	int mid = (left + right) / 2;
	for (int i = cnt - 1; i >= 0; i--) { // ������������ tree���͸� ���������Ƿ�
		if (tree[i] <= mid) { // mid���� ���� ���� ������ �ڸ��� ���ϴ� Ż��
			break;
		}
		sum += (tree[i] - mid);
	}
	if (sum == goal) {
		ans = mid;
		return;
	}
	if (sum < goal) { // sum�� goal���� ������ ������ ���̸� �ٿ����Ѵ�
		solve(left, mid - 1, tree);
	}
	if (sum > goal) { // sum�� goal���� ũ�� ������ ���̸� �÷����Ѵ�
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
	solve(0, tree[cnt - 1], tree); // �ε����� �ƴ� 0�� ������ �ִ밪�� �����ش�
	cout << ans;
	return 0;
}