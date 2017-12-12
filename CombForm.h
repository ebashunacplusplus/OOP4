#pragma once

#include "ContourForm.h"
#include "FilledForm.h"

class CombForm: public FilledForm {

private:

	ContourForm cTrapeze;
	void setUp();
	void setDown(HWND hwnd);
	void setLeft();
	void setRight(HWND hwnd);

public:

	void drawForm(HDC hdc);
	void loadFile(std::string namefile);
	void saveFile(std::string namefile);

};