#include "Form.h"
#include "ContourForm.h"
#include "FilledForm.h"
#include "CombForm.h"

using namespace std;


int main() {
	HWND hwnd = FindWindowA("notepad", nullptr);
	HDC hdc = GetDC(hwnd);
	
	CombForm comb;
	comb.loadFile("comb.txt");
	comb.saveFile("combsave.txt");
	system("pause");
	return 0;
}