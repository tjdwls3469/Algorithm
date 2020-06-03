/*
1. 0 ~ 1000000 사이를 이동시킬 채널로 설정
2. 채널에 이동시킬 번호가 있는지 확인
3. 이동시킨 채널 - 목표채널 구하기
*/
#include <iostream>
#include <algorithm>
using namespace std;

bool check[10];

int calPress(int channel) { // 이동시킬 채널에 고장난 버튼이 있으면 0 아니면 횟수 리턴
	if (channel == 0) {
		if (check[channel] == true) { // 채널이 0이고 고장난 버튼이라면 0리턴
			return 0;
		}
		else {
			return 1;
		}
	}
	int num = channel;
	int pressCnt = 0; // 누른횟수
	while (true) { // num이 0이 될때까지 반복
		if (num == 0) {
			break;
		}
		if (check[num % 10] == true) { // nun의 일의자리수가 고장났는지 체크
			return 0;
		}
		num /= 10; // 일의자리 -> 십의자리 -> 백의자리 순서로 비교하게끔 num을 조작
		pressCnt++;
	}
	return pressCnt;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int goal;
	int cnt;
	int ans;
	cin >> goal >> cnt;
	ans = abs(goal - 100); // 현재 100에서 goal까지 +or-로만 이동 시킨 횟수
	for (int i = 0; i < cnt; i++) { // 고장난 버튼 true로 만들기
		int button;
		cin >> button;
		check[button] = true;
	}

	for (int i = 0; i < 1000000; i++) { // i는 이동시킬 채널
		int numPressCnt = calPress(i); // i로 이동시킬때 눌러야하는 횟수
		if (numPressCnt == 0) {
			continue;
		}
		int moveCnt = abs(goal - i); // 목표채널에서 현재 설정한 채널(i)를 빼면 +나-버튼 누른 횟수구해짐
		if (numPressCnt + moveCnt < ans) {
			ans = numPressCnt + moveCnt;
		}
	}
	cout << ans;
	return 0;
}