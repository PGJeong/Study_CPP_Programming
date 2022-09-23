#include <iostream>
using namespace std;

class Container {
	int size; // ���� ���� ��, �ִ� ���差�� 10
public:
	Container() { size = 10; }
	void fill() { size = 10; } // �ִ뷮���� ä���
	void consume(int consume) { size -= consume; if (size < 0) size = 0; } // 1��ŭ �Ҹ��ϱ�
	int getSize() { return size; } // ���� ũ�� ����
};

class CoffeeVandingMachine {
	Container tong[3]; // tong[0]�� Ŀ��, tong[1]�� ��, tong[2]�� ����
	bool quantityCheck();
	void fill() {
		tong[0].fill(); tong[1].fill(); tong[2].fill(); show();
	} // 3���� ���� ��� 10���� ä��
	void selectEspresso() {
		tong[0].consume(1); tong[1].consume(1); tong[2].consume(0);
		if (quantityCheck())
			cout << "���������� �弼��" << endl;
	} // Ŀ�� 1, �� 1 �Ҹ�
	void selectAmericano() {
		tong[0].consume(1); tong[1].consume(2); tong[2].consume(0);
		if (quantityCheck())
			cout << "�Ƹ޸�ī�� �弼��" << endl;
	} // Ŀ�� 1, �� 2 �Ҹ�
	void selectSugarCoffee() {
		tong[0].consume(1); tong[1].consume(2); tong[2].consume(1);
		if (quantityCheck())
			cout << "����Ŀ�� �弼��" << endl;
	} // Ŀ�� 1 �� 2, ���� 1 �Ҹ�
	void show() {
		cout << "Ŀ�� " << tong[0].getSize() << ", �� " << tong[1].getSize() << ", ���� " << tong[2].getSize() << endl;
	} // ���� �ܷ� ���
public:
	void run(); // Ŀ�� ���Ǳ� �۵�
};

bool CoffeeVandingMachine::quantityCheck() {
	if (tong[0].getSize() <= 0 || tong[1].getSize() <= 0 || tong[2].getSize() <= 0) {
		cout << "���ᰡ �����մϴ�!" << endl;
		return false;
	}
	else return true;
}

void CoffeeVandingMachine::run() {
	int userInput;
	cout << "***** Ŀ�� ���Ǳ⸦ �۵��մϴ� *****" << endl;
	while (true) {
		cout << endl << "�޴��� �����ּ��� (1: ����������, 2: �Ƹ޸�ī��, 3: ����Ŀ��, 4: �ܷ�����, 5: ä���) >> ";
		cin >> userInput;
		switch (userInput) {
		case 1:
			selectEspresso(); break;
		case 2:
			selectAmericano(); break;
		case 3:
			selectSugarCoffee(); break;
		case 4:
			show(); break;
		case 5:
			fill(); break;
		default:
			cout << "����! �ٽ� �Է����ּ���..." << endl;
			cin.clear();
			cin.ignore(100, '\n');
			break;
		}
	}
}

int main() {
	CoffeeVandingMachine obj;
	obj.run();
}