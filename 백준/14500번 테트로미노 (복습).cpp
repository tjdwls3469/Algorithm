#include <iostream>
#include <algorithm>
using namespace std;

int paper[500][500];
int row;
int col;
int ans = 0;

void a(int x, int y) {
	if (y + 1 >= col || x + 1 >= row) {
		return;
	}
	int sum = paper[x][y] + paper[x][y+1] + paper[x+1][y] + paper[x+1][y+1];
	if (sum > ans) {
		ans = sum;
	}
}

void b(int x, int y) {
	if (y + 3 >= col) {
		return;
	}
	int sum = paper[x][y] + paper[x][y+1] + paper[x][y+2] + paper[x][y+3];
	if (sum > ans) {
		ans = sum;
	}
}

void c(int x, int y) {
	if (x + 3 >= row) {
		return;
	}
	int sum = paper[x][y] + paper[x+1][y] + paper[x+2][y] + paper[x+3][y];
	if (sum > ans) {
		ans = sum;
	}
}

void d(int x, int y) {
	if (y + 1 >= col || x + 2 >= row) {
		return;
	}
	for (int i = 0; i < 3; i++) {
		int sum = paper[x][y] + paper[x + 1][y] + paper[x + 2][y] + paper[x + i][y + 1];
		if (sum > ans) {
			ans = sum;
		}
	}
}

void e(int x, int y) {
	if (y - 1 < 0 || x + 2 >= row) {
		return;
	}
	for (int i = 0; i < 3; i++) {
		int sum = paper[x][y] + paper[x + 1][y] + paper[x + 2][y] + paper[x + i][y - 1];
		if (sum > ans) {
			ans = sum;
		}
	}
}

void f(int x, int y) {
	if (y + 2 >= col || x - 1 < 0) {
		return;
	}
	for (int i = 0; i < 3; i++) {
		int sum = paper[x][y] + paper[x][y + 1] + paper[x][y + 2] + paper[x - 1][y + i];
		if (sum > ans) {
			ans = sum;
		}
	}
}

void g(int x, int y) {
	if (y + 2 >= col || x + 1 >= row) {
		return;
	}
	for (int i = 0; i < 3; i++) {
		int sum = paper[x][y] + paper[x][y + 1] + paper[x][y + 2] + paper[x + 1][y + i];
		if (sum > ans) {
			ans = sum;
		}
	}
}

void h(int x, int y) {
	if (y + 1 >= col || x + 1 >= row || x - 1 < 0) {
		return;
	}
	int sum1 = paper[x][y] + paper[x][y + 1] + paper[x - 1][y] + paper[x + 1][y + 1];
	int sum2 = paper[x][y] + paper[x][y + 1] + paper[x - 1][y + 1] + paper[x + 1][y];
	int temp = max(sum1, sum2);
	if (temp > ans) {
		ans = temp;
	}
}

void k(int x, int y) {
	if (y + 1 >= col || x + 1 >= row || y - 1 < 0) {
		return;
	}
	int sum1 = paper[x][y] + paper[x + 1][y] + paper[x][y + 1] + paper[x + 1][y - 1];
	int sum2 = paper[x][y] + paper[x + 1][y] + paper[x][y - 1] + paper[x + 1][y + 1];
	int temp = max(sum1, sum2);
	if (temp > ans) {
		ans = temp;
	}
}

int main() {
	cin >> row >> col;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cin >> paper[i][j];
		}
	}
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			a(i, j);
			b(i, j);
			c(i, j);
			d(i, j);
			e(i, j);
			f(i, j);
			g(i, j);
			h(i, j);
			k(i, j);
		}
	}
	cout << ans;
	return 0;
}