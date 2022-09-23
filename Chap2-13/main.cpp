#include <iostream>
#include <string>
using namespace std;

int main() {
	int cmd;
	int per;
	string menu[4] = { "짬뽕", "짜장", "군만두", "종료" };

	cout << "***** 승리장에 오신 것을 환영합니다 *****" << endl;
	do {;
		cout << endl << "짬뽕:1, 짜장:2, 군만두:3, 종료:4 >> ";
		cin >> cmd;
		if (cmd == 4) break;
		if (cmd < 0 || cmd > 4) {
			cout << "다시 주문하세요!!" << endl;
			continue;
		}
		cout << "몇인분? >> ";
		cin >> per;
		cout << menu[cmd - 1] << " " << per << "인분 나왔습니다" << endl;
	} while (cmd != 4);
	cout << "오늘 영업은 끝났습니다." << endl;
}