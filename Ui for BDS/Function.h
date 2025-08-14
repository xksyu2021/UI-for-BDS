#pragma once
#include "Win32.h"

int Err(HWND hwnd, LPCTSTR message);
int Err(ATOM atom, LPCTSTR message);
int Err(LPCTSTR message);
void ForceErrCheck(LPCTSTR title);
int Err(std::ifstream* file, LPCTSTR message);
int Err(std::fstream* file, LPCTSTR message);

void StartBDS();
void StopBDS();
void ForceStopBDS();

bool SendCommand(LPCSTR command);

void ClearLog();
void Log(HWND hwnd);

HWND CreateChildWindow(HWND hFather, LPCWCHAR childTitle, int x, int y, WNDPROC procFunc, LPCWCHAR className, HINSTANCE hInstance);
HWND CreateNewWindow(LPCWCHAR childTitle, int x, int y, WNDPROC procFunc, LPCWCHAR className, HINSTANCE hInstanceF);
