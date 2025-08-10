#include "Win32.h"
#include "ID.h"

//Error check&output
int Err(HWND hwnd, LPCTSTR title, LPCTSTR message)
{
    if (!hwnd)
    {
        MessageBox(NULL,message,title, MB_ICONERROR);
        return 1;
    }
    return 0;
}
int Err(ATOM atom, LPCTSTR message, LPCTSTR title)
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

//
static void AutoClose(DWORD time, LPCWSTR title)
{
    Sleep(time*1000); 
    HWND box = FindWindow(NULL, title);
    if (box) 
    {
        SendMessage(box, WM_CLOSE, 0, 0); 
    }
}

//Open&Stop
HANDLE BDSr_key = NULL;
HANDLE UIw_key = NULL;
void StartBDS()
{
    SECURITY_ATTRIBUTES sa = { sizeof(sa), NULL, TRUE };
    if(!CreatePipe(&BDSr_key, &UIw_key, &sa, 0))
        Err(TITLE, _T("Failed to create pipe"));
    STARTUPINFO si = { sizeof(si) };
    si.dwFlags = STARTF_USESTDHANDLES;
    si.hStdInput = UIw_key;
    si.wShowWindow = SW_SHOWMINIMIZED;
    PROCESS_INFORMATION pi;

    if (CreateProcess(
        L"bedrock_server.exe",
        NULL, NULL, NULL, TRUE, NULL, NULL, NULL, &si, &pi))
    {
        HWND hBox = NULL;
        MessageBoxW(hWnd,
            _T("开始启动服务器\n5s后弹窗自动关闭"), L"Info",
            MB_OK);
        AutoClose(5, L"Info");
    }
    else {
        Err(TITLE, _T("Failed to send command to BDS!"));
        CloseHandle(BDSr_key);
        CloseHandle(UIw_key);
    }
}
