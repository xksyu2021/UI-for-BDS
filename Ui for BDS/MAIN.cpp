#include "Win32.h"
#include "ID.h"
#include "Function.h"

HWND hWnd = NULL;

static HFONT Font()
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
        L"STATIC", L"快捷命令",
        WS_VISIBLE | WS_CHILD,
        30, 255, 90, 30,
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


    HWND hOpenLog = CreateWindow(
        L"BUTTON", L"打开日志",
        WS_VISIBLE | WS_CHILD,
        302, 500, 110, 40,
        hWnd, (HMENU)ID_LOG,
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
InitHWND(hTime); 
InitHWND(hWeather);
InitHWND(hLog);
LRESULT CALLBACK TimeProc(HWND hWnd1, UINT msg, WPARAM wParam, LPARAM lParam); 
LRESULT CALLBACK WeatherProc(HWND hWnd1, UINT msg, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK LogProc(HWND hWnd1, UINT msg, WPARAM wParam, LPARAM lParam);

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    PAINTSTRUCT ps;
    HDC hdc;
    TCHAR greeting[] = _T("by xksyu2021\nYou must obey / 您必须遵守 Minecraft EULA.");

    switch (message)
    {
    case WM_CREATE:
        ClearLog();

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
                    600, 440,
                    TimeProc, _T("fc_time"), HI_FC_time);
            }
            break;
        case ID_LOG:
            if (!hLog)
            {
                HINSTANCE HI_Log = NULL;
                hLog = CreateNewWindow(
                    _T("日志"),
                    1000, 620,
                    LogProc, _T("log"), HI_Log);
            }
            break;
        }
        break;
    }
    case WM_DESTROY:
        StopBDS();
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
        break;
    }
    return 0;
}


LRESULT CALLBACK WeatherProc(HWND hWnd1, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
    case WM_CREATE:
    {
        HFONT hFont1 = Font();
        HWND hWeaSet = CreateWindow(
            L"BUTTON", L"基础选项",
            WS_VISIBLE | WS_CHILD | BS_GROUPBOX,
            20, 20, 330, 100,
            hWnd1, NULL,
            (HINSTANCE)GetWindowLongPtr(hWnd1, GWLP_HINSTANCE), NULL
        );
        HWND hWeaSet_1 = CreateWindow(
            L"BUTTON", L"晴天",
            WS_VISIBLE | WS_CHILD | BS_AUTORADIOBUTTON | WS_GROUP,
            40, 55, 80, 40,
            hWnd1, (HMENU)ID_FC_Wea_SET_1,
            (HINSTANCE)GetWindowLongPtr(hWnd1, GWLP_HINSTANCE), NULL
        );
        HWND hWeaSet_2 = CreateWindow(
            L"BUTTON", L"雨天",
            WS_VISIBLE | WS_CHILD | BS_AUTORADIOBUTTON,
           140, 55, 80, 40,
            hWnd1, (HMENU)ID_FC_Wea_SET_2,
            (HINSTANCE)GetWindowLongPtr(hWnd1, GWLP_HINSTANCE), NULL
        );
        HWND hWeaSet_3 = CreateWindow(
            L"BUTTON", L"雷暴",
            WS_VISIBLE | WS_CHILD | BS_AUTORADIOBUTTON,
            240, 55, 80, 40,
            hWnd1, (HMENU)ID_FC_Wea_SET_3,
            (HINSTANCE)GetWindowLongPtr(hWnd1, GWLP_HINSTANCE), NULL
        );


        HWND hLabel_Wea_1 = CreateWindow(
            L"STATIC", L"高级选项",
            WS_VISIBLE | WS_CHILD,
            30, 150, 80, 30,
            hWnd1, NULL,
            (HINSTANCE)GetWindowLongPtr(hWnd1, GWLP_HINSTANCE), NULL
        );

        HWND hWeaAdv = CreateWindow(
            L"BUTTON", L"天气更替",
            WS_VISIBLE | WS_CHILD | BS_AUTOCHECKBOX ,
            30, 190, 110, 40,
            hWnd1, (HMENU)ID_FC_Wea_ADV,
            (HINSTANCE)GetWindowLongPtr(hWnd1, GWLP_HINSTANCE), NULL
        );


        HWND hWeaOK = CreateWindow(
            L"BUTTON", L"提交",
            WS_VISIBLE | WS_CHILD,
            250, 250, 110, 40,
            hWnd1, (HMENU)ID_FC_Wea_OK,
            (HINSTANCE)GetWindowLongPtr(hWnd1, GWLP_HINSTANCE), NULL
        );

        SendMessage(hWeaSet_1, BM_SETCHECK, BST_CHECKED, 0);
        SendMessage(hWeaAdv, BM_SETCHECK, BST_CHECKED, 0);
    }
        break;

    case WM_COMMAND:
    {
        WORD wmId = LOWORD(wParam);
        switch (wmId)
        {
        case ID_FC_Wea_OK:
            if (IsDlgButtonChecked(hWnd1, ID_FC_Wea_ADV) == BST_CHECKED)
                SendCommand(C("gamerule doWeatherCycle true"));
            else SendCommand(C("gamerule doWeatherCycle false"));

            if (IsDlgButtonChecked(hWnd1, ID_FC_Wea_SET_1) == BST_CHECKED)
                SendCommand(C("weather clear"));
            else if (IsDlgButtonChecked(hWnd1, ID_FC_Wea_SET_2) == BST_CHECKED)
                SendCommand(C("weather rain"));
            else SendCommand(C("weather thunder"));

            DestroyWindow(hWnd1);

            break;

        default:
            break;
        }
        break;
    }
        

    case WM_CLOSE:
        DestroyWindow(hWnd1);
        break;
    case WM_DESTROY:
        hWeather = NULL;
        break;
    default:
        return DefWindowProc(hWnd1, msg, wParam, lParam);
    }
    return 0;
}

LRESULT CALLBACK TimeProc(HWND hWnd1, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
    case WM_CREATE:
    {
        HFONT hFont1 = Font();
        break;
    }
    case WM_CLOSE:
        DestroyWindow(hWnd1);
        break;
    case WM_DESTROY:
        hTime = NULL;
        break;
    default:
        return DefWindowProc(hWnd1, msg, wParam, lParam);
    }
    return 0;
}

LRESULT CALLBACK LogProc(HWND hWnd1, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg) {
    case WM_CREATE:
    {
        HFONT hFont1 = Font();
        HWND hLog = CreateWindow(
            L"EDIT", L"Null",
            WS_VISIBLE | WS_CHILD | WS_BORDER | WS_VSCROLL | ES_MULTILINE | ES_READONLY | ES_AUTOVSCROLL,
            30, 30, 910, 510,
            hWnd1, (HMENU)ID_LOG_OUTPUT,
            (HINSTANCE)GetWindowLongPtr(hWnd1, GWLP_HINSTANCE), NULL
        );
        break;
    }
    case WM_CLOSE:
        DestroyWindow(hWnd1);
        break;
    case WM_DESTROY:
        hLog = NULL;
        break;
    default:
        return DefWindowProc(hWnd1, msg, wParam, lParam);
    }
    return 0;
}