#include <iostream>
using namespace std;

class AbstractStack {
public:
	virtual bool push(int n) = 0;
	virtual bool pop(int& n) = 0;

	virtual int size() = 0;
};

class IntStack : public AbstractStack {
	int stack[10];
	int tos = 0;
public:
	bool push(int n) final {
		if (tos < 10) { stack[tos] = n; tos++; return true; }
		else return false;
	}
	bool pop(int& n) final {
		if (tos > 0) { tos--; n = stack[tos]; return true; }
		else return false;
	}
	int size() final {
		return 10 - tos;
	}
};

int main() {
	IntStack stack;

	for (int i = 0; i < 11; i++) {
		if (stack.push(i)) cout << i << '/' << stack.size() << ' ';
		else cout << "stack full" << endl;
	}

	int n;

	for (int i = 0; i < 11; i++) {
		if (stack.pop(n)) cout << n << ' ';
		else cout << "stack empty" << endl;
	}
}