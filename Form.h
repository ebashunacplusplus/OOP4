#pragma once

#include <string>
#include "Header.h"


// Abstract base class of a trapezoid
class Form {

protected:

	POINT points[4];
	Color contourColor;
	int contourStyle;
	int contourSize;

	virtual void setUp();
	virtual void setDown(HWND hwnd);
	virtual void setLeft();
	virtual void setRight(HWND hwnd);

	
public:

	Form() {}
	Form(int c_style, int c_size, Color c_color, POINT *p_Form) : contourColor(c_color), contourSize(c_size), contourStyle(c_style){
		set_pointsForm(p_Form);
	}

	virtual void drawForm(HDC hdc) = 0;
	virtual void loadFile(std::string namefile) = 0;
	virtual void saveFile(std::string namefile) = 0;
	

	void set_pointsForm(POINT* points);
	void set_styleForm(int stl) { contourStyle = stl; }
	void set_sizeForm(int sz) { contourSize = sz; }
	void set_ContourColor(Color color) { contourColor = color; }

	void get_pointsForm(POINT* ipoint) const;
	int get_styleForm() const { return contourStyle; }
	int get_sizeForm() const { return contourSize; }

	void correctPointX(int i, int x) { points[i].x += x; }
	void correctPointY(int i, int x) { points[i].y += x; }
	void actionForm(HWND hwnd, HDC hdc);

	COLORREF get_ContourColor() { return contourColor; }

};

