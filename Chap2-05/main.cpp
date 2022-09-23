#include <iostream>
using namespace std;

int main() {
	char input[100] = "";
	int count = 0;
	cout << "문자들을 입력하라(100개 미만) >> ";
	cin.getline(input, size(input));
	for (int i = 0; i < size(input); i++) {
		if (input[i] == 'x') count++;
		if (input[i] == '\0') break;
	}
	cout << "x의 개수는 " << count;
}