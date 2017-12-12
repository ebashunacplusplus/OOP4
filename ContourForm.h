#pragma once

#include "Form.h"

class ContourForm : public Form {

protected:

	

public:

	ContourForm() {}
	ContourForm(int c_style, int c_size, Color c_color, POINT *p_Form) : Form(c_style, c_size, c_color, p_Form) {};

	void drawForm(HDC hdc);
	void loadFile(std::string namefile);
	void saveFile(std::string namefile);

};