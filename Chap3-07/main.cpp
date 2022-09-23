#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class SelectableRandom {
	bool odd = true; // È¦¼ö(odd)´Â true, Â¦¼ö(even)´Â false
public:
	SelectableRandom(bool odd) { this->odd = odd; srand((unsigned)time(0)); }
	int random();
	int random(int min, int max);
};
int SelectableRandom::random() {
	int result = rand();
	if (this->odd == false) {
		if (result % 2 == 0) return result;
		else return result - 1;
	}
	if (this->odd == true) {
		if (result % 2 == 0) return result - 1;
		else return result;
	}
}
int SelectableRandom::random(int min, int max) {
	int result = rand() % (max - min + 1) + min;
	if (this->odd == false) {
		if (result % 2 == 0) return result;
		else return result - 1;
	}
	if (this->odd == true) {
		if (result % 2 == 0) return result - 1;
		else return result;
	}
}

int main() {
	SelectableRandom even(false);
	cout << "-- 0¿¡¼­ " << RAND_MAX << "±îÁöÀÇ Â¦¼ö ·£´ı Á¤¼ö 10°³" << endl;
	for (int i = 0; i < 10; i++) {
		cout << even.random() << ' ';
	}
	cout << endl << endl;

	SelectableRandom odd(true);
	cout << "-- 2¿¡¼­ 9±îÁöÀÇ È¦¼ö ·£´ı Á¤¼ö 10°³" << endl;
	for (int i = 0; i < 10; i++) {
		cout << odd.random(2, 9) << ' ';
	}
	cout << endl << endl;
}