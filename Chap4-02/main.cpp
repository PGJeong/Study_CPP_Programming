#include <iostream>
using namespace std;

int main() {
	int* arr = new int[5];
	double sum = 0;
	cout << "���� 5�� �Է� >> ";
	for (int i = 0; i < 5; i++)
		cin >> *(arr + i);
	for (int i = 0; i < 5; i++)
		sum += arr[i];
	cout << "��� " << sum / (_msize(arr) / sizeof(int)); //  _msize(void*) �Լ��� heap ������ �Ҵ�� �޸��� ũ�⸦ �ҷ��´�
	delete[] arr;
}