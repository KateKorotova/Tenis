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


void Ball::tenis(int start_x, int start_y) {
	int swt1 = rand_();
	int swt2 = rand_();

	for (int i = 0; i < 100; i++) {

		start_x = start_x + swt1;
		start_y = start_y + swt2;

		if (start_x > width) {
			swt1 = (-1)*abs(rand_());
			swt2 = rand_();
			start_x -= (start_x%width);
		}
		if (start_x < 0) {
			swt1 = abs(rand_());
			swt2 = rand_();
			start_x = 0;
		}

		if (start_y > height) {
			swt2 = (-1)*abs(rand_());
			swt1 = rand_();
			start_y -= (start_y%height);
		}

		if (start_y < 0) {
			swt2 = abs(rand_());
			swt1 = rand_();
			start_y = 0;
		}

		printat(start_x, start_y, "O");
		pause(400);
		system("cls");

	}
}

void Figure1::paint() {
	cout << "  " << "*" << endl;
	cout << "*" << "   " << "*" << endl;
	cout << " " << "*" << " " << "*" << endl;
}

void Figure2::paint() {
	cout << "***" << endl;
	cout << "*" << " " << "*" << endl;
	cout << "***" << endl;
}

void Ball::paint() {
	cout << "  " << "***" << "  " << endl;
	cout << " " << "*" << "   " << "*" << endl;
	cout << "*" << "     " << "*" << endl;
	cout << "*" << "     " << "*" << endl;
	cout << " " << "*" << "   " << "*" << endl;
	cout << "  " << "***" << "  " << endl;

}


int main() {
	Figure* figure = nullptr;
	cout << "Choice:" << endl;
	cout << "1. Paint figure 1" << endl;
	cout << "2. Paint figure 2" << endl;
	cout << "3. Paint ball" << endl;
	cout << "4. Turn on tennis" << endl; 
	int ch;
	cin >> ch;
	if (!cin.fail()) {
		switch (ch) {
		case 1:
			figure = new Figure1();
			figure->paint();
			system("pause");
			break;
		case 2:
			figure = new Figure2();
			figure->paint();
			system("pause");
			break;
		case 3:
			figure = new Ball();
			figure->paint();
			system("pause");
			break;
		case 4:
			Ball a;
			a.tenis(17, 21);
			system("cls");
			waitAnyKey();
			break;
		}
	}

}