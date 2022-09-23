#include <iostream>
using namespace std;

int main() {
	double arr[5];
	cout << size(arr) << "개의 실수를 입력 >> ";
	for (int i = 0; i < 5; i++)
		cin >> arr[i];
	double biggest = arr[0];
	for (int i = 0; i < 5; i++)
		if (arr[i] > biggest) biggest = arr[i];
	cout << "큰 수 = " << biggest;
}