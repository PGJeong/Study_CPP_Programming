#include <iostream>
using namespace std;

int main() {
	int* arr = new int[5];
	double sum = 0;
	cout << "정수 5개 입력 >> ";
	for (int i = 0; i < 5; i++)
		cin >> *(arr + i);
	for (int i = 0; i < 5; i++)
		sum += arr[i];
	cout << "평균 " << sum / (_msize(arr) / sizeof(int)); //  _msize(void*) 함수는 heap 영역에 할당된 메모리의 크기를 불러온다
	delete[] arr;
}