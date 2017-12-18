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
	bool chek_nest(POINT trap_p);

public:

	void drawForm(HDC hdc);
	void loadFile(std::string namefile, HWND hwnd);
	void saveFile(std::string namefile);
	bool chek_Nest();

};