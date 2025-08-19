#include "Win32.h"

static bool errShow = FALSE;

static LPWSTR GetError()
{
    DWORD error = GetLastError();
    LPWSTR errorMsg = NULL;
    FormatMessage(
        FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
        NULL, error, 0, (LPWSTR)&errorMsg, 256, NULL);
    return errorMsg;
}

int Err(HWND hwnd, LPCTSTR message)
{
    if ((!hwnd) && !errShow)
    {
        errShow = TRUE;
        MessageBox(NULL, message, GetError(), MB_ICONERROR);
        errShow = FALSE;
        return 1;
    }
    return 0;
}
int Err(ATOM atom, LPCTSTR message)
{
    if ((!atom) && !errShow)
    {
        errShow = TRUE;
        MessageBox(NULL, message, GetError(), MB_ICONERROR);
        errShow = FALSE;
        return 1;
    }
    return 0;
}
int Err(LPCTSTR message)
{
    if ((GetLastError() != 0) && !errShow)
    {
        errShow = TRUE;
        MessageBox(NULL, message, GetError(), MB_ICONERROR);
        errShow = FALSE;
        return 1;
    }
    return 0;
}
void ForceErrCheck(LPCTSTR title)
{
       MessageBox(NULL, GetError(), title, MB_ICONWARNING);
}

int Err(std::ifstream* file, LPCTSTR message)
{
    if ((!file) && !errShow)
    {
        errShow = TRUE;
        MessageBox(NULL, message, GetError(), MB_ICONERROR);
        errShow = FALSE;
        return 1;
    }
    return 0;
}
int Err(std::ofstream* file, LPCTSTR message)
{
    if ((!file) && !errShow)
    {
        errShow = TRUE;
        MessageBox(NULL, message, GetError(), MB_ICONERROR);
        errShow = FALSE;
        return 1;
    }
    return 0;
}