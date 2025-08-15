#include "Win32.h"
#include "ID.h"
#include "Function.h"

static  DWORD size = 0;
static bool statu = TRUE;

static void Reflesh(HWND hwnd)
{
    if (!statu) return;
    std::ifstream read;
    read.open("log.txt", std::ios::in);
    Err(&read, _T("Failed to open log.txt"));
    std::string text(
        (std::istreambuf_iterator<char>(read)),
        std::istreambuf_iterator<char>()
    );
    read.close();
    int len = MultiByteToWideChar(CP_ACP, 0, text.c_str(), -1, NULL, 0);
    std::wstring wtext(len, 0);
    MultiByteToWideChar(CP_ACP, 0, text.c_str(), -1, &wtext[0], len);
    SetWindowText(hwnd, wtext.c_str());
}

static void GetLog()
{
    char log[4096] = { 0 };
    statu = ReadFile(UIr_log, log, sizeof(log), &size, NULL);
    if (!statu || size < 4) 
    {
        statu = FALSE;
        return;
    }
    std::ofstream write("log.txt", std::ios::app);
    Err(&write, _T("Failed to open log.txt"));
    write << log;
    write.close();
}

void ClearLog()
{
    std::ofstream clear;
    Err(&clear, _T("Failed to open log.txt"));
    clear.open("log.txt", std::ios::out);
    clear.close();
}

void Log(HWND hwnd)
{
    GetLog();
    Reflesh(hwnd);
    size = 0;
}