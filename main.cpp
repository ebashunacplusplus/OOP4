#include "Form.h"
#include "ContourForm.h"
#include "FilledForm.h"
#include "CombForm.h"

using namespace std;


int main() {
	HWND hwnd = FindWindowA("notepad", nullptr);
	HDC hdc = GetDC(hwnd);

	ContourForm cForm;
	FilledForm fForm;
	CombForm cmbForm;

	int conMenu = -1, filMenu = -1, comMenu = -1, menu = -1;
	int istyle, isize, r, g, b, sr, sg, sb;
	POINT enteringP[4];
	string namefile;

	while (menu != 0) {

		system("cls");
		cout << "0 - Exit" << endl;
		cout << "1 - ContourForm" << endl;
		cout << "2 - FilledForm" << endl;
		cout << "3 - CombForm" << endl;
		cout << "-------------------------" << endl;
		cin >> menu;
		try {
			switch (menu)
			{

			case 0:

				system("cls");
				system("pause");
				break;

			case 1:          // ContourForm

				while (conMenu != 6) {

					system("cls");
					cout << "1 - Draw form" << endl;
					cout << "2 - Action form" << endl;
					cout << "3 - Load file" << endl;
					cout << "4 - Enter trapeze" << endl;
					cout << "5 - Save trapeze" << endl;
					cout << "6 - Back to menu" << endl;
					cout << "-------------------------" << endl;
					cin >> conMenu;

					switch (conMenu)
					{
					case 1:
						if (!cForm.get_stateForm()) {
							cout << "First enter the parameters of the trapezoid" << endl;
							system("pause");
							break;
						}
						cForm.drawForm(hdc);
						break;
					case 2:
						if (!cForm.get_stateForm()) {
							cout << "First enter the parameters of the trapezoid" << endl;
							system("pause");
							break;
						}
						cout << endl << "---To exit the mode, press Esc---" << endl;
						cForm.actionForm(hwnd, hdc);
						break;
					case 3:
						cout << "Enter namefile: ";
						cin >> namefile;
						cForm.loadFile(namefile, hwnd);
						break;
					case 4:
						for (int i = 0; i < 4; i++) {
							cout << "Press x" << i + 1 << ": ";
							cin >> enteringP[i].x;
							cout << "Press y" << i + 1 << ": ";
							cin >> enteringP[i].y;
						}
						cout << "Press style border: ";
						cin >> istyle;
						cout << "Press size border: ";
						cin >> isize;
						cout << "Color border r = ";
						cin >> r;
						cout << "Color border g = ";
						cin >> g;
						cout << "Color border b = ";
						cin >> b;
						cForm.enterContourForm(istyle, isize, RGB(r, g, b), enteringP, hwnd);
						break;
					case 5:
						cout << "Enter namefile: ";
						cin >> namefile;
						cForm.saveFile(namefile);
						break;
					case 6:
						break;
					default:
						cout << "Invalid menu item ..." << endl;
						system("pause");
						break;
					}
				}

				conMenu = -1;
				break;
			case 2:               // FilledForm

				while (filMenu != 6) {

					system("cls");
					cout << "1 - Draw form" << endl;
					cout << "2 - Action form" << endl;
					cout << "3 - Load file" << endl;
					cout << "4 - Enter trapeze" << endl;
					cout << "5 - Save trapeze" << endl;
					cout << "6 - Back to menu" << endl;
					cout << "-------------------------" << endl;
					cin >> filMenu;

					switch (filMenu)
					{
					case 1:
						if (!fForm.get_stateForm()) {
							cout << "First enter the parameters of the trapezoid" << endl;
							system("pause");
							break;
						}
						fForm.drawForm(hdc);
						break;
					case 2:
						if (!fForm.get_stateForm()) {
							cout << "First enter the parameters of the trapezoid" << endl;
							system("pause");
							break;
						}
						cout << endl << "---To exit the mode, press Esc---" << endl;
						fForm.actionForm(hwnd, hdc);
						break;
					case 3:
						cout << "Enter namefile: ";
						cin >> namefile;
						fForm.loadFile(namefile, hwnd);
						break;
					case 4:
						for (int i = 0; i < 4; i++) {
							cout << "Press x" << i + 1 << ": ";
							cin >> enteringP[i].x;
							cout << "Press y" << i + 1 << ": ";
							cin >> enteringP[i].y;
						}
						cout << "Press style border: ";
						cin >> istyle;
						cout << "Press size border: ";
						cin >> isize;
						cout << "Color border r = ";
						cin >> r;
						cout << "Color border g = ";
						cin >> g;
						cout << "Color border b = ";
						cin >> b;
						cout << "Color solid r = ";
						cin >> sr;
						cout << "Color solid g = ";
						cin >> sg;
						cout << "Color solid b = ";
						cin >> sb;

						fForm.enterFilledForm(istyle, isize, RGB(r, g, b), enteringP, hwnd, sr, sg, sb);
						break;
					case 5:
						cout << "Enter namefile: ";
						cin >> namefile;
						fForm.saveFile(namefile);
						break;
					case 6:
						break;
					default:
						cout << "Invalid menu item ..." << endl;
						system("pause");
						break;
					}
				}

				filMenu = -1;
				break;

			case 3:               // CombForm

				while (comMenu != 5) {

					system("cls");
					cout << "1 - Draw form" << endl;
					cout << "2 - Action form" << endl;
					cout << "3 - Load file" << endl;
					cout << "4 - Save trapeze" << endl;
					cout << "5 - Back to menu" << endl;
					cout << "-------------------------" << endl;
					cin >> comMenu;

					switch (comMenu)
					{
					case 1:
						if (!cmbForm.get_stateForm()) {
							cout << "First enter the parameters of the trapezoid" << endl;
							system("pause");
							break;
						}
						cmbForm.drawForm(hdc);
						break;
					case 2:
						if (!cmbForm.get_stateForm()) {
							cout << "First enter the parameters of the trapezoid" << endl;
							system("pause");
							break;
						}
						cout << endl << "---To exit the mode, press Esc---" << endl;
						cmbForm.actionForm(hwnd, hdc);
						break;
					case 3:
						cout << "Enter namefile: ";
						cin >> namefile;
						cmbForm.loadFile(namefile, hwnd);
						break;
					case 4:
						cout << "Enter namefile: ";
						cin >> namefile;
						cmbForm.saveFile(namefile);
						break;
					case 5:
						break;
					default:
						cout << "Invalid menu item ..." << endl;
						system("pause");
						break;
					}
				}

				comMenu = -1;
				break;

			default:
				cout << "Invalid menu item ..." << endl;
				system("pause");
				break;
			}
		}
		catch (int a) {
			if (a == 1) {
				cout << "Files not founded..." << endl;
				system("pause");
			}
			if (a == 2) {
				cout << "The ContourForm is not a trapezoid or is outside the screen" << endl;
				system("pause");
			}
			if (a == 3) {
				cout << "The FilledForm is not a trapezoid or is outside the screen" << endl;
				system("pause");
			}
			if (a == 4) {
				cout << "The CombForm contains incorrect data" << endl;
				system("pause");
			}
		}
	}
	
	return 0;
}