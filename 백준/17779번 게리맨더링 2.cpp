#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int map[21][21];
int ans = -1;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int cnt;
	int sum = 0;
	cin >> cnt;
	for (int i = 1; i <= cnt; i++) {
		for (int j = 1; j <= cnt; j++) {
			cin >> map[i][j];
			sum += map[i][j];
		}
	}
	for (int x = 1; x <= cnt; x++) {
		for (int y = 1; y <= cnt; y++) {
			for (int d1 = 1; d1 <= cnt; d1++) {
				for (int d2 = 1; d2 <= cnt; d2++) {
					if ((x < (x + d1 + d2)) && ((x + d1 + d2) <= cnt)) {
						if ((1 <= y - d1) && (y - d1 < y) && (y < y + d2) && (y + d2 <= cnt)) {
							int gu1, gu2, gu3, gu4, gu5;
							gu1 = gu2 = gu3 = gu4 = gu5 = 0;
							// 1번 선거구 x,y 윗 부분
							for (int i = 0; i < x; i++) {
								for (int j = 0; j <= y; j++) {
									gu1 += map[i][j];
								}
							}
							// 1번 선거구 계단처럼 생긴 옆 부분
							int k = 0;
							for (int i = x; i < x + d1; i++) {
								for (int j = 0; j < y-k; j++) {
									gu1 += map[i][j];
								}
								k++;
							}
							// 2번 선거구 윗부분
							for (int i = 0; i < x; i++) {
								for (int j = y+1; j <= cnt; j++) {
									gu2 += map[i][j];
								}
							}
							// 2번 선거구 옆부분
							k = 0;
							for (int i = x; i <= x + d2; i++) {
								for (int j = y + 1 + k; j <= cnt; j++) {
									gu2 += map[i][j];
								}
								k++;
							}
							// 3번 선거구 아래
							for (int i = x + d1 + d2 + 1; i <= cnt; i++) {
								for (int j = 0; j < y - d1 + d2; j++) {
									gu3 += map[i][j];
								}
							}
							// 3번 선거구 옆
							k = 0;
							for (int i = x + d1; i <= x + d1 + d2; i++) {
								for (int j = 0; j < y - d1 + k; j++) {
									gu3 += map[i][j];
								}
								k++;
							}
							// 4번 선거구 아래
							for (int i = x + d1 + d2 + 1; i <= cnt; i++) {
								for (int j = y - d1 + d2; j <= cnt; j++) {
									gu4 += map[i][j];
								}
							}
							// 4번 선거구 옆
							k = 1;
							for (int i = x + d2 + 1; i <= x + d1 + d2; i++) {
								for (int j = y + d2 + 1 - k; j <= cnt; j++) {
									gu4 += map[i][j];
								}
								k++;
							}

							gu5 = sum - (gu1 + gu2 + gu3 + gu4);
							vector<int> temp;
							temp.push_back(gu1);
							temp.push_back(gu2);
							temp.push_back(gu3);
							temp.push_back(gu4);
							temp.push_back(gu5);
							sort(temp.begin(), temp.end());
							if (ans == -1 || temp[4] - temp[0] < ans) {
								ans = temp[4] - temp[0];
							}
						}
					}
				}
			}
		}
	}
	cout << ans;
	return 0;
}