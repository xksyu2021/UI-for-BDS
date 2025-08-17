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
        610, 600, NULL, NULL,
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

//Behavior of controls
InitHW(hTime);   InitHW(hWeather);   InitHW(hLog);   InitHW(hPlayer);
LRESULT CALLBACK TimeProc(HWND hWnd1, UINT msg, WPARAM wParam, LPARAM lParam); 
LRESULT CALLBACK WeatherProc(HWND hWnd1, UINT msg, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK LogProc(HWND hWnd1, UINT msg, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK PlayerProc(HWND hWnd1, UINT msg, WPARAM wParam, LPARAM lParam);

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    PAINTSTRUCT ps;
    HDC hdc;
    TCHAR greeting[] = _T("by xksyu2021\nYou must obey / 您必须遵守 Minecraft EULA.");

    switch (message)
    {
    case WM_CREATE:
    {
        ClearLog();
        //StartBDS();
        HINSTANCE HI_Log = NULL;
        hLog = CreateLogWindow(
            _T("日志"),
            1000, 690,
            LogProc, _T("log"), HI_Log);
        Log(GetDlgItem(hLog, ID_LOG));
        break;
    }

    case WM_PAINT:
        hdc = BeginPaint(hWnd, &ps);
        TextOut(hdc,
            5, 5,
            greeting, _tcslen(greeting));
        EndPaint(hWnd, &ps);
        break;

    case WM_COMMAND:
    {
        WORD wmId = LOWORD(wParam);
        switch (wmId)
        {
        case ID_START:
            ClearLog();
            StartBDS();
            break;
        case ID_STOP:
            StopBDS();
            break;
        case ID_STOP_FORCE:
            if (MessageBox(hWnd,
                L"强制关闭服务器是非常危险的操作！\n是否仍要继续？", TITLE,
                MB_OKCANCEL | MB_APPLMODAL | MB_ICONWARNING)
                == 1)
            {
                ForceStopBDS();
            }
            break;

        case ID_CMD_OK:
        {
            if (GetWindowTextLength(GetDlgItem(hWnd, ID_CMD_KEY)) > 0)
            {
                char Command[1024] = { 0 };
                GetWindowTextA(GetDlgItem(hWnd, ID_CMD_KEY), Command, 1024);
                std::string temp(Command);
                temp += "\n";
                SendCommand(temp.c_str());
            }
            break;
        }
        case ID_CMD_CLEAR:
            SetWindowText(GetDlgItem(hWnd, ID_CMD_KEY), _T(" "));
            break;

        case ID_FC_Weather:
            if (!hWeather)
            {
                HINSTANCE HI_FC_weather = NULL;
                hWeather = CreateChildWindow(hWnd,
                    _T("天气控制"),
                    400, 370,
                    WeatherProc, _T("fc_wea"), HI_FC_weather);
            }
            break;
        case ID_FC_Time:
            if (!hTime)
            {
                HINSTANCE HI_FC_time = NULL;
                hTime = CreateChildWindow(hWnd,
                    _T("时间控制"),
                    400, 415,
                    TimeProc, _T("fc_time"), HI_FC_time);
            }
            break;
        case ID_FS_WT:
            SendCommand(C("time query daytime"));
            SendCommand(C("weather query"));
            break;

        case ID_FC_PLAYER:
            if (!hPlayer)
            {
                HINSTANCE HI_FC_player = NULL;
                hPlayer = CreateChildWindow(hWnd,
                    _T("玩家面板"),
                    400, 370,
                    PlayerProc, _T("fc_player"), HI_FC_player);
            }
            break;
        case ID_FS_LIST:
            SendCommand(C("list"));
            break;
        }
        break;
    }
    case WM_CLOSE:
        if (MessageBox(hWnd,
            L"服务端若正在运行，将被一并关闭。", TITLE,
            MB_OKCANCEL | MB_APPLMODAL | MB_ICONWARNING)
            == 1)
        {
            StopBDS();
            PostQuitMessage(0);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
        break;
    }
    return 0;
}


