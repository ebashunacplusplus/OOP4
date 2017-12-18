#include "ContourForm.h"

void ContourForm::drawForm(HDC hdc) {

	HPEN hPen = CreatePen(contourStyle, contourSize, contourColor);
	HBRUSH hBrush = CreateSolidBrush(RGB(255, 255, 255));
	SelectPen(hdc, hPen);
	SelectBrush(hdc, hBrush);
	Polygon(hdc, points, 4);
	DeletePen(hPen);
	DeleteBrush(hBrush);

}

void ContourForm::loadFile(std::string namefile, HWND hwnd) {

	int r, g, b;
	std::ifstream fin;
	fin.open(namefile);
	if (!fin)throw 1;

	while (!fin.eof()) {
		for (int i = 0; i < 4; i++) {
			fin >> points[i].x >> points[i].y;
		}
		fin >> contourStyle >> contourSize >> r >> g >> b;
	}
	contourColor = RGB(r, g, b);
	fin.close();
	if (chek_figure() && chek_border(hwnd)) state = true;
	else {
		state = false;
		throw 2;
	}
}

void ContourForm::saveFile(std::string namefile) {

	std::ofstream fout;
	fout.open(namefile, std::ofstream::ios_base::trunc);
	if (!fout)throw 1;
	for (int i = 0; i < 4; i++) {
		fout << points[i].x << std::endl << points[i].y << std::endl;
	}
	fout << contourStyle << " " 
		 << contourSize << " " 
		 << static_cast<int>(GetRValue(contourColor))
		 << " " << static_cast<int>(GetGValue(contourColor)) 
		 << " " << static_cast<int>(GetBValue(contourColor));
	fout.close();
}

void ContourForm::enterContourForm(int c_style, int c_size, Color c_color, POINT *c_points, HWND hwnd) {

	contourStyle = c_style;
	contourSize = c_size;
	contourColor = c_color;
	
	set_pointsForm(c_points);
	if (chek_figure() && chek_border(hwnd)) state = true;
	else {
		state = false;
		throw 2;
	}
}