#include <iostream>
#include <cstring>
#pragma warning (disable: 4996)
using namespace std;

int main() {
	char input[100];
	while (true) {
		cout << "dsf>> ";
		cin.getline(input, size(input));
		int operand1 = atoi(strtok(input, " "));
		char *opr = strtok(NULL, " ");
		int operand2 = atoi(strtok(NULL, " "));
		cout << operand1 << ' ' << opr << ' ' << operand2 << " = ";
		if (strcmp(opr, "+") == 0) cout << operand1 + operand2 << endl;
		else if (strcmp(opr, "-") == 0) cout << operand1 - operand2 << endl;
		else if (strcmp(opr, "*") == 0) cout << operand1 * operand2 << endl;
		else if (strcmp(opr, "/") == 0) cout << operand1 / operand2 << endl;
		else if (strcmp(opr, "%") == 0) cout << operand1 % operand2 << endl;
		else cout << "계산할 수 없음" << endl;
	}
}