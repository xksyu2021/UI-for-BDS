#include "Win32.h"
#include "ID.h"
#include "Function.h"
#include "SharedValue.h"

InitHW(hTime);   InitHW(hWeather);   InitHW(hLog);   InitHW(hPlayer); InitHW(hConfig); InitHW(hBackup);

LRESULT CALLBACK TimeProc(HWND hWnd1, UINT msg, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK WeatherProc(HWND hWnd1, UINT msg, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK LogProc(HWND hWnd1, UINT msg, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK PlayerProc(HWND hWnd1, UINT msg, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK ConfProc(HWND hWnd1, UINT msg, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK BkProc(HWND hWnd1, UINT msg, WPARAM wParam, LPARAM lParam);


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

        //MessageBox(hWnd,
        //    L"测试版程序\n数据无价，谨慎操作！", TITLE,
        //    MB_OK | MB_ICONWARNING);

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

        case ID_DUWP:
            ShellExecute(
                NULL, L"runas",
                L"C:\\windows\\system32\\WindowsPowerShell\\v1.0\\powershell.exe",
                L"-NoProfile -ExecutionPolicy Bypass -Command \"Get-ChildItem -Path Registry::'HKCU\\Software\\Classes\\Local Settings\\Software\\Microsoft\\Windows\\CurrentVersion\\AppContainer\\Mappings\\' -name | ForEach-Object {CheckNetIsolation.exe LoopbackExempt -a -p=$_}\"" ,               
                NULL, SW_SHOWNORMAL
            );
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
            if (SendCommand_NoErr(C("time query daytime")) == FALSE  || 
                SendCommand_NoErr(C("weather query")) == FALSE)
            {
                Err(_T("发送命令失败\n可能是因为服务器已被关闭"));
            }
            break;

        case ID_FC_PLAYER:
            if (!hPlayer)
            {
                HINSTANCE HI_FC_player = NULL;
                hPlayer = CreateChildWindow(hWnd,
                    _T("玩家面板"),
                    380, 390,
                    PlayerProc, _T("fc_player"), HI_FC_player);
            }
            break;
        case ID_FS_LIST:
            SendCommand(C("list"));
            break;
        case ID_FILE_Config:
            if (!hConfig)
            {
                HINSTANCE HI_FI_config = NULL;
                hConfig = CreateChildWindow(hWnd,
                    _T("配置文件编辑"),
                    570, 1200,
                    ConfProc, _T("file_conf"), HI_FI_config);
            }
            break;
        case ID_FILE_Backup:
            if (!hBackup)
            {
                HINSTANCE HI_FI_backup = NULL;
                hBackup = CreateChildWindow(hWnd,
                    _T("备份与恢复"),
                    460, 400,
                    BkProc, _T("file_backup"), HI_FI_backup);
            }
        }
        break;
    }
    case WM_CLOSE:
        if (MessageBox(hWnd,
            L"您正在关闭主程序！\n若服务端正在运行，将被一并正常关闭。\n若有正在执行的任务，将被强行停止。", TITLE,
            MB_OKCANCEL  | MB_ICONWARNING)
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
