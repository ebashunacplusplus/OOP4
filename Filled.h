#pragma once
#include <Windows.h>

class Filled {

protected:

	Color solidColor;

public:

	Filled() {}
	Filled(int r, int g, int b) { solidColor = RGB(r, g, b); }
	~Filled() {}

	void setColorForm(Color color) { solidColor = color; };
	Color getColorForm() { return solidColor; };

};