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
	string namefile;

	while (menu != 0) {

		system("cls");
		cout << "0 - Exit" << endl;
		cout << "1 - ContourForm" << endl;
		cout << "2 - FilledForm" << endl;
		cout << "3 - CombForm" << endl;
		cout << "-------------------------" << endl;
		cin >> menu;

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
					cForm.drawForm(hdc);
					break;
				case 2: 
					cForm.actionForm(hwnd, hdc);
					break;
				case 3:
					cout << "Enter namefile: ";
					cin >> namefile;
					cForm.loadFile(namefile);
					break;
				case 4:
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
					fForm.drawForm(hdc);
					break;
				case 2:
					fForm.actionForm(hwnd, hdc);
					break;
				case 3:
					cout << "Enter namefile: ";
					cin >> namefile;
					fForm.loadFile(namefile);
					break;
				case 4:
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

			while (comMenu != 6) {

				system("cls");
				cout << "1 - Draw form" << endl;
				cout << "2 - Action form" << endl;
				cout << "3 - Load file" << endl;
				cout << "4 - Enter trapeze" << endl;
				cout << "5 - Save trapeze" << endl;
				cout << "6 - Back to menu" << endl;
				cout << "-------------------------" << endl;
				cin >> comMenu;

				switch (comMenu)
				{
				case 1:
					cmbForm.drawForm(hdc);
					break;
				case 2:
					cmbForm.actionForm(hwnd, hdc);
					break;
				case 3:
					cout << "Enter namefile: ";
					cin >> namefile;
					cmbForm.loadFile(namefile);
					break;
				case 4:
					break;
				case 5:
					cout << "Enter namefile: ";
					cin >> namefile;
					cmbForm.saveFile(namefile);
					break;
				case 6:
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
	
	return 0;
}