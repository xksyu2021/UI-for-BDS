#include "Win32.h"
#include "ID.h"
#include "Function.h"

HWND CreateChildWindow(HWND hFather, HWND hChild, LPCWCHAR childTitle ,int x, int y, WNDPROC procFunc, LPCWCHAR className, HINSTANCE hInstanceF)
{
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
    Err(RegisterClassEx(&wcexF),
        _T("Call to RegisterClassEx failed!"));

    hChild = CreateWindowEx(
        WS_EX_OVERLAPPEDWINDOW,
        className, childTitle,
        WS_CHILD | WS_VISIBLE | WS_BORDER,
        CW_USEDEFAULT, CW_USEDEFAULT,
        x, y, NULL, NULL,
        hInstanceF, NULL
    );
    Err(hChild,
        _T("CreateChildWindow failed!"));
    return hChild;
}