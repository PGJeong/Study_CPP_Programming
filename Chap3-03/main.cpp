#include <iostream>
using namespace std;

class Account {
	string name;
	int id;
	int balance; // �ܾ�
public:
	Account(string name, int id, int balance);
	string getOwner(); // ������
	int inquary(); // �ܾ���ȸ
	int deposit(int deposit); // �Ա�
	int withdraw(int withdraw); // ���
};
Account::Account(string name, int id, int balance) {
	this->name = name; this->id = id; this->balance = balance;
}
string Account::getOwner() { return name; }
int Account::inquary() { return balance; }
int Account::deposit(int deposit) { balance += deposit; return deposit; }
int Account::withdraw(int withdraw) { balance -= withdraw; return withdraw; }

int main() {
	Account a("kitae", 1, 5000);
	a.deposit(50000);
	cout << a.getOwner() << "�� �ܾ���" << a.inquary() << endl;
	int money = a.withdraw(20000);
	cout << a.getOwner() << "�� �ܾ���" << a.inquary() << endl;
}