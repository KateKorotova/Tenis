#include "Tenis.h"
#include <Windows.h>
#include <math.h>

using namespace std;

int rand_() {
	int k = 0; 
	while (k == 0)
	k = rand() % 4 - 3;

	return k; 
}

Figure::Figure(int up, int down, int right, int left) {
	this->up = up;
	this->down = down;
	this->right = right;
	this->left = left; 
}

void Figure::tenis(int start_x, int start_y) {
	int swt1 = rand_();
	int swt2 = rand_();

	for (int i = 0; i < 100; i++) {

		start_x = start_x + swt1;
		start_y = start_y + swt2;

		if (start_x + right > width) {
			swt1 = (-1)*swt1;
			start_x = width - right;
		}
		if (start_x - left < 0) {
			swt1 = (-1)*swt1;
			start_x = left;
		}

		if (start_y+ down> height) {
			swt2 = (-1)*swt2;
			start_y = height -down;
		}

		if (start_y - up< 0) {
			swt2 = (-1)*swt2;
			start_y = up;
		}

		paint(start_x, start_y);
		pause(400);
		system("cls");

	}
}
 

Figure1::Figure1():Figure(1, 1, 2, 2) {};

Figure2::Figure2() :Figure(2, 1, 1, 1) {};


void Figure1::paint(int x, int y) {
	printat(x, y-1, "*");
	printat(x - 2, y, "*");
	printat(x + 2, y, "*");
	printat(x - 1, y + 1, "*");
	printat(x + 1, y + 1, "*");
}

void Figure2::paint(int x, int y) {
	printat(x-1, y - 2, "*");
	printat(x, y - 2, "*"); 
	printat(x + 1, y - 2, "*");
	printat(x-1, y-1, "*");
	printat(x + 1, y-1, "*");
	printat(x - 1, y, "*");
	printat(x + 1, y, "*");
	printat(x - 1, y + 1, "*");
	printat(x, y + 1, "*");
	printat(x + 1, y + 1, "*");
}




int main() {
	Figure* figure = nullptr;
	cout << "Choice:" << endl;
	cout << "1. Paint figure 1" << endl;
	cout << "2. Paint figure 2" << endl;
	cout << "3. Tennis 1" << endl;
	cout << "4. Tennis 2" << endl;
	int ch;
	cin >> ch;
	if (!cin.fail()) {
		switch (ch) {
		case 1:
			figure = new Figure1();
			figure->paint(8, 10);
			system("pause");
			break;
		case 2:
			figure = new Figure2();
			figure->paint(8, 10);
			system("pause");
			break;
		case 3:
			figure = new Figure1();
			figure->tenis(6, 9);
			break;
		case 4:
			figure = new Figure2();
			figure->tenis(6, 9);
			break;
		}
	}
}