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
        DWORD error = GetLastError();
        LPWSTR errorMsg = (LPWSTR)"unknown";
        FormatMessage(
            FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM, 
            NULL, error, 0, errorMsg, 256, NULL);
        MessageBox(NULL, message, errorMsg, MB_ICONERROR);
        return 1;
    }
    return 0;
}