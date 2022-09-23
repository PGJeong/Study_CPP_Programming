#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Book {
	char* title;
	int price;
public:
	Book(const char* title, int price) {
		this->title = new char[strlen(title) + 1];
		strcpy(this->title, title);
		this->price = price;
	}
	Book(Book& book) {
		this->title = new char[strlen(book.title) + 1];
		strcpy(this->title, book.title);
		this->price = book.price;
	}
	~Book() {
		if (this->title)
			delete[] this->title;
	}
	void set(const char* title, int price) {
		if (this->title)
			delete[] this->title;
		this->title = new char[strlen(title) + 1];
		strcpy(this->title, title);
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