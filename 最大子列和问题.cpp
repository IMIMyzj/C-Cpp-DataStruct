#include <iostream>

using namespace std;

int MaxSum(int Num, int a[]) {
	int MaxSum = 0;
	int ThisSum = 0;
	int count = 0;

	for (int j = 0; j < Num; j++) {
		if (a[j] < 0) {
			count++;
		}
	}

	if (count == Num)
		return 0;

	for (int j = 0; j < Num; j++) {
		ThisSum += a[j];
		if (ThisSum > MaxSum)
			MaxSum = ThisSum;
		else if (ThisSum < 0)
			ThisSum = 0;
	}

	return MaxSum;
}

int main() {
	int a[100000];
	long int Num;

	cin >> Num;
	for (long int i = 0; i < Num; i++)
		cin >> a[i];

	cout << endl << MaxSum(Num, a) << endl;

	system("pause");
	return 0;
}