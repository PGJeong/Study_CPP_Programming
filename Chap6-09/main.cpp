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
	Board::add("�߰����� ���� ���� ���� �����Դϴ�");
	Board::add("�ڵ� ����� ���� �̿�ٶ��ϴ�");
	Board::print();
	Board::add("�ڵ� ������ȸ �Ի��ڴ� ȫ�浿");
	Board::print();
}