#include <iostream>
using namespace std;

int main() {
	for (int i = 0; i < 100; i++) {
		cout << (i + 1) << "\t";
		if ((i + 1) % 10 == 0) cout << endl;
	}
}