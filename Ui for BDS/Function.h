#pragma once
#include "Win32.h"

int Err(HWND hwnd, LPCTSTR message);
int Err(ATOM atom, LPCTSTR message);
int Err(LPCTSTR message);
void ForceErrCheck(LPCTSTR title);

void StartBDS();
void StopBDS();
void ForceStopBDS();

bool SendCommand(LPCSTR command);

HWND CreateChildWindow(HWND hFather, LPCWCHAR childTitle, int x, int y, WNDPROC procFunc, LPCWCHAR className, HINSTANCE hInstance);
