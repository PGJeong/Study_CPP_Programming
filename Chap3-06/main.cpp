#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class EvenRandom {
public:
	EvenRandom();
	int next();
	int nextInRange(int min, int max);
};
EvenRandom::EvenRandom() {
	srand((unsigned)time(0));
}
int EvenRandom::next() {
	int num = rand();
	if (num % 2 == 0) return num;
	else return num - 1;
}
int EvenRandom::nextInRange(int min, int max) {
	min /= 2; max /= 2;
	return (rand() % (max - min + 1) + min) * 2;
}

int main() {
	EvenRandom r;
	cout << "-- 0 ���� " << RAND_MAX << " ������ ���� ���� 10�� (¦��)" << endl;
	for (int i = 0; i < 10; i++) {
		int n = r.next();
		cout << n << ' ';
	}
	cout << endl << "-- 2 ���� " << "10 ������ ���� ���� 10�� (¦��)" << endl;
	for (int i = 0; i < 10; i++) {
		int n = r.nextInRange(2, 10);
		cout << n << ' ';
	}
	cout << endl;
}