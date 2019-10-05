#include <iostream>
#pragma warning(disable: 4996)

using namespace std;

int main() {
	int result;
	int count = 0;
	scanf("%d", &result);

	result = 1000 - result;

	count += result / 500;
	result = result % 500;
	count += result / 100;
	result = result % 100;
	count += result / 50;
	result = result % 50;
	count += result / 10;
	result = result % 10;
	count += result / 5;
	result = result % 5;
	count += result / 1;
	result = result % 1;

	cout << count;

	return 0;
}