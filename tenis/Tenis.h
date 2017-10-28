#pragma once

#include <iostream>
#include "conslib.h"

using namespace std;


class Figure {
public:
	void virtual paint() = 0;
};

class Figure1 : public Figure {
public:
	void paint();
};

class Figure2 : public Figure {
public:
	void paint();
};

class Ball : public Figure {
private:
	const int height = 30;
	const int width = 30;
public:
	void tenis(int start_x, int start_y);
	void paint();
};