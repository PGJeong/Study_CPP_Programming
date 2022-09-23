#include <iostream>
using namespace std;

class ArrayUtility {
	ArrayUtility() {}
public:
	static int* concat(int s1[], int s2[], int size) {
		int* tmp = new int[size * 2];
		for (int i = 0; i < size * 2; i++) {
			if (i < size)
				tmp[i] = s1[i];
			else
				tmp[i] = s2[i - size];
		}
		return tmp;
	}
	static int* remove(int s1[], int s2[], int size, int& retSize) {
		int overlap = 0;
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++)
				if (s1[i] == s2[j]) overlap++;
		}
		int* overlappedArr = new int[overlap];
		int cnt = 0;
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++)
				if (s1[i] == s2[j]) { overlappedArr[cnt] = s1[i]; cnt++; }
		}
		retSize = size - overlap;
		int* tmp = new int[retSize];
		bool isOverlapped;
		cnt = 0;
		for (int i = 0; i < size; i++) {
			isOverlapped = false;
			for (int j = 0; j < overlap; j++)
				if (s1[i] == overlappedArr[j]) isOverlapped = true;

			if (isOverlapped == false) {
				tmp[cnt] = s1[i];
				cnt++;
			}
		}
		delete[] overlappedArr;
		return tmp;
	}
};

int main() {
	int arr1[5], arr2[5];
	int* ptr1, * ptr2, retSize;

	cout << "정수를 5개 입력하라 (arr1) >> ";
	for (int i = 0; i < size(arr1); i++)
		cin >> arr1[i];

	cout << "정수를 5개 입력하라 (arr2) >> ";
	for (int i = 0; i < size(arr2); i++)
		cin >> arr2[i];

	ptr1 = ArrayUtility::concat(arr1, arr2, size(arr1));

	cout << endl << "- concat" << endl;
	for (int i = 0; i < size(arr1) + size(arr2); i++)
		cout << ptr1[i] << ' ';
	cout << endl;

	ptr2 = ArrayUtility::remove(arr1, arr2, size(arr1), retSize);

	cout << endl << "- remove" << endl;
	for (int i = 0; i < retSize; i++)
		cout << ptr2[i] << ' ';
	cout << endl;

	delete[] ptr1;
	delete[] ptr2;
}