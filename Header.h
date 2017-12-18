#pragma once

#include <iostream>
#include <Windows.h>
#include <windowsx.h>
#include <fstream>
#include <conio.h>

typedef COLORREF Color;

void eraseDisplay(HDC hdc, HWND hwnd);

int area_tr(POINT p_one, POINT p_two, POINT p_three);