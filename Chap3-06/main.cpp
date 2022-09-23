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
	cout << "-- 0 에서 " << RAND_MAX << " 까지의 랜덤 정수 10개 (짝수)" << endl;
	for (int i = 0; i < 10; i++) {
		int n = r.next();
		cout << n << ' ';
	}
	cout << endl << "-- 2 에서 " << "10 까지의 랜덤 정수 10개 (짝수)" << endl;
	for (int i = 0; i < 10; i++) {
		int n = r.nextInRange(2, 10);
		cout << n << ' ';
	}
	cout << endl;
}