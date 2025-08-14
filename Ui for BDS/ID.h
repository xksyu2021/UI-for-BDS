#pragma once

#define InitH(x) HANDLE x = NULL
#define InitHWND(x) HWND x = NULL

#define C(x) (x "\n")

extern HANDLE UIw_key, BDSr_key, UIr_log, BDSw_log;
extern HWND hWnd;

#define TITLE _T("UI for BDS")
// #define ID_

#define ID_START 10001
#define ID_STOP 10002
#define ID_STOP_FORCE 10003
#define ID_CMD_KEY 20001
#define ID_CMD_OK 20002
#define ID_CMD_CLEAR 20003
#define ID_FC_Weather 30100
#define ID_FC_Wea_SET_1 30101
#define ID_FC_Wea_SET_2 30102
#define ID_FC_Wea_SET_3 30103
#define ID_FC_Wea_ADV 30110
#define ID_FC_Wea_OK 30120
#define ID_FC_Time 30200
#define ID_FC_Time_SET 30201
#define ID_FC_Time_ADV 30202
#define ID_FC_Time_MAN 30203
#define ID_FC_Time_OK 30210
#define ID_LOG 40001
#define ID_LOG_OUTPUT 40101