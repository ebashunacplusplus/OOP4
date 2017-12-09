#pragma once

#include <string>
#include "Header.h"


// Abstract base class of a trapezoid
class Form {

protected:
	POINT points[4];
	COLORREF contourColor;


public:

	Form() {};
	~Form() {};

	virtual void drawForm(HDC hdc) = 0;
	virtual void loadFile(std::string namefile) = 0;
	virtual void saveFile(std::string namefile) = 0;

	void set_points(POINT* points);
	void set_ContourColor(Color color) { contourColor = BuildColor(color); }
	void get_points(POINT* points) const;
	void actionForm(HWND hwnd, HDC hdc);
	COLORREF get_BorderColorForm() { return contourColor; }

};

