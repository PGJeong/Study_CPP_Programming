#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Random {
	Random() {}
public:
	static void seed() { srand((unsigned)time(0)); }
	static int nextInt(int min = 0, int max = RAND_MAX) {
		return rand() % (max - min + 1) + min;
	}
	static char nextAlphabet() {
		if (rand() % 2)
			return rand() % ('Z' - 'A' + 1) + 'A';
		else
			return rand() % ('z' - 'a' + 1) + 'a';
	}
	static double nextDouble() {
		return (double)rand() / RAND_MAX;
	}
};

int main() {
	Random::seed();

	cout << endl << "*** 1¿¡¼­ 100±îÁöÀÇ ·£´ý Á¤¼ö 10°³" << endl;
	for (int i = 0; i < 10; i++)
		cout << Random::nextInt(1, 100) << ' ';

	cout << endl;

	cout << endl << "*** ·£´ý ¾ËÆÄºª 10°³" << endl;
	for (int i = 0; i < 10; i++)
		cout << Random::nextAlphabet() << ' ';

	cout << endl;

	cout << endl << "*** ·£´ý ½Ç¼ö 10°³" << endl;
	for (int i = 0; i < 10; i++) {
		cout << Random::nextDouble() << ' ';
		if (i == 4) cout << endl;
	}

	cout << endl;
}