#include <iostream>
#include "Shape.h"
using namespace std;

#ifndef LINE_H
#define LINE_H

class Line : public Shape {
	void draw() override { cout << "Line" << endl; }
};

#endif // !LINE_H