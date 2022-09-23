#include <iostream>
using namespace std;

#include "Line.h"
#include "Circle.h"
#include "Rect.h"

class UI {
	UI() {}
public:
	static void showTitle() { cout << "*** Graphic Editor ***" << endl; }
	static int selectMenu() {
		int cmd;
		cout << endl << "삽입(1), 삭제(2), 보기(3), 종료(4) >> ";
		cin >> cmd; return cmd;
	}
	static int selectFigure() {
		int cmd;
		cout << "Line(1), Circle(2), Rect(3) >> ";
		cin >> cmd; return cmd;
	}
	static int selectIndex() {
		int cmd;
		cout << "삭제하고자 하는 도형의 인덱스 >> ";
		cin >> cmd; return cmd;
	}
};

class GraphicEditor {
	Shape* pHead, * pTail;
	int count;
public:
	GraphicEditor() { pHead = NULL; pTail = NULL; count = -1; }
	void insert(int cmd) {
		switch (cmd)
		{
		case 1:
			if (!pHead) { pHead = new Line(); pTail = pHead; }
			else { pTail = pTail->add(new Line()); }
			cout << "Line 추가됨..." << endl; count++;
			break;
		case 2:
			if (!pHead) { pHead = new Circle(); pTail = pHead; }
			else { pTail = pTail->add(new Circle()); }
			cout << "Circle 추가됨..." << endl; count++;
			break;
		case 3:
			if (!pHead) { pHead = new Rect(); pTail = pHead; }
			else { pTail = pTail->add(new Rect()); }
			cout << "Rect 추가됨..." << endl; count++;
			break;
		default: cout << "다시 입력하세요..." << endl;
			break;
		}
	}
	void remove(int index) {
		if (index > count) {
			cout << "존재하지 않는 Index 입니다..." << endl;
			return;
		}

		if (index == 0) {
			Shape* tmp = pHead;
			pHead = pHead->getNext();
			delete tmp;
		}
		else {
			Shape* prevTarget = pHead, * nextTarget = pHead, * target = pHead;

			for (int i = 0; i < index - 1; i++)
				prevTarget = prevTarget->getNext();
			for (int i = 0; i < index + 1; i++) 
				nextTarget = nextTarget->getNext();
			for (int i = 0; i < index; i++)
				target = target->getNext();

			if (index == count) pTail = prevTarget;
			prevTarget->add(nextTarget);
			delete target;
		}
		count--;
	}
	void show() {
		Shape* p = pHead;
		int index = 0;
		if (!p) cout << "(비어있음)" << endl;
		while (p) {
			cout << index << " : "; p->paint(); index++;
			p = p->getNext();
		}
	}
	void system() {
		bool exit = false;
		UI::showTitle();
		while (!exit) {
			switch (UI::selectMenu())
			{
			case 1: insert(UI::selectFigure());
				break;
			case 2: remove(UI::selectIndex());
				break;
			case 3: show();
				break;
			case 4: exit = true;
				break;
			default: cout << "다시 입력하세요..." << endl;
				break;
			}
		}
		cout << "Graphic Editor 종료..." << endl;
	}
};

int main() {
	GraphicEditor obj;
	obj.system();
}