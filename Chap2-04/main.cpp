#include <iostream>
using namespace std;

int main() {
	double arr[5];
	cout << size(arr) << "���� �Ǽ��� �Է� >> ";
	for (int i = 0; i < 5; i++)
		cin >> arr[i];
	double biggest = arr[0];
	for (int i = 0; i < 5; i++)
		if (arr[i] > biggest) biggest = arr[i];
	cout << "ū �� = " << biggest;
}