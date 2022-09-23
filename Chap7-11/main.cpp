#include <iostream>
using namespace std;

class Stack {
	int tos;
	int arr[10];
public:
	Stack() { tos = 0; }
	Stack& operator << (int num) {
		arr[tos] = num;
		tos++;
		return *this;
	}
	bool operator ! () {
		if (tos == 0) return true;
		else return false;
	}
	void operator >> (int &num) {
		tos--;
		num = arr[tos];
	}
};

int main() {
	Stack stack;
	stack << 3 << 5 << 10;

	while (true) {
		if (!stack) break;
		int x;
		stack >> x;
		cout << x << ' ';
	}

	cout << endl;
}