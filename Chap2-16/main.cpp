#include <iostream>
using namespace std;

int main() {
	char input[10000];
	char alphabet[26];
	for (int i = 0; i < 26; i++)
		alphabet[i] = 'a' + i;
	int count[26] = { 0, };
	int amount = 0;

	cout << "���� �ؽ�Ʈ�� �Է��ϼ���. �ؽ�Ʈ�� ���� ';' �Դϴ� >> " << endl;
	cin.getline(input, size(input), ';');

	for (int i = 0; i < strlen(input); i++) {
		for (int j = 0; j < size(alphabet); j++)
			if (input[i] == alphabet[j] || input[i] == alphabet[j] - 32)
				count[j]++;
	}

	for (int i = 0; i < size(count); i++)
		amount += count[i];
	cout << "�� ���ĺ� �� : " << amount << endl << endl;

	for (int i = 0; i < size(alphabet); i++) {
		cout << alphabet[i] << " (" << count[i] << ")\t: ";
		for (int j = 0; j < count[i]; j++)
			cout << '*';
		cout << endl;
	}
}