#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Book {
	string title;
	int price;
public:
	Book(string title, int price) {
		this->title = title;
		this->price = price;
	}
	~Book() {}
	void set(string title, int price) {
		this->title = title;
		this->price = price;
	}
	void show() { cout << title << ' ' << price << "원" << endl; }
};

int main() {
	Book cpp("명품 C++", 10000);
	Book java = cpp;
	java.set("명품 Java", 12000);
	cpp.show();
	java.show();
}