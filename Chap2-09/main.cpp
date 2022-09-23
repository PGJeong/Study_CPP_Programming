#include <iostream>
#include <string>
using namespace std;

int main() {
	string name, address, age;
	cout << "이름 >> ";
	getline(cin, name);
	cout << "주소 >> ";
	getline(cin, address);
	cout << "나이 >> ";
	getline(cin, age);
	cout << name << ", " << address << ", " << age << "세" << endl;
}