#include <iostream>
using namespace std;

class LoopAdder {
	string name;
	int x, y, sum;
	void read();
	void write();
protected:
	LoopAdder(string name = "") { this->name = name; }
	int getX() { return x; }
	int getY() { return y; }
	virtual int calculate() = 0;
public:
	void run();
};

void LoopAdder::read() {
	cout << name << " : " << endl;
	cout << "ó�� ������ �ι�° ������ ���մϴ�. �� ���� �Է��ϼ��� >> ";
	cin >> x >> y;
}

void LoopAdder::write() {
	cout << x << "���� " << y << "������ �� = " << sum << endl;
}

void LoopAdder::run() {
	read();
	sum = calculate();
	write();
}

class ForLoopAdder : public LoopAdder {
	int calculate() final {
		int sum = 0;
		for (int i = getX(); i <= getY(); i++)
			sum += i;
		return sum;
	}
public:
	ForLoopAdder(string title) : LoopAdder(title) {}
};

int main() {
	ForLoopAdder forLoop("For Loop");
	forLoop.run();
}