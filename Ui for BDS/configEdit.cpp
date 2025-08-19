#include "Win32.h"
#include "ID.h"
#include "Function.h"
#include "SharedValue.h"

HFONT Font();

LRESULT CALLBACK ConfProc(HWND hWnd1, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
    case WM_CREATE:
    {
        HFONT hFont = Font();

         HWND hLabel_1 = CreateWindow(
            L"STATIC", L"����������",
            WS_VISIBLE | WS_CHILD,
            20, 20, 100, 30,
            hWnd1, NULL,
            (HINSTANCE)GetWindowLongPtr(hWnd1, GWLP_HINSTANCE), NULL
        );
        HWND hServerName = CreateWindow(
            L"EDIT", L"���޸�",
            WS_VISIBLE | WS_CHILD | WS_BORDER |  ES_MULTILINE,
            150, 20, 300, 40,
            hWnd1, (HMENU)NULL,
            (HINSTANCE)GetWindowLongPtr(hWnd1, GWLP_HINSTANCE), NULL
        );

        HWND hLabel_2 = CreateWindow(
            L"STATIC", L"��Ϸģʽ",
            WS_VISIBLE | WS_CHILD,
            20, 85, 100, 30,
            hWnd1, NULL,
            (HINSTANCE)GetWindowLongPtr(hWnd1, GWLP_HINSTANCE), NULL
        );
        HWND hGamemode = CreateWindow(
            L"COMBOBOX", NULL,
            WS_VISIBLE | WS_CHILD | CBS_DROPDOWNLIST,
            150, 85, 150, 100,
            hWnd1, (HMENU)NULL,
            (HINSTANCE)GetWindowLongPtr(hWnd1, GWLP_HINSTANCE), NULL
        );
        SendMessage(hGamemode, CB_ADDSTRING, 0, (LPARAM)L"���޸�");
        SendMessage(hGamemode, CB_ADDSTRING, 0, (LPARAM)L"ð��");
        SendMessage(hGamemode, CB_ADDSTRING, 0, (LPARAM)L"����");
        SendMessage(hGamemode, CB_ADDSTRING, 0, (LPARAM)L"����");
        HWND hForceGM = CreateWindow(
            L"BUTTON", L"ǿ����Ϸģʽ",
            WS_VISIBLE | WS_CHILD | BS_AUTOCHECKBOX,
            320, 80, 150, 40,
            hWnd1, (HMENU)NULL,
            (HINSTANCE)GetWindowLongPtr(hWnd1, GWLP_HINSTANCE), NULL
        );
        HWND hLabel_3 = CreateWindow(
            L"STATIC", L"��Ϸ�Ѷ�",
            WS_VISIBLE | WS_CHILD,
            20, 150, 100, 30,
            hWnd1, NULL,
            (HINSTANCE)GetWindowLongPtr(hWnd1, GWLP_HINSTANCE), NULL
        );
        HWND hDifficulty = CreateWindow(
            L"COMBOBOX", NULL,
            WS_VISIBLE | WS_CHILD | CBS_DROPDOWNLIST,
            150, 150, 150, 100,
            hWnd1, (HMENU)NULL,
            (HINSTANCE)GetWindowLongPtr(hWnd1, GWLP_HINSTANCE), NULL
        );
        SendMessage(hDifficulty, CB_ADDSTRING, 0, (LPARAM)L"���޸�");
        SendMessage(hDifficulty, CB_ADDSTRING, 0, (LPARAM)L"��ƽ");
        SendMessage(hDifficulty, CB_ADDSTRING, 0, (LPARAM)L"��");
        SendMessage(hDifficulty, CB_ADDSTRING, 0, (LPARAM)L"��ͨ");
        SendMessage(hDifficulty, CB_ADDSTRING, 0, (LPARAM)L"����");

        HWND hCheat = CreateWindow(
            L"BUTTON", L"����ģʽ",
            WS_VISIBLE | WS_CHILD | BS_AUTOCHECKBOX,
            20, 210, 110, 40,
            hWnd1, NULL,
            (HINSTANCE)GetWindowLongPtr(hWnd1, GWLP_HINSTANCE), NULL
        );
        HWND hCheat_1 = CreateWindow(
            L"BUTTON", L"���޸Ĵ���",
            WS_VISIBLE | WS_CHILD | BS_AUTOCHECKBOX,
            150, 210, 150, 40,
            hWnd1, NULL,
            (HINSTANCE)GetWindowLongPtr(hWnd1, GWLP_HINSTANCE), NULL
        );
        SendMessage(hCheat_1, BM_SETCHECK, BST_CHECKED, 0);

        break;
    }
    case WM_CLOSE:
        DestroyWindow(hWnd1);
        break;
    case WM_DESTROY:
        hConfig = NULL;
        break;
    default:
        return DefWindowProc(hWnd1, msg, wParam, lParam);
	}
}