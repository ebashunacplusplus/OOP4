#include <iostream>

#include "Form.h"
#include "ContourForm.h"

using namespace std;

Color gold(252, 215, 30);
Color red(255, 0, 0);

int main() {
	HWND hwnd = FindWindowA("notepad", nullptr);
	HDC hdc = GetDC(hwnd);

	POINT myP[4];

	for (int i = 0; i < 4; i++) {
		cin >> myP[i].x;
		cin >> myP[i].y;
	}

	ContourForm cForm(0,2,red,myP);

	cForm.drawForm(hwnd);

	system("pause");
	return 0;
}