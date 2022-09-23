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
			cout << "--- " << "모든" << " 태그의 Trace 정보를 출력합니다 ---" << endl;
			for (int i = 0; i < cnt; i++)
				cout << tag[i] << " : " << log[i] << endl;
		}
		else {
			cout << "--- " << tagInput << " 태그의 Trace 정보를 출력합니다 ---" << endl;
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
	cout << "두 개의 정수를 입력하세요 >> ";
	cin >> a >> b;
	Trace::put("f()", "정수를 입력 받았음");
	c = a + b;
	Trace::put("f()", "합 계산");
	cout << "합은 " << c << endl;
}

int main() {
	Trace::put("main()", "프로그램 시작");
	f();
	Trace::put("main()", "종료");
	Trace::print("f()");
	Trace::print();
}