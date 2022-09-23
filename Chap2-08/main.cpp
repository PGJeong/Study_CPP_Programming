#include <iostream>
using namespace std;

int main() {
	int longest = 0;
	char name[30] = "";
	char longestName[30];
	cout << "5명의 이름을 ';'로 구분하여 입력 >> " << endl;
	for (int i = 0; i < 5; i++) {
		int length = 0;
		cin.getline(name, size(name), ';');
		cout << (i + 1) << " : " << name << endl;
		for (int j = 0; j < size(name); j++)
			if (name[j] != '\0') length++; // 이름의 길이 구하기
		if (length > longest) {
			longest = length;
			strcpy_s(longestName, name); 
		}
	}
	cout << "가장 긴 이름은 : " << longestName << endl;
}