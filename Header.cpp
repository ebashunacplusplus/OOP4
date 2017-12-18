#include "Header.h"

void eraseDisplay(HDC hdc, HWND hwnd) {
	RECT brd;
	HBRUSH hBrushS = CreateSolidBrush(RGB(255, 255, 255));
	HPEN hPen = CreatePen(0, 1, RGB(255, 255, 255));
	SelectPen(hdc, hPen);
	SelectBrush(hdc, hBrushS);
	GetClientRect(hwnd, &brd);
	Rectangle(hdc, 0, 0, brd.right, brd.bottom);
	DeletePen(hPen);
	DeleteBrush(hBrushS);
}

int area_tr(POINT p_one, POINT p_two, POINT p_three) {
	int area;
	area = 0.5*((p_one.x - p_three.x)*(p_two.y - p_three.y) - (p_two.x - p_three.x)*(p_one.y - p_three.y));
	return abs(area);
}