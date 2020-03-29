#pragma warning(disable:4996)
#include <iostream>
using namespace std;

struct Pair {
	int x;
	int y;
};

int check[100][100];
int map[100][100];
int ans[100][100];
Pair queue[10001];
int front, rear;
int dx[] = { 0, -1, 0, 1 };
int dy[] = { -1, 0, 1, 0 };

bool empty() {
	return front == rear;
}

void push(Pair val, int size) {
	if ((rear + 1) % size == front) {
		return;
	}
	queue[rear] = val;
	rear = ++rear % size;
	return;
}



void pop(int size) {
	if (front == rear) {
		return;
	}
	front = ++front%size;
	return;
}

int main() {
	int row;
	int col;
	cin >> row >> col;
	int size = row * col + 1;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	ans[0][0] = 1;
	check[0][0] = true;
	Pair p = { 0,0 };
	push(p, size);
	while (!empty()) {
		int fx = queue[front].x;
		int fy = queue[front].y;
		pop(size);
		for (int i = 0; i < 4; i++) {
			int nx = fx + dx[i];
			int ny = fy + dy[i];
			if (nx >= 0 && nx < row && ny >= 0 && ny < col) {
				if (check[nx][ny] == false && map[nx][ny] == 1) {
					check[nx][ny] = true;
					Pair temp = { nx,ny };
					push(temp, size);
					ans[nx][ny] = ans[fx][fy] + 1;
				}
			}
		}
	}
	cout << ans[row - 1][col - 1];
	return 0;
}