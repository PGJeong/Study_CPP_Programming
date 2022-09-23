#include <iostream>
using namespace std;

class Circle {
	int radius;
public:
	Circle(int radius = 0) { this->radius = radius; }
	void show() { cout << "radius = " << radius << "ÀÎ ¿ø" << endl; }
	friend Circle operator+(int add, Circle& a);
};

Circle operator+(int add, Circle& a) {
	Circle tmp;
	tmp.radius = a.radius + add;
	return tmp;
}

int main() {
	Circle a(5), b(4);
	b = 1 + a;
	a.show();
	b.show();
}