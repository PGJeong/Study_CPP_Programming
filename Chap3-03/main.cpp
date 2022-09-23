#include <iostream>
using namespace std;

class Account {
	string name;
	int id;
	int balance; // ÀÜ¾×
public:
	Account(string name, int id, int balance);
	string getOwner(); // ¿¹±ÝÁÖ
	int inquary(); // ÀÜ¾×Á¶È¸
	int deposit(int deposit); // ÀÔ±Ý
	int withdraw(int withdraw); // Ãâ±Ý
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
	cout << a.getOwner() << "ÀÇ ÀÜ¾×Àº" << a.inquary() << endl;
	int money = a.withdraw(20000);
	cout << a.getOwner() << "ÀÇ ÀÜ¾×Àº" << a.inquary() << endl;
}