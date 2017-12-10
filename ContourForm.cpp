#include "ContourForm.h"

void ContourForm::drawForm(HWND hwnd) {

	HDC hdc = GetDC(hwnd);
	POINT p[4];
	HPEN hPen = CreatePen(contourStyle, contourSize, contourColor);
	HBRUSH hBrush = CreateSolidBrush(RGB(255, 255, 255));
	SelectPen(hdc, hPen);
	SelectBrush(hdc, hBrush);
	Polygon(hdc, points, 4);
	DeletePen(hPen);
	DeleteBrush(hBrush);

}

void ContourForm::loadFile(std::string namefile) {


}

void ContourForm::saveFile(std::string namefile) {


}