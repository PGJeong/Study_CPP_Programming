#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Random {
public:
	Random();
	int next();
	int nextInRange(int min, int max);
};
Random::Random() {
	srand((unsigned)time(0));
}
int Random::next() {
	return rand();
}
int Random::nextInRange(int min, int max) {
	return rand() % (max - min + 1) + min;
}

int main() {
	Random r;
	cout << "-- 0 ���� " << RAND_MAX << " ������ ���� ���� 10��" << endl;
	for (int i = 0; i < 10; i++) {
		int n = r.next();
		cout << n << ' ';
	}
	cout << endl << "-- 2 ���� " << "4 ������ ���� ���� 10��" << endl;
	for (int i = 0; i < 10; i++) {
		int n = r.nextInRange(2, 4);
		cout << n << ' ';
	}
	cout << endl;
}