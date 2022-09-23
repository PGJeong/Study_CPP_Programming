#include <iostream>
using namespace std;

#include "header.h" // using 지시에 아래에 include 해야하는 이유??

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
		case 4: cout << "예약시스템을 종료합니다..." << endl; break;
		default: cout << "다시 입력하세요..." << endl; break;
		}
	}
}

void Console::showTitle() { 
	cout << "*** 한성항공 예약 시스템 ***" << endl << endl;
}
int Console::selectMenu() {
	int cmd;
	cout << "예약(1), 취소(2), 보기(3), 종료(4) >> ";
	cin >> cmd; return cmd;
}
int Console::selectTime() {
	int cmd;
	cout << "07시(1), 12시(2), 17시(3) >> ";
	cin >> cmd; return cmd;
}
string Console::inputName() {
	string input;
	cout << "이름 입력 >> ";
	cin >> input; return input;
}
int Console::selectSeatNo() {
	int cmd;
	cout << "좌석 번호 >> ";
	cin >> cmd; return cmd;
}

Schdule::Schdule(string time) { seat = new Seat[8]; this->time = time; }
Schdule::~Schdule() { delete[] seat; }
void Schdule::reserve(int seatNo, string name) { seat[seatNo - 1].reserve(name); }
void Schdule::cancel(int seatNo, string name) {
	if (seat[seatNo - 1].getName() == name) {
		seat[seatNo - 1].cancel();
		cout << name << "님의 예약이 취소되었습니다..." << endl;
	}
	else cout << name << "님을 찾을 수 없습니다..." << endl;
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