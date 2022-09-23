#include <iostream>
#include <string>
using namespace std;

int main() {
	string input;
	cout << "문자열 입력 >> ";
	getline(cin, input);
	int count = 0;
	for (int i = 0; i < input.length(); i++) {
		if (input.at(i) == 'a')
			count++;
	}
	cout << "문자 'a'는 " << count << "개 있습니다." << endl;
}