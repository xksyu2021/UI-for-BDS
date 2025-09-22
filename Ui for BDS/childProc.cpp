#include "Win32.h"
#include "ID.h"
#include "Function.h"
#include "SharedValue.h"

HFONT Font();

LRESULT CALLBACK StartProc(HWND hWnd1, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
    case WM_DESTROY:
        hStart = NULL;
        break;
    default:
        return DefWindowProc(hWnd1, msg, wParam, lParam);
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
            WS_VISIBLE | WS_CHILD | BS_AUTOCHECKBOX,
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
        HWND hWeaSet = CreateWindow(
            L"BUTTON", L"快速设定",
            WS_VISIBLE | WS_CHILD | BS_GROUPBOX,
            20, 20, 330, 150,
            hWnd1, NULL,
            (HINSTANCE)GetWindowLongPtr(hWnd1, GWLP_HINSTANCE), NULL
        );
        HWND hTimeSet_1 = CreateWindow(
            L"BUTTON", L"日出",
            WS_VISIBLE | WS_CHILD | BS_AUTORADIOBUTTON | WS_GROUP,
            40, 55, 80, 40,
            hWnd1, (HMENU)ID_FC_Time_SET_1,
            (HINSTANCE)GetWindowLongPtr(hWnd1, GWLP_HINSTANCE), NULL
        );
        HWND hTimeSet_2 = CreateWindow(
            L"BUTTON", L"白日",
            WS_VISIBLE | WS_CHILD | BS_AUTORADIOBUTTON,
            140, 55, 80, 40,
            hWnd1, (HMENU)ID_FC_Time_SET_2,
            (HINSTANCE)GetWindowLongPtr(hWnd1, GWLP_HINSTANCE), NULL
        );
        HWND hTimeSet_3 = CreateWindow(
            L"BUTTON", L"正午",
            WS_VISIBLE | WS_CHILD | BS_AUTORADIOBUTTON,
            240, 55, 80, 40,
            hWnd1, (HMENU)ID_FC_Time_SET_3,
            (HINSTANCE)GetWindowLongPtr(hWnd1, GWLP_HINSTANCE), NULL
        );
        HWND hTimeSet_4 = CreateWindow(
            L"BUTTON", L"日落",
            WS_VISIBLE | WS_CHILD | BS_AUTORADIOBUTTON,
            40, 115, 80, 40,
            hWnd1, (HMENU)ID_FC_Time_SET_4,
            (HINSTANCE)GetWindowLongPtr(hWnd1, GWLP_HINSTANCE), NULL
        );
        HWND hTimeSet_5 = CreateWindow(
            L"BUTTON", L"夜晚",
            WS_VISIBLE | WS_CHILD | BS_AUTORADIOBUTTON,
            140, 115, 80, 40,
            hWnd1, (HMENU)ID_FC_Time_SET_5,
            (HINSTANCE)GetWindowLongPtr(hWnd1, GWLP_HINSTANCE), NULL
        );
        HWND hTimeSet_6 = CreateWindow(
            L"BUTTON", L"午夜",
            WS_VISIBLE | WS_CHILD | BS_AUTORADIOBUTTON,
            240, 115, 80, 40,
            hWnd1, (HMENU)ID_FC_Time_SET_6,
            (HINSTANCE)GetWindowLongPtr(hWnd1, GWLP_HINSTANCE), NULL
        );


        HWND hLabel_Wea_1 = CreateWindow(
            L"STATIC", L"高级选项",
            WS_VISIBLE | WS_CHILD,
            30, 210, 80, 30,
            hWnd1, NULL,
            (HINSTANCE)GetWindowLongPtr(hWnd1, GWLP_HINSTANCE), NULL
        );

        HWND hTimeAdv = CreateWindow(
            L"BUTTON", L"时间更替",
            WS_VISIBLE | WS_CHILD | BS_AUTOCHECKBOX,
            30, 250, 110, 40,
            hWnd1, (HMENU)ID_FC_Time_ADV,
            (HINSTANCE)GetWindowLongPtr(hWnd1, GWLP_HINSTANCE), NULL
        );


        HWND hWeaOK = CreateWindow(
            L"BUTTON", L"提交",
            WS_VISIBLE | WS_CHILD,
            250, 300, 110, 40,
            hWnd1, (HMENU)ID_FC_Time_OK,
            (HINSTANCE)GetWindowLongPtr(hWnd1, GWLP_HINSTANCE), NULL
        );

        SendMessage(hTimeSet_3, BM_SETCHECK, BST_CHECKED, 0);
        SendMessage(hTimeAdv, BM_SETCHECK, BST_CHECKED, 0);
    }
    break;

    case WM_COMMAND:
    {
        WORD wmId = LOWORD(wParam);
        switch (wmId)
        {
        case ID_FC_Time_OK:
            if (IsDlgButtonChecked(hWnd1, ID_FC_Time_ADV) == BST_CHECKED)
                SendCommand(C("gamerule doDaylightCycle true"));
            else SendCommand(C("gamerule doDaylightCycle false"));

            if (IsDlgButtonChecked(hWnd1, ID_FC_Wea_SET_1) == BST_CHECKED)
                SendCommand(C("time set sunrise"));
            else if (IsDlgButtonChecked(hWnd1, ID_FC_Time_SET_2) == BST_CHECKED)
                SendCommand(C("time set day"));
            else if (IsDlgButtonChecked(hWnd1, ID_FC_Time_SET_3) == BST_CHECKED)
                SendCommand(C("time set noon"));
            else if (IsDlgButtonChecked(hWnd1, ID_FC_Time_SET_4) == BST_CHECKED)
                SendCommand(C("time set sunset"));
            else if (IsDlgButtonChecked(hWnd1, ID_FC_Time_SET_5) == BST_CHECKED)
                SendCommand(C("time set night"));
            else SendCommand(C("time set midnight"));

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
        hTime = NULL;
        break;
    default:
        return DefWindowProc(hWnd1, msg, wParam, lParam);
    }
    return 0;
    return 0;
}

LRESULT CALLBACK LogProc(HWND hWnd1, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg) {
    case WM_CREATE:
    {
        SetTimer(hWnd1, 1, 100, NULL);
        HFONT hFont1 = Font();
        HWND hLog = CreateWindow(
            L"EDIT", L"Null",
            WS_VISIBLE | WS_CHILD | WS_BORDER | WS_VSCROLL | ES_MULTILINE | ES_READONLY | ES_AUTOVSCROLL,
            30, 30, 910, 510,
            hWnd1, (HMENU)ID_LOG,
            (HINSTANCE)GetWindowLongPtr(hWnd1, GWLP_HINSTANCE), NULL
        );
        HWND hLogClear = CreateWindow(
            L"BUTTON", L"清除日志",
            WS_VISIBLE | WS_CHILD,
            790, 570, 110, 40,
            hWnd1, (HMENU)ID_LOG_CLEAR,
            (HINSTANCE)GetWindowLongPtr(hWnd1, GWLP_HINSTANCE), NULL
        );
        break;
    }
    case WM_COMMAND:
    {
        WORD wmId = LOWORD(wParam);
        switch (wmId)
        {
        case ID_LOG_CLEAR:
            if (MessageBox(hWnd1,
                L"是否要清除所有日志？", TITLE,
                MB_OKCANCEL | MB_APPLMODAL | MB_ICONQUESTION)
                == IDOK)
            {
                ClearLog();
                SetWindowText(GetDlgItem(hWnd1, ID_LOG), _T("Null"));
            }
            break;
        default:
            break;
        }
        break;
    }
    case WM_TIMER:
        Log(GetDlgItem(hLog, ID_LOG));
        break;
    case WM_CLOSE:
        break;
    case WM_DESTROY:
        KillTimer(hWnd1, 1);
        hLog = NULL;
        break;
    default:
        return DefWindowProc(hWnd1, msg, wParam, lParam);
    }
    return 0;
}

LRESULT CALLBACK PlayerProc(HWND hWnd1, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
    case WM_CREATE:
    {
        HFONT hFont1 = Font();
        HWND hLabel_1 = CreateWindow(
            L"STATIC", L"操作类型",
            WS_VISIBLE | WS_CHILD,
            20, 20, 100, 30,
            hWnd1, NULL,
            (HINSTANCE)GetWindowLongPtr(hWnd1, GWLP_HINSTANCE), NULL
        );
        HWND hCmdType = CreateWindow(
            L"COMBOBOX", NULL,
            WS_VISIBLE | WS_CHILD | CBS_DROPDOWNLIST,
            130, 20, 200, 160,
            hWnd1, (HMENU)ID_FC_Player_TYPE,
            (HINSTANCE)GetWindowLongPtr(hWnd1, GWLP_HINSTANCE), NULL
        );
        SendMessage(hCmdType, CB_ADDSTRING, 0, (LPARAM)L"踢出服务器");
        SendMessage(hCmdType, CB_ADDSTRING, 0, (LPARAM)L"赋予管理员权限");
        SendMessage(hCmdType, CB_ADDSTRING, 0, (LPARAM)L"撤销管理员权限");
        SendMessage(hCmdType, CB_ADDSTRING, 0, (LPARAM)L"更改游戏模式");
        SendMessage(hCmdType, CB_ADDSTRING, 0, (LPARAM)L"使玩家失败");
        SendMessage(hCmdType, CB_ADDSTRING, 0, (LPARAM)L"发送私密消息");

        HWND hLabel_2 = CreateWindow(
            L"STATIC", L"玩家ID",
            WS_VISIBLE | WS_CHILD,
            20, 70, 60, 30,
            hWnd1, NULL,
            (HINSTANCE)GetWindowLongPtr(hWnd1, GWLP_HINSTANCE), NULL
        );
        HWND hPlayerSelect = CreateWindow(
            L"EDIT", NULL,
            WS_VISIBLE | WS_CHILD | WS_BORDER | ES_LEFT | ES_MULTILINE | ES_AUTOHSCROLL,
            20, 90, 310, 40,
            hWnd1, (HMENU)ID_FC_Player_LIST,
            (HINSTANCE)GetWindowLongPtr(hWnd1, GWLP_HINSTANCE), NULL
        );

        HWND hLabel_3 = CreateWindow(
            L"STATIC", L"消息内容",
            WS_CHILD,
            20, 150, 90, 30,
            hWnd1, (HMENU)ID_FC_Player_TEXT_s,
            (HINSTANCE)GetWindowLongPtr(hWnd1, GWLP_HINSTANCE), NULL
        );
        HWND hText = CreateWindow(
            L"EDIT", NULL,
            WS_CHILD | WS_BORDER | ES_LEFT | ES_MULTILINE | ES_AUTOVSCROLL,
            20, 170, 310, 90,
            hWnd1, (HMENU)ID_FC_Player_TEXT,
            (HINSTANCE)GetWindowLongPtr(hWnd1, GWLP_HINSTANCE), NULL
        );

        HWND hLabel_4 = CreateWindow(
            L"STATIC", L"游戏模式",
            WS_CHILD,
            20, 150, 100, 30,
            hWnd1, (HMENU)ID_FC_Player_GM_s,
            (HINSTANCE)GetWindowLongPtr(hWnd1, GWLP_HINSTANCE), NULL
        );
        HWND hGMtype = CreateWindow(
            L"COMBOBOX", NULL,
            WS_CHILD | CBS_DROPDOWNLIST,
            130, 150, 200, 160,
            hWnd1, (HMENU)ID_FC_Player_GM,
            (HINSTANCE)GetWindowLongPtr(hWnd1, GWLP_HINSTANCE), NULL
        );
        SendMessage(hGMtype, CB_ADDSTRING, 0, (LPARAM)L"冒险");
        SendMessage(hGMtype, CB_ADDSTRING, 0, (LPARAM)L"生存");
        SendMessage(hGMtype, CB_ADDSTRING, 0, (LPARAM)L"创造");
        SendMessage(hGMtype, CB_ADDSTRING, 0, (LPARAM)L"旁观");


        HWND hPlayerOK = CreateWindow(
            L"BUTTON", L"提交",
            WS_VISIBLE | WS_CHILD,
            220, 280, 110, 40,
            hWnd1, (HMENU)ID_FC_Player_OK,
            (HINSTANCE)GetWindowLongPtr(hWnd1, GWLP_HINSTANCE), NULL
        );

    }
    break;

    case WM_COMMAND:
    {
        WORD wmId = LOWORD(wParam);

        WORD wmEvent = HIWORD(wParam);
        if (wmEvent == CBN_SELCHANGE && wmId == ID_FC_Player_TYPE)
        {
            int selected = SendMessage(GetDlgItem(hWnd1, ID_FC_Player_TYPE), CB_GETCURSEL, 0, 0);
            ShowWindow(GetDlgItem(hWnd1, ID_FC_Player_GM), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd1, ID_FC_Player_TEXT), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd1, ID_FC_Player_GM_s), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd1, ID_FC_Player_TEXT_s), SW_HIDE);
            switch (selected)
            {
            case 3:
                ShowWindow(GetDlgItem(hWnd1, ID_FC_Player_GM), SW_SHOW);
                ShowWindow(GetDlgItem(hWnd1, ID_FC_Player_GM_s), SW_SHOW);
                break;
            case 5:
                ShowWindow(GetDlgItem(hWnd1, ID_FC_Player_TEXT), SW_SHOW);
                ShowWindow(GetDlgItem(hWnd1, ID_FC_Player_TEXT_s), SW_SHOW);
                break;
            }
        }

        switch (wmId)
        {
        case ID_FC_Player_OK:
        {
            char ID[512] = {0};
            char TEXT[2048] = { 0 };
            GetWindowTextA(GetDlgItem(hWnd1, ID_FC_Player_LIST), ID, 512);
            GetWindowTextA(GetDlgItem(hWnd1, ID_FC_Player_TEXT), TEXT, 512);
            int type = SendMessage(GetDlgItem(hWnd1, ID_FC_Player_TYPE), CB_GETCURSEL, 0, 0);
            switch (type)
            {
            case 0:
            {
                SendCommand_WithID("kick", ID, "");
                break;
            }
            case 1:
            {
                SendCommand_WithID("op", ID, "");
                break;
            }
            case 2:
            {
                SendCommand_WithID("deop", ID, "");
                break;
            }
            case 3:
            {
                int gm = SendMessage(GetDlgItem(hWnd1, ID_FC_Player_GM), CB_GETCURSEL, 0, 0);
                switch (gm)
                {
                case 0:
                {
                    SendCommand_WithID("gamemode 2", ID, "");
                    break;
                }
                case 1:
                {
                    SendCommand_WithID("gamemode 0", ID, "");
                    break;
                }
                case 2:
                {
                    SendCommand_WithID("gamemode 1", ID, "");
                    break;
                }
                case 3:
                {
                    SendCommand_WithID("gamemode 3", ID, "");
                    break;
                }
                default:
                    break;
                }
            }
            case 4:
            {
                SendCommand_WithID("kill", ID, "");
                break;
            }
            case 5:
                SendCommand_WithID("msg", ID, TEXT);
                break;
            }

            MessageBox(hWnd1, L"已发送指令", TITLE, MB_OK);
            DestroyWindow(hWnd1);
            break;
        }

        default:
            break;
        }
        break;
    }


    case WM_CLOSE:
        DestroyWindow(hWnd1);
        break;
    case WM_DESTROY:
        hPlayer = NULL;
        break;
    default:
        return DefWindowProc(hWnd1, msg, wParam, lParam);
    }
    return 0;
}

LRESULT CALLBACK BkProc(HWND hWnd1, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch(msg)
    {
    case WM_CREATE:
    {
        HWND hLabel_1 = CreateWindow(
            L"STATIC", L"备份选项",
            WS_VISIBLE | WS_CHILD,
            20, 20, 100, 30,
            hWnd1, NULL,
            (HINSTANCE)GetWindowLongPtr(hWnd1, GWLP_HINSTANCE), NULL
        );
        HWND hLevelBk = CreateWindow(
            L"BUTTON", L"备份存档",
            WS_VISIBLE | WS_CHILD,
            30,70,  110, 40,
            hWnd1, H_ ID_FILE_Bk_Level,
            (HINSTANCE)GetWindowLongPtr(hWnd1, GWLP_HINSTANCE), NULL
        );
        HWND hAllBk = CreateWindow(
            L"BUTTON", L"备份全部文件",
            WS_VISIBLE | WS_CHILD,
            150,70,  170, 40,
            hWnd1, H_ ID_FILE_Bk_All,
            (HINSTANCE)GetWindowLongPtr(hWnd1, GWLP_HINSTANCE), NULL
        );
        HWND hBkCover = CreateWindow(
            L"BUTTON", L"覆盖相应先前备份",
            WS_VISIBLE | WS_CHILD | BS_AUTOCHECKBOX,
            30, 125, 210, 40,
            hWnd1, H_ ID_FILE_Bk_Cover,
            (HINSTANCE)GetWindowLongPtr(hWnd1, GWLP_HINSTANCE), NULL
        );
        HWND hLabel_2 = CreateWindow(
            L"STATIC", L"还原选项（应用会自动识别类型）",
            WS_VISIBLE | WS_CHILD,
            20, 200, 290, 30,
            hWnd1, NULL,
            (HINSTANCE)GetWindowLongPtr(hWnd1, GWLP_HINSTANCE), NULL
        );
        HWND hRec = CreateWindow(
            L"BUTTON", L"选择文件",
            WS_VISIBLE | WS_CHILD,
            30, 245, 110, 40,
            hWnd1, H_ ID_FILE_Bk_Open,
            (HINSTANCE)GetWindowLongPtr(hWnd1, GWLP_HINSTANCE), NULL
        );
        break;
    }

    case WM_COMMAND:
    {
        WORD wmId = LOWORD(wParam);
        switch (wmId)
        {
        case ID_FILE_Bk_Level:

            break;
        case ID_FILE_Bk_All:

            break;
        case ID_FILE_Bk_Open:

            break;
        }
        break;
    }

    case WM_CLOSE:
        DestroyWindow(hWnd1);
        break;
    case WM_DESTROY:
        hBackup = NULL;
        break;
    default:
        return DefWindowProc(hWnd1, msg, wParam, lParam);
    }
    return 0;
}

