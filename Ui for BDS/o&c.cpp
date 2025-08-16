#include "Win32.h"
#include "ID.h"
#include "Function.h"
#include "SharedValue.h"


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

static void CloseHandleA()
{
    CloseHandle(BDSr_key);
    CloseHandle(UIw_key);
    CloseHandle(UIr_log);
    CloseHandle(BDSw_log);
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
    BDSr_key = UIw_key = UIr_log = BDSw_log = NULL;
    pi.hProcess = pi.hThread = NULL;
}
static void CloseHandleS()
{
    CloseHandle(BDSr_key);
    CloseHandle(BDSw_log);
}

InitHA(BDSr_key); InitHA(UIw_key); InitHA(BDSw_log); InitHA(UIr_log);
void StartBDS()
{
    SECURITY_ATTRIBUTES sa = { sizeof(sa),NULL , TRUE };

    if(!CreatePipe(&BDSr_key, &UIw_key, &sa, 0))
        Err(_T("Failed to create pipe_key"));
    if (!CreatePipe(&UIr_log, &BDSw_log, &sa, 0))
        Err(_T("Failed to create pipe_log"));
    STARTUPINFO si = { sizeof(si) };
    si.dwFlags = STARTF_USESTDHANDLES | STARTF_USESHOWWINDOW;
    si.hStdInput = BDSr_key;
    si.hStdOutput = BDSw_log;
    //si.wShowWindow = SW_SHOWMINIMIZED;

    if (CreateProcess(
        L"bedrock_server.exe",
        NULL, NULL, NULL, TRUE, NULL, NULL, NULL, &si, &pi))
    {
        CloseHandleS();
    }
    else {
        Err(_T("Failed to send command to BDS!"));
        CloseHandleA();
    }
}

void StopBDS()
{
    if (pi.hProcess)
    {
        SendCommand_WhenStop(C("stop"));
    }
}

void ForceStopBDS()
{
    if(pi.hProcess)
    {
        TerminateProcess(pi.hProcess, 0);
        CloseHandleA();
        MessageBox(hWnd,
            _T("已尝试强行停止服务器"), TITLE,
            MB_OK);
    }
}
