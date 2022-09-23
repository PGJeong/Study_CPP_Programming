#include <iostream>
using namespace std;

int main() {
	int profit = 0; // 매출
	int qty; // 수량
	int amt; // 가격
	char coffee[100];
	cout << "에스프레소 2000원 / 아메리카노 2300원 / 카푸치노 2500원 " << endl;
	do {
		cout << endl << "주문 >> ";
		cin >> coffee >> qty;
		if (strcmp(coffee, "에스프레소") == 0) amt = 2000 * qty;
		else if (strcmp(coffee, "아메리카노") == 0) amt = 2300 * qty;
		else if (strcmp(coffee, "카푸치노") == 0) amt = 2500 * qty;
		else {
			cout << "다시 주문해 주세요" << endl;
			continue;
		}
		cout << amt << "원 입니다" << endl;
		profit += amt;
	} while (profit < 20000);
	cout << endl << "총 매출 : " << profit << "원... 종료" << endl;
}