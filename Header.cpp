#include "Header.h"

COLORREF BuildColor(Color color) {
	COLORREF temp = RGB(color.r, color.g, color.b);
	return temp;
}