#include "Win32.h"
#include "ID.h"
#include "Function.h"
#include "SharedValue.h"

static bool statu = TRUE;

static void Reflesh(HWND hwnd)
{
    if (!statu) return;
    std::ifstream read;
    read.open("log.txt", std::ios::in);
    Err(&read, _T("打开日志文件失败"));
    std::string text(
        (std::istreambuf_iterator<char>(read)),
        std::istreambuf_iterator<char>()
    );
    read.close();
    int len = MultiByteToWideChar(CP_ACP, 0, text.c_str(), -1, NULL, 0);
    std::wstring wtext(len, 0);
    MultiByteToWideChar(CP_ACP, 0, text.c_str(), -1, &wtext[0], len);
    SetWindowText(hwnd, wtext.c_str());
    SendMessage(hwnd, WM_VSCROLL, SB_BOTTOM, 0);
}

static void GetLog()
{
    static DWORD size = 0;
    char log[10240] = { 0 };

    PeekNamedPipe(UIr_log, NULL , NULL, NULL,&size,NULL);
    if(size < 1)
    {
        statu = FALSE;
        return;
    }
     statu = ReadFile(UIr_log, log, sizeof(log), NULL, NULL);

    std::ofstream write("log.txt", std::ios::app);
    Err(&write, _T("打开日志文件失败"));
    write << log;
    write.close();
}

void ClearLog()
{
    std::ofstream clear;
    Err(&clear, _T("打开日志文件失败"));
    clear.open("log.txt", std::ios::out);
    clear.close();
}

void Log(HWND hwnd)
{
    GetLog();
    Reflesh(hwnd);
    statu = TRUE;
}