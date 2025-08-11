#include "Win32.h"
#include "ID.h"


int Err(HWND hwnd, LPCTSTR title, LPCTSTR message)
{
    if (!hwnd)
    {
        MessageBox(NULL, message, title, MB_ICONERROR);
        return 1;
    }
    return 0;
}
int Err(ATOM atom, LPCTSTR title, LPCTSTR message)
{
    if (!atom)
    {
        MessageBox(NULL, message, title, MB_ICONERROR);
        return 1;
    }
    return 0;
}
int Err(LPCTSTR title, LPCTSTR message)
{
    if (GetLastError() != 0)
    {
        MessageBox(NULL, message, title, MB_ICONERROR);
        return 1;
    }
    return 0;
}