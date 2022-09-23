#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	cout << "문자열 입력 >> ";
	getline(cin, str);
	for (int i = 0; i < size(str); i++) {
		for (int j = 0; j < i + 1; j++)
			cout << str[j];
		cout << endl;
	}
}