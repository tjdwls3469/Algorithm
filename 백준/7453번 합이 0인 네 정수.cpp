#pragma warning (disable:4996)
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	int cnt;
	scanf("%d", &cnt);
	vector<int> a(cnt), b(cnt), c(cnt), d(cnt);
	for (int i = 0; i < cnt; i++) {
		scanf("%d %d %d %d", &a[i], &b[i], &c[i], &d[i]);
	}
	vector<int> first, second;
	for (int i = 0; i < cnt; i++) {
		for (int j = 0; j < cnt; j++) {
			first.push_back(a[i] + b[j]);
			second.push_back(c[i] + d[j]);
		}
	}
	sort(second.begin(), second.end());
	long long ans = 0;
	for (int num : first) {
		auto range = equal_range(second.begin(), second.end(), -num);
		ans += range.second - range.first;
	}
	printf("%lld\n", ans);
	return 0;
}