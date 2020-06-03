/*
1. 0 ~ 1000000 ���̸� �̵���ų ä�η� ����
2. ä�ο� �̵���ų ��ȣ�� �ִ��� Ȯ��
3. �̵���Ų ä�� - ��ǥä�� ���ϱ�
*/
#include <iostream>
#include <algorithm>
using namespace std;

bool check[10];

int calPress(int channel) { // �̵���ų ä�ο� ���峭 ��ư�� ������ 0 �ƴϸ� Ƚ�� ����
	if (channel == 0) {
		if (check[channel] == true) { // ä���� 0�̰� ���峭 ��ư�̶�� 0����
			return 0;
		}
		else {
			return 1;
		}
	}
	int num = channel;
	int pressCnt = 0; // ����Ƚ��
	while (true) { // num�� 0�� �ɶ����� �ݺ�
		if (num == 0) {
			break;
		}
		if (check[num % 10] == true) { // nun�� �����ڸ����� ���峵���� üũ
			return 0;
		}
		num /= 10; // �����ڸ� -> �����ڸ� -> �����ڸ� ������ ���ϰԲ� num�� ����
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
	ans = abs(goal - 100); // ���� 100���� goal���� +or-�θ� �̵� ��Ų Ƚ��
	for (int i = 0; i < cnt; i++) { // ���峭 ��ư true�� �����
		int button;
		cin >> button;
		check[button] = true;
	}

	for (int i = 0; i < 1000000; i++) { // i�� �̵���ų ä��
		int numPressCnt = calPress(i); // i�� �̵���ų�� �������ϴ� Ƚ��
		if (numPressCnt == 0) {
			continue;
		}
		int moveCnt = abs(goal - i); // ��ǥä�ο��� ���� ������ ä��(i)�� ���� +��-��ư ���� Ƚ��������
		if (numPressCnt + moveCnt < ans) {
			ans = numPressCnt + moveCnt;
		}
	}
	cout << ans;
	return 0;
}