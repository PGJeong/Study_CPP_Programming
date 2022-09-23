#include <iostream>
using namespace std;

class SortedArray {
	int size;
	int* p;
	void sort() {
		int swp;
		for (int i = 0; i < size; i++) {
			for (int j = i; j < size; j++) {
				if (p[i] < p[j] || p[i] == p[j]);
				else {
					swp = p[i];
					p[i] = p[j];
					p[j] = swp;
				}
			}
		}
	}
public:
	SortedArray() : SortedArray(NULL, 0) {}
	SortedArray(SortedArray& src) {
		size = src.size;
		p = new int[size];
		for (int i = 0; i < size; i++)
			p[i] = src.p[i];
	}
	SortedArray(int p[], int size) {
		this->size = size;
		this->p = new int[size];
		for (int i = 0; i < size; i++)
			this->p[i] = p[i];
	}
	~SortedArray() { if(p) delete[] p; }
	SortedArray operator + (SortedArray& op2) {
		SortedArray tmp;
		tmp.size = size + op2.size;
		tmp.p = new int[tmp.size];
		for (int i = 0; i < size; i++)
			tmp.p[i] = p[i];
		for (int i = 0; i < op2.size; i++)
			tmp.p[i + size] = op2.p[i];
		return tmp;
	}
	SortedArray& operator = (const SortedArray& op2) {
		if(p) delete[] p;
		size = op2.size;
		p = new int[size];
		for (int i = 0; i < size; i++)
			p[i] = op2.p[i];
		return *this;
	}
	void show() {
		sort();
		cout << "배열 출력 : ";
		for (int i = 0; i < size; i++)
			cout << p[i] << ' ';
		cout << endl;
	}
};

int main() {
	int n[] = { 2, 20, 6 };
	int m[] = { 10, 7, 8, 30 };
	SortedArray a(n, 3), b(m, 4), c;

	c = a + b;

	a.show();
	b.show();
	c.show();
}