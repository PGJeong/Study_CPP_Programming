#include <iostream>
using namespace std;

int main() {
	int profit = 0; // ����
	int qty; // ����
	int amt; // ����
	char coffee[100];
	cout << "���������� 2000�� / �Ƹ޸�ī�� 2300�� / īǪġ�� 2500�� " << endl;
	do {
		cout << endl << "�ֹ� >> ";
		cin >> coffee >> qty;
		if (strcmp(coffee, "����������") == 0) amt = 2000 * qty;
		else if (strcmp(coffee, "�Ƹ޸�ī��") == 0) amt = 2300 * qty;
		else if (strcmp(coffee, "īǪġ��") == 0) amt = 2500 * qty;
		else {
			cout << "�ٽ� �ֹ��� �ּ���" << endl;
			continue;
		}
		cout << amt << "�� �Դϴ�" << endl;
		profit += amt;
	} while (profit < 20000);
	cout << endl << "�� ���� : " << profit << "��... ����" << endl;
}