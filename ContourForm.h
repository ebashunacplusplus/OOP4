#pragma once
#include "Header.h"

class ContourForm : public Form {
protected:

public:

	void drawForm(HDC hdc);
	void loadFile(std::string namefile);
	void saveFile(std::string namefile);
};