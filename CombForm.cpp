#include "CombForm.h"

void CombForm::drawForm(HDC hdc) {

	HPEN out_hPen = CreatePen(contourStyle, contourSize, contourColor);
	HPEN in_hPen = CreatePen(cTrapeze.get_styleForm(), cTrapeze.get_sizeForm(), cTrapeze.get_ContourColor());
	HBRUSH out_hBrush = CreateSolidBrush(solidColor);
	HBRUSH in_hBrush = CreateSolidBrush(RGB(255, 255, 255));
	SelectPen(hdc, out_hPen);
	SelectBrush(hdc, out_hBrush);
	Polygon(hdc, points, 4);
	SelectPen(hdc, in_hPen);
	SelectBrush(hdc, in_hBrush);
	DeletePen(out_hPen);
	DeleteBrush(out_hBrush);
	POINT P[4]; 
	cTrapeze.get_pointsForm(P);
	Polygon(hdc, P, 4);
	DeletePen(in_hPen);
	DeleteBrush(in_hBrush);

}

void CombForm::loadFile(std::string namefile) {

	POINT cmb_P[4];
	int cmb_style, cmb_size,r,g,b;

	std::ifstream fin;
	fin.open(namefile);
	if (!fin)throw 1;

	for (int i = 0; i < 4; i++) {
		fin >> points[i].x >> cmb_P[i].x >> points[i].y >> cmb_P[i].y;
	}
	cTrapeze.set_pointsForm(cmb_P);
	fin >> contourStyle >> contourSize >> r >> g >> b;
	contourColor = RGB(r, g, b);
	fin >> cmb_style >> cmb_size >> r >> g >> b;
	cTrapeze.set_sizeForm(cmb_size);
	cTrapeze.set_styleForm(cmb_style);
	cTrapeze.set_ContourColor(RGB(r, g, b));
	fin >> r >> g >> b;
	solidColor = RGB(r, g, b);
	fin.close();

}

void CombForm::saveFile(std::string namefile) {

	std::ofstream fout;
	fout.open(namefile);
	if (!fout)throw 1;
	POINT P[4];
	cTrapeze.get_pointsForm(P);

	for (int i = 0; i < 4; i++) {
		fout << points[i].x << " " << P[i].x << std::endl;
		fout << points[i].y << " " << P[i].y << std::endl;
	}
	fout << contourStyle
		 << " " << contourSize
		 << " " << static_cast<int>(GetRValue(contourColor))
		 << " " << static_cast<int>(GetGValue(contourColor))
		 << " " << static_cast<int>(GetBValue(contourColor)) << std::endl;
	fout << cTrapeze.get_styleForm() 
		 << " " << cTrapeze.get_sizeForm() 
		 << " " << static_cast<int>(GetRValue(cTrapeze.get_ContourColor()))
		 << " " << static_cast<int>(GetGValue(cTrapeze.get_ContourColor()))
		 << " " << static_cast<int>(GetBValue(cTrapeze.get_ContourColor())) << std::endl;
	fout << static_cast<int>(GetRValue(solidColor))
		 << " " << static_cast<int>(GetGValue(solidColor))
		 << " " << static_cast<int>(GetBValue(solidColor));
	fout.close();

}

void CombForm::setUp() {
	if (points[0].y != 0) {
		for (int i = 0; i < 4; i++) {
			points[i].y--;
			cTrapeze.correctPointY(i, -1);
		}
	}
}

void CombForm::setDown(HWND hwnd) {
	RECT brd;
	GetClientRect(hwnd, &brd);
	if (points[1].y != brd.bottom) {
		for (int i = 0; i < 4; i++) {
			points[i].y++;
			cTrapeze.correctPointY(i, 1);
		}
	}
}

void CombForm::setRight(HWND hwnd) {
	RECT brd;
	GetClientRect(hwnd, &brd);
	if (points[2].x != brd.right) {
		GetClientRect(hwnd, &brd);
		for (int i = 0; i < 4; i++) {
			points[i].x++;
			cTrapeze.correctPointX(i, 1);
		}
	}
}

void CombForm::setLeft() {
	if (points[1].x != 0) {
		for (int i = 0; i < 4; i++) {
			points[i].x--;
			cTrapeze.correctPointX(i, -1);
		}
	}
}