#pragma once
#include <Windows.h>
#include <string>

#include "Form.h"

struct  Color
{
	int r, g, b;

	Color(int r, int g, int b) :r(r), g(g), b(b) {};
};

COLORREF get_color(Color col);