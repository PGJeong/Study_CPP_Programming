#include <iostream>
#include "Shape.h"
using namespace std;

#ifndef RECT_H
#define RECT_H

class Rect : public Shape {
	void draw() override { cout << "Rect" << endl; }
};

#endif // !RECT_H