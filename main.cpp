#include "Form.h"
#include "ContourForm.h"

using namespace std;


int main() {
	HWND hwnd = FindWindowA("notepad", nullptr);
	HDC hdc = GetDC(hwnd);

	ContourForm form;

	
	system("pause");
	return 0;
}