#include <iostream>
using namespace std;

class Statistics {
	int size;
	int *data;
public:
	Statistics() { size = 0; }
	bool operator ! () {
		if (size == 0) return true;
		else return false;
	}
	Statistics& operator << (int num) {
		size++;
		int* temp = new int[size];
		for (int i = 0; i < size - 1; i++)
			temp[i] = data[i];
		temp[size - 1] = num;

		delete[] data;
		data = temp;
		return *this;
	}
	void operator ~ () {
		for (int i = 0; i < size; i++)
			cout << data[i] << ' ';
		cout << endl;
	}
	void operator >> (int &avg) {
		int sum = 0;
		for (int i = 0; i < size; i++)
			sum += data[i];
		avg = sum / size;
	}
};

int main() {
	Statistics stat;
	if (!stat) cout << "현재 통계 데이터가 없습니다" << endl;

	int x[5];
	cout << "5개의 정수를 입력하라 >> ";
	for (int i = 0; i < 5; i++) cin >> x[i];

	for (int i = 0; i < 5; i++) stat << x[i];
	stat << 100 << 200;
	~stat;

	int avg;
	stat >> avg;
	cout << "avg = " << avg << endl;
}