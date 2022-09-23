#include <iostream>
#include "Shape.h"
using namespace std;

#ifndef CIRCLE_H
#define CIRCLE_H

class Circle : public Shape {
	void draw() override { cout << "Circle" << endl; }
};

#endif // !CIRCLE_H