#include "Win32.h"
#include "ID.h"
#include "Function.h"
#include "SharedValue.h"

HWND hWnd = NULL;

HFONT Font()
{
    HFONT hFont = CreateFont(
        -40,
        0, 0, 0,
        FW_NORMAL, FALSE, FALSE, FALSE,
        DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
        ANTIALIASED_QUALITY,
        FF_ROMAN,
        L"Arial"
    );
    return hFont;
}

//Basic info
static TCHAR szWindowClass[] = _T("ufb"); 
static TCHAR szTitle[] = TITLE;
HINSTANCE hInst;
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(
    _In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPSTR     lpCmdLine,
    _In_ int       nCmdShow
)
{
    // Window config
    WNDCLASSEX wcex;
    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(wcex.hInstance, IDI_APPLICATION);
    wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = NULL;
    wcex.lpszClassName = szWindowClass;
    wcex.hIconSm = LoadIcon(wcex.hInstance, IDI_APPLICATION);
    Err(RegisterClassEx(&wcex),
        _T("Call to RegisterClassEx failed!"));
   
    //Create window
    hInst = hInstance;
    hWnd = CreateWindowEx(
        WS_EX_OVERLAPPEDWINDOW,
        szWindowClass, szTitle,
        WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX,
        CW_USEDEFAULT, CW_USEDEFAULT,
        610, 800, NULL, NULL,
        hInstance, NULL
    );
    Err(hWnd,
        _T("Call to CreateWindow failed!"));
 
    //Create controls
    HWND hLabel_1 = CreateWindow(
        L"STATIC", L"基础操作",
        WS_VISIBLE | WS_CHILD,
        30, 55, 90, 30,
        hWnd, NULL,
        (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE), NULL
    );
    HWND hStart = CreateWindow(
        L"BUTTON", L"启动",
        WS_VISIBLE | WS_CHILD,
        30, 100, 70, 40,
        hWnd, (HMENU)ID_START,
        (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE), NULL
    );
    HWND hStop = CreateWindow(
        L"BUTTON", L"停止",
        WS_VISIBLE | WS_CHILD,
        120, 100, 70, 40,
        hWnd, (HMENU)ID_STOP,
        (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE), NULL
    );
    HWND hStopForce = CreateWindow(
        L"BUTTON", L"强行停止",
        WS_VISIBLE | WS_CHILD,
        210, 100, 110, 40,
        hWnd, (HMENU)ID_STOP_FORCE,
        (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE), NULL
    );
    HWND hUWP = CreateWindow(
        L"BUTTON", L"解除回环",
        /*WS_VISIBLE | */WS_CHILD,
        340, 100, 110, 40,
        hWnd, (HMENU)ID_DUWP,
        (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE), NULL
    );


    HWND hLabel_2 = CreateWindow(
        L"STATIC", L"命令输入",
        WS_VISIBLE | WS_CHILD,
        30, 155, 90, 30,
        hWnd, NULL,
        (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE), NULL
    );
    HWND hCmdKey = CreateWindow(
        L"EDIT", NULL,
        WS_VISIBLE | WS_CHILD | WS_BORDER | ES_LEFT | ES_MULTILINE | ES_AUTOHSCROLL,
        30, 200, 350, 40,
        hWnd, (HMENU)ID_CMD_KEY,
        (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE), NULL
    );
    HWND hCmdSend = CreateWindow(
        L"BUTTON", L"执行",
        WS_VISIBLE | WS_CHILD,
        400, 200, 70, 40,
        hWnd, (HMENU)ID_CMD_OK,
        (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE), NULL
    );
    HWND hCmdClear = CreateWindow(
        L"BUTTON", L"清空",
        WS_VISIBLE | WS_CHILD,
        490, 200, 70, 40,
        hWnd, (HMENU)ID_CMD_CLEAR,
        (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE), NULL
    );


    HWND hLabel_3 = CreateWindow(
        L"STATIC", L"时间和天气",
        WS_VISIBLE | WS_CHILD,
        30, 255, 110, 30,
        hWnd, NULL,
        (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE), NULL
    );
    HWND hFCweather = CreateWindow(
        L"BUTTON", L"天气控制",
        WS_VISIBLE | WS_CHILD,
        30, 300, 110, 40,
        hWnd, (HMENU)ID_FC_Weather,
        (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE), NULL
    );
    HWND hFCtime = CreateWindow(
        L"BUTTON", L"时间控制",
        WS_VISIBLE | WS_CHILD,
        160, 300, 110, 40,
        hWnd, (HMENU)ID_FC_Time,
        (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE), NULL
    );
    HWND hFSwt = CreateWindow(
        L"BUTTON", L"查询时间和天气",
        WS_VISIBLE | WS_CHILD,
        290, 300, 180, 40,
        hWnd, (HMENU)ID_FS_WT,
        (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE), NULL
    );
   

    HWND hLabel_4 = CreateWindow(
        L"STATIC", L"在线玩家操作",
        WS_VISIBLE | WS_CHILD,
        30, 365, 130, 30,
        hWnd, NULL,
        (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE), NULL
    );
    HWND hFClevel = CreateWindow(
        L"BUTTON", L"打开面板",
        WS_VISIBLE | WS_CHILD,
        30, 410, 110, 40,
        hWnd, (HMENU)ID_FC_PLAYER,
        (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE), NULL
    );
    HWND hFSlist = CreateWindow(
        L"BUTTON", L"查询在线玩家",
        WS_VISIBLE | WS_CHILD,
        160, 410, 150, 40,
        hWnd, (HMENU)ID_FS_LIST,
        (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE), NULL
    );

    HWND hLabel_5 = CreateWindow(
        L"STATIC", L"文件与配置操作",
        WS_VISIBLE | WS_CHILD,
        30, 470, 150, 30,
        hWnd, NULL,
        (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE), NULL
    );
    HWND hFIconf = CreateWindow(
        L"BUTTON", L"编辑配置文件",
        WS_VISIBLE | WS_CHILD,
        30, 510, 150, 40,
        hWnd, (HMENU)ID_FILE_Config,
        (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE), NULL
    );
    HWND hFIbk = CreateWindow(
        L"BUTTON", L"备份存档",
        WS_VISIBLE | WS_CHILD,
        210, 510, 110, 40,
        hWnd, (HMENU)ID_FILE_Backup,
        (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE), NULL
    );

    //Font
    HFONT hFont = CreateFont(
        -40,
        0, 0, 0,
        FW_NORMAL, FALSE, FALSE, FALSE,
        DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
        ANTIALIASED_QUALITY,
        FF_ROMAN,
        L"Arial"
    );
    SendMessage(hWnd, WM_SETFONT, (WPARAM)hFont, TRUE);

    //Visibility & Loop
    ShowWindow(hWnd,
        nCmdShow);
    UpdateWindow(hWnd);
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return (int)msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);


