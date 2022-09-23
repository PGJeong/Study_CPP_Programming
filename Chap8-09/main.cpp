#include <iostream>
using namespace std;

#include "header.h" // using ���ÿ� �Ʒ��� include �ؾ��ϴ� ����??

AirlineBook::AirlineBook() {
	schdule = new Schdule[3]{ Schdule("07"), Schdule("12"), Schdule("17") };
}
AirlineBook::~AirlineBook() { delete[] schdule; }
void AirlineBook::reserve() {
	int time = Console::selectTime();
	schdule[time - 1].show();
	schdule[time - 1].reserve(Console::selectSeatNo(), Console::inputName());
}
void AirlineBook::cancel() {
	int time = Console::selectTime();
	schdule[time - 1].show();
	schdule[time - 1].cancel(Console::selectSeatNo(), Console::inputName());
}
void AirlineBook::show() {
	for (int i = 0; i < 3; i++)
		schdule[i].show();
}
void AirlineBook::system() {
	int cmd = 0;
	Console::showTitle();
	while (cmd != 4) {
		cmd = Console::selectMenu();
		switch (cmd) {
		case 1: reserve(); break;
		case 2: cancel(); break;
		case 3: show(); break;
		case 4: cout << "����ý����� �����մϴ�..." << endl; break;
		default: cout << "�ٽ� �Է��ϼ���..." << endl; break;
		}
	}
}

void Console::showTitle() { 
	cout << "*** �Ѽ��װ� ���� �ý��� ***" << endl << endl;
}
int Console::selectMenu() {
	int cmd;
	cout << "����(1), ���(2), ����(3), ����(4) >> ";
	cin >> cmd; return cmd;
}
int Console::selectTime() {
	int cmd;
	cout << "07��(1), 12��(2), 17��(3) >> ";
	cin >> cmd; return cmd;
}
string Console::inputName() {
	string input;
	cout << "�̸� �Է� >> ";
	cin >> input; return input;
}
int Console::selectSeatNo() {
	int cmd;
	cout << "�¼� ��ȣ >> ";
	cin >> cmd; return cmd;
}

Schdule::Schdule(string time) { seat = new Seat[8]; this->time = time; }
Schdule::~Schdule() { delete[] seat; }
void Schdule::reserve(int seatNo, string name) { seat[seatNo - 1].reserve(name); }
void Schdule::cancel(int seatNo, string name) {
	if (seat[seatNo - 1].getName() == name) {
		seat[seatNo - 1].cancel();
		cout << name << "���� ������ ��ҵǾ����ϴ�..." << endl;
	}
	else cout << name << "���� ã�� �� �����ϴ�..." << endl;
}
void Schdule::show() {
	cout << time << " :\t";
	for (int i = 0; i < 8; i++)
		cout << seat[i].getName() << "\t";
	cout << endl;
}

Seat::Seat() { name = "---"; }
Seat::~Seat() {}
void Seat::reserve(string name) { this->name = name; }
void Seat::cancel() { name = "---"; }
string Seat::getName() { return name; }

int main() {
	AirlineBook* airlineBook = new AirlineBook;
	airlineBook->system();
	delete airlineBook;
}