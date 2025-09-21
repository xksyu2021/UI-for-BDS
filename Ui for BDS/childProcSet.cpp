#include "Win32.h"
#include "Function.h"

static void AutoMid(int Wx,int Wy, int& x, int& y)
{
    int screenWidth = GetSystemMetrics(SM_CXSCREEN);
    int screenHeight = GetSystemMetrics(SM_CYSCREEN);
    x = (screenWidth - Wx) / 2;
    y = (screenHeight - Wy) / 2;
}

HWND CreateChildWindow(HWND hFather, LPCWCHAR childTitle ,int x, int y, WNDPROC procFunc, LPCWCHAR className, HINSTANCE hInstanceF)
{
    HWND hChild = NULL;
    static WNDCLASSEX wcexF;
    wcexF.cbSize = sizeof(WNDCLASSEX);
    wcexF.style = CS_HREDRAW | CS_VREDRAW;
    wcexF.lpfnWndProc = procFunc;
    wcexF.cbClsExtra = 0;
    wcexF.cbWndExtra = 0;
    wcexF.hInstance = hInstanceF;
    wcexF.hIcon = LoadIcon(wcexF.hInstance, IDI_APPLICATION);
    wcexF.hCursor = LoadCursor(NULL, IDC_ARROW);
    wcexF.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcexF.lpszMenuName = NULL;
    wcexF.lpszClassName = className;
    wcexF.hIconSm = LoadIcon(wcexF.hInstance, IDI_APPLICATION);
    RegisterClassEx(&wcexF);
 

    hChild = CreateWindowEx(
        NULL,
        className, childTitle,
        WS_POPUP | WS_VISIBLE |  WS_CAPTION | WS_SYSMENU ,
        700, 300,
        x, y, hFather, NULL,
        hInstanceF, NULL
    );
    Err(hChild,
        _T("Create ChildWindow failed!"));
    return hChild;
}

HWND CreateLogWindow(LPCWCHAR childTitle, int x, int y, WNDPROC procFunc, LPCWCHAR className, HINSTANCE hInstanceF)
{
    HWND hChild = NULL;
    static WNDCLASSEX wcexF;
    wcexF.cbSize = sizeof(WNDCLASSEX);
    wcexF.style = CS_HREDRAW | CS_VREDRAW | CS_NOCLOSE;
    wcexF.lpfnWndProc = procFunc;
    wcexF.cbClsExtra = 0;
    wcexF.cbWndExtra = 0;
    wcexF.hInstance = hInstanceF;
    wcexF.hIcon = LoadIcon(wcexF.hInstance, IDI_APPLICATION);
    wcexF.hCursor = LoadCursor(NULL, IDC_ARROW);
    wcexF.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcexF.lpszMenuName = NULL;
    wcexF.lpszClassName = className;
    wcexF.hIconSm = LoadIcon(wcexF.hInstance, IDI_APPLICATION);
    RegisterClassEx(&wcexF);


    hChild = CreateWindowEx(
        NULL,
        className, childTitle,
        WS_POPUP | WS_VISIBLE | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX,
        1000, 400,
        x, y, NULL , NULL,
        hInstanceF, NULL
    );
    Err(hChild,
        _T("Create ChildWindow failed!"));
    return hChild;
}

HWND CreateStartWindow(int x, int y, WNDPROC procFunc, LPCWCHAR className, HINSTANCE hInstanceF)
{
    HWND hChild = NULL;
    static WNDCLASSEX wcexF;
    wcexF.cbSize = sizeof(WNDCLASSEX);
    wcexF.style = CS_HREDRAW | CS_VREDRAW | CS_NOCLOSE;
    wcexF.lpfnWndProc = procFunc;
    wcexF.cbClsExtra = 0;
    wcexF.cbWndExtra = 0;
    wcexF.hInstance = hInstanceF;
    wcexF.hIcon = LoadIcon(wcexF.hInstance, IDI_APPLICATION);
    wcexF.hCursor = LoadCursor(NULL, IDC_ARROW);
    wcexF.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcexF.lpszMenuName = NULL;
    wcexF.lpszClassName = className;
    wcexF.hIconSm = LoadIcon(wcexF.hInstance, IDI_APPLICATION);
    RegisterClassEx(&wcexF);

    int Sx, Sy;
    AutoMid(x, y, Sx, Sy);

    hChild = CreateWindowEx(
        NULL,
        className, NULL,
        WS_POPUP | WS_VISIBLE,
        Sx, Sy,
        x, y, NULL, NULL,
        hInstanceF, NULL
    );
    Err(hChild,
        _T("Create ChildWindow failed!"));
    return hChild;
}