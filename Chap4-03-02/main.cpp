#include <iostream>
#include <string>
using namespace std;

int main() {
	string input;
	cout << "���ڿ� �Է� >> ";
	getline(cin, input);
	int count = 0;
	int location = 0;
	for (int i = 0; i < input.length(); i++)
		if (input.at(i) == 'a')
			count++;
	cout << "���� 'a'�� ���� : " << count << endl << endl;
	for (int i = 0; i < count; i++) {
		cout << i + 1 << "��° 'a'�� ��ġ : " << input.find('a', location) << endl;
		location = input.find('a', location) + 1;
	}
}