#include <iostream>
#include <string>
using namespace std;

int main() {
	int cmd;
	int per;
	string menu[4] = { "«��", "¥��", "������", "����" };

	cout << "***** �¸��忡 ���� ���� ȯ���մϴ� *****" << endl;
	do {;
		cout << endl << "«��:1, ¥��:2, ������:3, ����:4 >> ";
		cin >> cmd;
		if (cmd == 4) break;
		if (cmd < 0 || cmd > 4) {
			cout << "�ٽ� �ֹ��ϼ���!!" << endl;
			continue;
		}
		cout << "���κ�? >> ";
		cin >> per;
		cout << menu[cmd - 1] << " " << per << "�κ� ���Խ��ϴ�" << endl;
	} while (cmd != 4);
	cout << "���� ������ �������ϴ�." << endl;
}