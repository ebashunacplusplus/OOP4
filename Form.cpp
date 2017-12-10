#include "Form.h"

void Form::set_pointsForm(POINT* point) {
	for (int i = 0; i < 4; i++) {
		points[i].x = point[i].x;
		points[i].y = point[i].y;
	}
}

void Form::get_pointsForm(POINT* points) const {
	

}

void Form::actionForm(HWND hwnd, HDC hdc) {


}