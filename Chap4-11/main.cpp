#include <iostream>
using namespace std;

class Container {
	int size; // 현재 저장 량, 최대 저장량은 10
public:
	Container() { size = 10; }
	void fill() { size = 10; } // 최대량으로 채우기
	void consume(int consume) { size -= consume; if (size < 0) size = 0; } // 1만큼 소모하기
	int getSize() { return size; } // 현재 크기 리턴
};

class CoffeeVandingMachine {
	Container tong[3]; // tong[0]은 커피, tong[1]은 물, tong[2]는 설탕
	bool quantityCheck();
	void fill() {
		tong[0].fill(); tong[1].fill(); tong[2].fill(); show();
	} // 3개의 통을 모두 10으로 채움
	void selectEspresso() {
		tong[0].consume(1); tong[1].consume(1); tong[2].consume(0);
		if (quantityCheck())
			cout << "에스프레소 드세요" << endl;
	} // 커피 1, 물 1 소모
	void selectAmericano() {
		tong[0].consume(1); tong[1].consume(2); tong[2].consume(0);
		if (quantityCheck())
			cout << "아메리카노 드세요" << endl;
	} // 커피 1, 물 2 소모
	void selectSugarCoffee() {
		tong[0].consume(1); tong[1].consume(2); tong[2].consume(1);
		if (quantityCheck())
			cout << "설탕커피 드세요" << endl;
	} // 커피 1 물 2, 설탕 1 소모
	void show() {
		cout << "커피 " << tong[0].getSize() << ", 물 " << tong[1].getSize() << ", 설탕 " << tong[2].getSize() << endl;
	} // 현재 잔량 출력
public:
	void run(); // 커피 자판기 작동
};

bool CoffeeVandingMachine::quantityCheck() {
	if (tong[0].getSize() <= 0 || tong[1].getSize() <= 0 || tong[2].getSize() <= 0) {
		cout << "원료가 부족합니다!" << endl;
		return false;
	}
	else return true;
}

void CoffeeVandingMachine::run() {
	int userInput;
	cout << "***** 커피 자판기를 작동합니다 *****" << endl;
	while (true) {
		cout << endl << "메뉴를 눌러주세요 (1: 에스프레소, 2: 아메리카노, 3: 설탕커피, 4: 잔량보기, 5: 채우기) >> ";
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
			cout << "오류! 다시 입력해주세요..." << endl;
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