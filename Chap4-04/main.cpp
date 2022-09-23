#include <iostream>
using namespace std;

class Sample {
	int* p;
	int size;
public:
	Sample(int n) { size = n; p = new int[n]; }
	void read();
	void write();
	int big();
	~Sample() { delete[] p; }
};
void Sample::read() {
	cout << "���� " << size << "���� �Է��ϼ��� >> ";
	for (int i = 0; i < size; i++)
		cin >> p[i];
}
void Sample::write() {
	for (int i = 0; i < size; i++)
		cout << i + 1 << "��° ���� : " << p[i] << endl;
}
int Sample::big() {
	int biggest = p[0];
	for (int i = 0; i < size; i++)
		if (biggest < p[i])
			biggest = p[i];
	return biggest;
}

int main() {
	Sample s(5);
	s.read();
	s.write();
	cout << endl << "���� ū ���� " << s.big() << endl;
}