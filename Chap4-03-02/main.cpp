#include <iostream>
#include <string>
using namespace std;

int main() {
	string input;
	cout << "문자열 입력 >> ";
	getline(cin, input);
	int count = 0;
	int location = 0;
	for (int i = 0; i < input.length(); i++)
		if (input.at(i) == 'a')
			count++;
	cout << "문자 'a'의 개수 : " << count << endl << endl;
	for (int i = 0; i < count; i++) {
		cout << i + 1 << "번째 'a'의 위치 : " << input.find('a', location) << endl;
		location = input.find('a', location) + 1;
	}
}