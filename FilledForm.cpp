#include "FilledForm.h"
#include "Header.h"

void FilledForm::drawForm(HDC hdc) {

	HPEN hPen = CreatePen(contourStyle, contourSize, contourColor);
	HBRUSH hBrush = CreateSolidBrush(solidColor);
	SelectPen(hdc, hPen);
	SelectBrush(hdc, hBrush);
	Polygon(hdc, points, 4);
	DeletePen(hPen);
	DeleteBrush(hBrush);

}

void FilledForm::loadFile(std::string namefile, HWND hwnd) {

	int r, g, b;
	std::ifstream fin;
	fin.open(namefile);
	if (!fin)throw 1;

	for (int i = 0; i < 4; i++) {
		fin >> points[i].x >> points[i].y;
	}

	fin >> contourStyle >> contourSize >> r >> g >> b;
	contourColor = RGB(r, g, b);
	fin >> r >> g >> b;
	solidColor = RGB(r, g, b);
	fin.close();
	if (chek_figure() && chek_border(hwnd)) state = true;
	else {
		state = false; 
		throw 3;
	}
}

void FilledForm::saveFile(std::string namefile) {

	std::ofstream fout;
	fout.open(namefile, std::ofstream::ios_base::trunc);
	if (!fout)throw 1;

	for (int i = 0; i < 4; i++) {
		fout << points[i].x << std::endl << points[i].y << std::endl;
	}
	fout << contourStyle << " "
		 << contourSize  << " "
		 << static_cast<int>(GetRValue(contourColor))
		 << " " << static_cast<int>(GetGValue(contourColor))
		 << " " << static_cast<int>(GetBValue(contourColor)) << std::endl;
	fout << static_cast<int>(GetRValue(solidColor)) 
		 << " " << static_cast<int>(GetGValue(solidColor))
		 << " " << static_cast<int>(GetBValue(solidColor));
	fout.close();

}

void FilledForm::enterFilledForm(int c_style, int c_size, Color c_color, POINT *c_points, HWND hwnd, int r, int g, int b) {

	contourStyle = c_style;
	contourSize = c_size;
	contourColor = c_color;

	set_pointsForm(c_points);
	solidColor = RGB(r, g, b);

	if (chek_figure() && chek_border(hwnd)) state = true;
	else { 
		state = false; 
		throw 3; 
	}
}