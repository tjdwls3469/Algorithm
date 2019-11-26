#include <iostream>
using namespace std;

int gamePlate[100][100];
long long result[100][100];

int main() {
	int size;
	cin >> size;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cin >> gamePlate[i][j];
		}
	}
	result[0][0] = 1;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (gamePlate[i][j] == 0) {
				continue;
			}
			if (j + gamePlate[i][j] < size) {
				result[i][j + gamePlate[i][j]] += result[i][j];
			}
			if (i + gamePlate[i][j] < size) {
				result[i + gamePlate[i][j]][j] += result[i][j];
			}
		}
	}
	cout << result[size - 1][size - 1];

	return 0;
}