#pragma once

#include <iostream>
#include "conslib.h"

using namespace std;


class Figure {
protected:
	const int height = 30;
	const int width = 30;
	int up;
	int down;
	int left;
	int right;
public:
	Figure(int up, int down, int right, int left);
	void virtual paint(int x, int y) = 0;
	void tenis(int start_x, int start_y);

};

class Figure1 : public Figure {
public:
	Figure1();
	void paint(int x, int y);
};

class Figure2 : public Figure {
public:
	Figure2();
	void paint(int x, int y);

};

