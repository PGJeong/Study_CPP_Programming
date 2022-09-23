#include <iostream>
using namespace std;

template <class T>
bool equalArrays(T src1[], T src2[], int size) {
	bool isEqual = true;
	for (int i = 0; i < size; i++)
		if (src1[i] != src2[i]) isEqual = false;
	return isEqual;
}

int main() {
	int x[] = { 1, 10, 100, 5, 4 };
	int y[] = { 1, 10, 100, 5, 4 };
	if (equalArrays(x, y, 5)) cout << "Same" << endl;
	else cout << "Different" << endl;

	char a[] = { 'a', 'c', 'e', 'g', 'i'};
	char b[] = { 'a', 'c', 'e', 'g', 'k' };
	if (equalArrays(a, b, 5)) cout << "Same" << endl;
	else cout << "Different" << endl;
}