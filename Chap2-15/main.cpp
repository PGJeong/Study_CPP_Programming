#include <iostream>
using namespace std;

int main() {
	char oprnd1[30];
	char opr[30];
	char oprnd2[30];
	while (1) {
		cout << endl << " >> ";
		cin.getline(oprnd1, size(oprnd1), ' ');
		cin.getline(opr, size(opr), ' ');
		cin.getline(oprnd2, size(oprnd2));
		cout << oprnd1 << ' ' << opr << ' ' << oprnd2 << " = ";
		if (strcmp(opr, "+") == 0) cout << atoi(oprnd1) + atoi(oprnd2) << endl;
		else if (strcmp(opr, "-") == 0) cout << atoi(oprnd1) - atoi(oprnd2) << endl;
		else if (strcmp(opr, "*") == 0) cout << atoi(oprnd1) * atoi(oprnd2) << endl;
		else if (strcmp(opr, "/") == 0) cout << atoi(oprnd1) / atoi(oprnd2) << endl;
		else if (strcmp(opr, "%") == 0) cout << atoi(oprnd1) % atoi(oprnd2) << endl;
		else cout << "계산할 수 없음" << endl;
	}
}