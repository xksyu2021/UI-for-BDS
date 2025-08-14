#include "Win32.h"
#include "ID.h"
#include "Function.h"

static void Reflesh(HWND hwnd)
{
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
    
}

void ClearLog()
{
    std::ofstream output;
    output.open("log.txt", std::ios::out);
    output.close();
}

void Log(HWND hwnd)
{
    GetLog();
    Reflesh(hwnd);
}