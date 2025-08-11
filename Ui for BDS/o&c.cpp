#include "Win32.h"
#include "ID.h"
#include "Function.h"


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
PROCESS_INFORMATION pi;
HWND hBDS;

static void CloseHandle()
{
    CloseHandle(BDSr_key);
    CloseHandle(UIw_key);
    CloseHandle(UIr_log);
    CloseHandle(BDSw_log);
}
InitH(BDSr_key); InitH(UIw_key); InitH(BDSw_log); InitH(UIr_log);
void StartBDS()
{
    SECURITY_ATTRIBUTES sa = { sizeof(sa), NULL, TRUE };
    if(!CreatePipe(&BDSr_key, &UIw_key, &sa, 0))
        Err(TITLE, _T("Failed to create pipe_key"));
    if (!CreatePipe(&UIr_log, &BDSw_log, &sa, 0))
        Err(TITLE, _T("Failed to create pipe_log"));
    STARTUPINFO si = { sizeof(si) };
    si.dwFlags = STARTF_USESTDHANDLES;
    si.hStdInput = UIw_key;
    si.wShowWindow = SW_SHOWMINIMIZED;

    if (CreateProcess(
        L"bedrock_server.exe",
        NULL, NULL, NULL, TRUE, NULL, NULL, NULL, &si, &pi))
    {
        hBDS = GetConsoleWindow();
        Err(hBDS, TITLE,
            _T("Failed to find BDS window"));
        /*
        HMENU hmenu = GetSystemMenu(hBDS, false);
        RemoveMenu(hmenu, SC_CLOSE, MF_BYCOMMAND);
        LONG style = GetWindowLong(hBDS, GWL_STYLE);
        style &= ~(WS_MINIMIZEBOX);
        SetWindowLong(hBDS, GWL_STYLE, style);
        SetWindowPos(hBDS, HWND_TOP, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
        ShowWindow(hBDS, SW_SHOWNORMAL);
        DestroyMenu(hmenu);
        */
        while (bool condition=0)
        {

        }
    }
    else {
        Err(TITLE, _T("Failed to send command to BDS!"));
        CloseHandle();
    }
}

void StopBDS()
{
    SendCommand((WCHAR)"stop\n");
    CloseHandle();
}

void ForceStopBDS()
{
    TerminateProcess(pi.hProcess,0);
    CloseHandle();
    MessageBox(hWnd,
        L"已尝试强行停止服务器", TITLE,
        MB_OK);
}
