#pragma once

#include "ContourForm.h"
#include "Filled.h"

class FilledForm : public ContourForm, public Filled {

private:

public:

	FilledForm() {}
	FilledForm(int f_style, int f_size, Color f_color, POINT* f_P, int fr, int fg, int fb) : ContourForm(f_style, f_size, f_color, f_P), Filled(fr, fg, fb) {}
	~FilledForm() {}

	void drawForm(HDC hdc);
	void loadFile(std::string namefile, HWND hwnd);
	void saveFile(std::string namefile);
	void FilledForm::enterFilledForm(int c_style, int c_size, Color c_color, POINT *c_points, HWND hwnd, int r ,int g, int b);
};