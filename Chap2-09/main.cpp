#include <iostream>
#include <string>
using namespace std;

int main() {
	string name, address, age;
	cout << "�̸� >> ";
	getline(cin, name);
	cout << "�ּ� >> ";
	getline(cin, address);
	cout << "���� >> ";
	getline(cin, age);
	cout << name << ", " << address << ", " << age << "��" << endl;
}