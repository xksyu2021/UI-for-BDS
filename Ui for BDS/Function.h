#pragma once

int Err(HWND hwnd, LPCTSTR message);
int Err(ATOM atom, LPCTSTR message);
int Err(LPCTSTR message);
void ForceErrCheck(LPCTSTR title);
int Err(std::ifstream* file, LPCTSTR message);
int Err(std::ofstream* file, LPCTSTR message);

void StartBDS();
void StopBDS();
void ForceStopBDS();

bool SendCommand(LPCSTR command);
bool SendCommand_NoErr(LPCSTR command);
bool SendCommand_WithID(const std::string& front, const std::string& id, const std::string& behind);


void ClearLog();
void Log(HWND hwnd);

HWND CreateChildWindow(HWND hFather, LPCWCHAR childTitle, int x, int y, WNDPROC procFunc, LPCWCHAR className, HINSTANCE hInstance);
HWND CreateLogWindow(LPCWCHAR childTitle, int x, int y, WNDPROC procFunc, LPCWCHAR className, HINSTANCE hInstanceF);
HWND CreateStartWindow(int x, int y, WNDPROC procFunc, LPCWCHAR className, HINSTANCE hInstanceF);