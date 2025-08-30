#pragma once

#define InitHA(x) HANDLE x = NULL
#define InitHW(x) HWND x = NULL
#define H_ (HMENU)

#define C(x) (x "\n")

extern HANDLE UIw_key, BDSr_key, UIr_log, BDSw_log;
extern HWND hWnd, hLog, hTime, hWeather, hPlayer, hConfig;

#define TITLE _T("UI for BDS")

#define TEST MessageBox(hWnd,L"Success!",L"step test",MB_OK)