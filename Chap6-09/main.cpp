#include <iostream>
#include <string>
using namespace std;

class Board {
	Board() {};
	static string board[];
	static int count;
public:
	static void add(string contents) {
		board[count] = contents;
		count++;
	}
	static void print() {
		cout << "*** Board ***" << endl;
		for (int i = 0; i < count; i++)
			cout << i << ": " << board[i] << endl;
	}
};

string Board::board[100];
int Board::count = 0;

int main() {
	Board::add("중간고사는 감독 없는 자율 시험입니다");
	Board::add("코딩 라운지 많이 이용바랍니다");
	Board::print();
	Board::add("코딩 경진대회 입상자는 홍길동");
	Board::print();
}