#pragma once
#include "Win32.h"

int Err(HWND hwnd, LPCTSTR message, LPCTSTR title);
int Err(ATOM atom, LPCTSTR message, LPCTSTR title);
int Err(LPCTSTR title, LPCTSTR message);

void StartBDS();