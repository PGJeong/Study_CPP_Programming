#include <iostream>
using namespace std;

int main() {
	int longest = 0;
	char name[30] = "";
	char longestName[30];
	cout << "5���� �̸��� ';'�� �����Ͽ� �Է� >> " << endl;
	for (int i = 0; i < 5; i++) {
		int length = 0;
		cin.getline(name, size(name), ';');
		cout << (i + 1) << " : " << name << endl;
		for (int j = 0; j < size(name); j++)
			if (name[j] != '\0') length++; // �̸��� ���� ���ϱ�
		if (length > longest) {
			longest = length;
			strcpy_s(longestName, name); 
		}
	}
	cout << "���� �� �̸��� : " << longestName << endl;
}