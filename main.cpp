#include "Form.h"
#include "ContourForm.h"
#include "FilledForm.h"

using namespace std;


int main() {
	HWND hwnd = FindWindowA("notepad", nullptr);
	HDC hdc = GetDC(hwnd);
	
	FilledForm form;
	form.loadFile("filled.txt");
	form.actionForm(hwnd,hdc);
	form.saveFile("filledsave.txt");
	system("pause");
	return 0;
}