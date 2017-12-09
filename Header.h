#pragma once
#include <Windows.h>

struct Color {
	int r, g, b;
	Color(int r, int g, int b) :r(r), g(g), b(b) {};
};

COLORREF BuildColor(Color color);
