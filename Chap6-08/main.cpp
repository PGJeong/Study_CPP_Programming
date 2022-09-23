#include <iostream>
using namespace std;

class Trace {
	Trace() {}
	static string tag[];
	static string log[];
	static int cnt;
public:
	static void put(string tagInput, string logInput) {
		tag[cnt] = tagInput; log[cnt] = logInput; cnt++;
	}
	static void print(string tagInput = "") {
		if (tagInput == "") {
			cout << "--- " << "���" << " �±��� Trace ������ ����մϴ� ---" << endl;
			for (int i = 0; i < cnt; i++)
				cout << tag[i] << " : " << log[i] << endl;
		}
		else {
			cout << "--- " << tagInput << " �±��� Trace ������ ����մϴ� ---" << endl;
			for (int i = 0; i < cnt; i++)
				if (tag[i] == tagInput) cout << tag[i] << " : " << log[i] << endl;
		}
	}
};

string Trace::tag[100];
string Trace::log[100];
int Trace::cnt = 0;

void f() {
	int a, b, c;
	cout << "�� ���� ������ �Է��ϼ��� >> ";
	cin >> a >> b;
	Trace::put("f()", "������ �Է� �޾���");
	c = a + b;
	Trace::put("f()", "�� ���");
	cout << "���� " << c << endl;
}

int main() {
	Trace::put("main()", "���α׷� ����");
	f();
	Trace::put("main()", "����");
	Trace::print("f()");
	Trace::print();
}