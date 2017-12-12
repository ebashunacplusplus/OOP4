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