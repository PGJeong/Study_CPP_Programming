#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	cout << "���ڿ� �Է� >> ";
	getline(cin, str);
	for (int i = size(str) - 1; i >= 0; i--) {
		for (int j = 0; j < i + 1; j++)
			cout << str[j];
		cout << endl;
	}
}