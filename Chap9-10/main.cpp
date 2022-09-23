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
		cout << endl << "����(1), ����(2), ����(3), ����(4) >> ";
		cin >> cmd; return cmd;
	}
	static int selectFigure() {
		int cmd;
		cout << "Line(1), Circle(2), Rect(3) >> ";
		cin >> cmd; return cmd;
	}
	static int selectIndex() {
		int cmd;
		cout << "�����ϰ��� �ϴ� ������ �ε��� >> ";
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
			cout << "Line �߰���..." << endl; count++;
			break;
		case 2:
			if (!pHead) { pHead = new Circle(); pTail = pHead; }
			else { pTail = pTail->add(new Circle()); }
			cout << "Circle �߰���..." << endl; count++;
			break;
		case 3:
			if (!pHead) { pHead = new Rect(); pTail = pHead; }
			else { pTail = pTail->add(new Rect()); }
			cout << "Rect �߰���..." << endl; count++;
			break;
		default: cout << "�ٽ� �Է��ϼ���..." << endl;
			break;
		}
	}
	void remove(int index) {
		if (index > count) {
			cout << "�������� �ʴ� Index �Դϴ�..." << endl;
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
		if (!p) cout << "(�������)" << endl;
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
			default: cout << "�ٽ� �Է��ϼ���..." << endl;
				break;
			}
		}
		cout << "Graphic Editor ����..." << endl;
	}
};

int main() {
	GraphicEditor obj;
	obj.system();
}