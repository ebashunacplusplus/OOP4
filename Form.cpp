#include "Form.h"

void Form::set_pointsForm(POINT* point) {
	for (int i = 0; i < 4; i++) {
		points[i].x = point[i].x;
		points[i].y = point[i].y;
	}
}

void Form::get_pointsForm(POINT* ipoints) const {
	for (int i = 0; i < 4; i++) {
		ipoints[i].x = points[i].x;
		ipoints[i].y = points[i].y;
	}

}

void Form::setUp() {
	if (points[0].y != 0) {
		for (int i = 0; i < 4; i++)
			points[i].y--;
	}
}

void Form::setDown(HWND hwnd) {
	RECT brd;
	GetClientRect(hwnd, &brd);
	if (points[1].y != brd.bottom) {
		for (int i = 0; i < 4; i++)
			points[i].y++;
	}
}

void Form::setRight(HWND hwnd) {
	RECT brd;
	GetClientRect(hwnd, &brd);
	if (points[2].x != brd.right) {
		GetClientRect(hwnd, &brd);
		for (int i = 0; i < 4; i++)
			points[i].x++;
	}
}

void Form::setLeft() {
	if (points[1].x != 0) {
		for (int i = 0; i < 4; i++)
			points[i].x--;
	}
}

void Form::actionForm(HWND hwnd, HDC hdc) {

	drawForm(hdc);
	while (true) {
		switch (_getch())
		{
		case 72:
			setUp();
			drawForm(hdc);
			break;
		case 80:
			setDown(hwnd);
			drawForm(hdc);
			break;
		case 75:
			setLeft();
			drawForm(hdc);
			break;
		case 77:
			setRight(hwnd);
			drawForm(hdc);
			break;
		case 224:
			eraseDisplay(hdc, hwnd);
			break;
		case 27:
			return;
		default:
			std::cout << "Invalid button" << std::endl;
			break;
		}
	}
}

bool Form::chek_figure() const {
	int a, b;
	a = (points[2].x - points[1].x) * (points[3].y - points[0].y) -
		(points[2].y - points[1].y) * (points[3].x - points[0].x);
	b = (points[1].x - points[0].x) * (points[2].y - points[3].y) -
		(points[1].y - points[0].y) * (points[2].x - points[3].x);
	if (a == 0 && b != 0) return 1;
	return 0;
}

bool Form::chek_border(HWND hwnd) const {
	RECT border;
	GetClientRect(hwnd, &border);
	for (int i = 0; i < 4; i++) {
		if (points[i].x > border.right || points[i].x < 0 || points[i].y > border.bottom || points[i].y < 0)
			return 0;
	}
	return 1;
}