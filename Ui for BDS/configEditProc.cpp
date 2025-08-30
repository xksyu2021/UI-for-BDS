#include "Win32.h"
#include "Function.h"
#include "SharedValue.h"
#include "ConfigID.h"

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
            hWnd1, (HMENU)CONF_ServerName,
            (HINSTANCE)GetWindowLongPtr(hWnd1, GWLP_HINSTANCE), NULL
        );

        HWND hLabel_A = CreateWindow(
            L"STATIC", L"��1������ѡ���������Ϸ�浵",
            WS_VISIBLE | WS_CHILD,
            20, 95, 400, 30,
            hWnd1, NULL,
            (HINSTANCE)GetWindowLongPtr(hWnd1, GWLP_HINSTANCE), NULL
        );
        HWND hLabel_2 = CreateWindow(
            L"STATIC", L"��Ϸģʽ",
            WS_VISIBLE | WS_CHILD,
            20, 150, 100, 30,
            hWnd1, NULL,
            (HINSTANCE)GetWindowLongPtr(hWnd1, GWLP_HINSTANCE), NULL
        );
        HWND hGamemode = CreateWindow(
            L"COMBOBOX", NULL,
            WS_VISIBLE | WS_CHILD | CBS_DROPDOWNLIST,
            150, 150, 150, 100,
            hWnd1, (HMENU)CONF_GameMode,
            (HINSTANCE)GetWindowLongPtr(hWnd1, GWLP_HINSTANCE), NULL
        );
        SendMessage(hGamemode, CB_ADDSTRING, 0, (LPARAM)L"���޸�");
        SendMessage(hGamemode, CB_ADDSTRING, 0, (LPARAM)L"ð��");
        SendMessage(hGamemode, CB_ADDSTRING, 0, (LPARAM)L"����");
        SendMessage(hGamemode, CB_ADDSTRING, 0, (LPARAM)L"����");
        SendMessage(hGamemode, CB_SETCURSEL, 0, 0);
        HWND hForceGM = CreateWindow(
            L"BUTTON", L"ǿ����Ϸģʽ",
            WS_VISIBLE | WS_CHILD | BS_AUTOCHECKBOX,
            320, 145, 150, 40,
            hWnd1, (HMENU)CONF_ForeceGameMode,
            (HINSTANCE)GetWindowLongPtr(hWnd1, GWLP_HINSTANCE), NULL
        );
        HWND hLabel_3 = CreateWindow(
            L"STATIC", L"��Ϸ�Ѷ�",
            WS_VISIBLE | WS_CHILD,
            20, 195, 100, 30,
            hWnd1, NULL,
            (HINSTANCE)GetWindowLongPtr(hWnd1, GWLP_HINSTANCE), NULL
        );
        HWND hDifficulty = CreateWindow(
            L"COMBOBOX", NULL,
            WS_VISIBLE | WS_CHILD | CBS_DROPDOWNLIST,
            150, 195, 150, 100,
            hWnd1, (HMENU)CONF_GameDifficuty,
            (HINSTANCE)GetWindowLongPtr(hWnd1, GWLP_HINSTANCE), NULL
        );
        SendMessage(hDifficulty, CB_ADDSTRING, 0, (LPARAM)L"���޸�");
        SendMessage(hDifficulty, CB_ADDSTRING, 0, (LPARAM)L"��ƽ");
        SendMessage(hDifficulty, CB_ADDSTRING, 0, (LPARAM)L"��");
        SendMessage(hDifficulty, CB_ADDSTRING, 0, (LPARAM)L"��ͨ");
        SendMessage(hDifficulty, CB_ADDSTRING, 0, (LPARAM)L"����");
        SendMessageW(hDifficulty, CB_SETCURSEL, 0, 0);

        HWND hCheat = CreateWindow(
            L"BUTTON", L"����ģʽ",
            WS_VISIBLE | WS_CHILD | BS_AUTOCHECKBOX,
            20, 255, 110, 40,
            hWnd1, H_ CONF_Cheat,
            (HINSTANCE)GetWindowLongPtr(hWnd1, GWLP_HINSTANCE), NULL
        );
        HWND hCheat_1 = CreateWindow(
            L"BUTTON", L"���޸Ĵ���",
            WS_VISIBLE | WS_CHILD | BS_AUTOCHECKBOX,
            150, 255, 150, 40,
            hWnd1, H_ CONF_Cheat_NOEDIT,
            (HINSTANCE)GetWindowLongPtr(hWnd1, GWLP_HINSTANCE), NULL
        );
        SendMessage(hCheat_1, BM_SETCHECK, BST_CHECKED, 0);

        HWND hLabel_4 = CreateWindow(
            L"STATIC", L"���Ĭ��Ȩ�޵ȼ�",
            WS_VISIBLE | WS_CHILD,
            20, 320, 170, 30,
            hWnd1, NULL,
            (HINSTANCE)GetWindowLongPtr(hWnd1, GWLP_HINSTANCE), NULL
        );
        HWND hPermission = CreateWindow(
            L"COMBOBOX", NULL,
            WS_VISIBLE | WS_CHILD | CBS_DROPDOWNLIST,
            210, 320, 150, 100,
            hWnd1, (HMENU)CONF_DeflautPermission,
            (HINSTANCE)GetWindowLongPtr(hWnd1, GWLP_HINSTANCE), NULL
        );
        SendMessage(hPermission, CB_ADDSTRING, 0, (LPARAM)L"���޸�");
        SendMessage(hPermission, CB_ADDSTRING, 0, (LPARAM)L"�ÿ�");
        SendMessage(hPermission, CB_ADDSTRING, 0, (LPARAM)L"��Ա");
        SendMessage(hPermission, CB_ADDSTRING, 0, (LPARAM)L"����Ա");
        SendMessage(hPermission, CB_SETCURSEL, 0, 0);

        HWND hLabel_B = CreateWindow(
            L"STATIC", L"��2������˻���ѡ������ڷ���������",
            WS_VISIBLE | WS_CHILD,
            20, 390, 400, 30,
            hWnd1, NULL,
            (HINSTANCE)GetWindowLongPtr(hWnd1, GWLP_HINSTANCE), NULL
        );
        HWND hLabel_5 = CreateWindow(
            L"STATIC", L"ָ���浵������",
            WS_VISIBLE | WS_CHILD,
            20, 450, 170, 30,
            hWnd1, NULL,
            (HINSTANCE)GetWindowLongPtr(hWnd1, GWLP_HINSTANCE), NULL
        );
        HWND hLevelName = CreateWindow(
            L"EDIT", L"���޸�",
            WS_VISIBLE | WS_CHILD | WS_BORDER | ES_MULTILINE,
            220, 450, 300, 40,
            hWnd1, H_ CONF_LevelName,
            (HINSTANCE)GetWindowLongPtr(hWnd1, GWLP_HINSTANCE), NULL
        );
        HWND hLabel_6 = CreateWindow(
            L"STATIC", L"�½��浵������",
            WS_VISIBLE | WS_CHILD,
            20, 510, 170, 30,
            hWnd1, NULL,
            (HINSTANCE)GetWindowLongPtr(hWnd1, GWLP_HINSTANCE), NULL
        );
        HWND hLevelSeed = CreateWindow(
            L"EDIT", L"���޸�",
            WS_VISIBLE | WS_CHILD | WS_BORDER | ES_MULTILINE,
            220, 510, 300, 40,
            hWnd1, (HMENU)CONF_LevelSeed,
            (HINSTANCE)GetWindowLongPtr(hWnd1, GWLP_HINSTANCE), NULL
        );
        HWND hLabel_7 = CreateWindow(
            L"STATIC", L"����������",
            WS_VISIBLE | WS_CHILD,
            20, 570, 170, 30,
            hWnd1, NULL,
            (HINSTANCE)GetWindowLongPtr(hWnd1, GWLP_HINSTANCE), NULL
        );
        HWND hMaxPlayer = CreateWindow(
            L"EDIT", L"���޸�",
            WS_VISIBLE | WS_CHILD | WS_BORDER | ES_MULTILINE | ES_NUMBER,
            220, 570, 70, 40,
            hWnd1, (HMENU)CONF_MaxPlayer,
            (HINSTANCE)GetWindowLongPtr(hWnd1, GWLP_HINSTANCE), NULL
        );


        HWND hOnlineMode = CreateWindow(
            L"BUTTON", L"����ģʽ",
            WS_VISIBLE | WS_CHILD | BS_AUTOCHECKBOX,
            20, 650, 100, 40,
            hWnd1, (HMENU)CONF_OnlineMod,
            (HINSTANCE)GetWindowLongPtr(hWnd1, GWLP_HINSTANCE), NULL
        );
        HWND hLAN = CreateWindow(
            L"BUTTON", L"�������ɼ�",
            WS_VISIBLE | WS_CHILD | BS_AUTOCHECKBOX,
            170, 650, 130, 40,
            hWnd1, (HMENU)CONF_LanVisible,
            (HINSTANCE)GetWindowLongPtr(hWnd1, GWLP_HINSTANCE), NULL
        );
        HWND hWhiteList = CreateWindow(
            L"BUTTON", L"��ԭ��������",
            WS_VISIBLE | WS_CHILD | BS_AUTOCHECKBOX,
            320, 650, 200, 40,
            hWnd1, (HMENU)CONF_Whitelist,
            (HINSTANCE)GetWindowLongPtr(hWnd1, GWLP_HINSTANCE), NULL
        );
        HWND hOnlineMode_1 = CreateWindow(
            L"BUTTON", L"���޸�����",
            WS_VISIBLE | WS_CHILD | BS_AUTOCHECKBOX,
            20, 700, 130, 40,
            hWnd1, (HMENU)CONF_OnlineMod_NOEDIT,
            (HINSTANCE)GetWindowLongPtr(hWnd1, GWLP_HINSTANCE), NULL
        );
        HWND hLAN_1 = CreateWindow(
            L"BUTTON", L"���޸�����",
            WS_VISIBLE | WS_CHILD | BS_AUTOCHECKBOX,
            170, 700, 130, 40,
            hWnd1, (HMENU)CONF_LanVisible_NOEDIT,
            (HINSTANCE)GetWindowLongPtr(hWnd1, GWLP_HINSTANCE), NULL
        );
        HWND hWiteList_1 = CreateWindow(
            L"BUTTON", L"���޸�����",
            WS_VISIBLE | WS_CHILD | BS_AUTOCHECKBOX,
            320, 700, 130, 40,
            hWnd1, (HMENU)CONF_Whitelist_NOEDIT,
            (HINSTANCE)GetWindowLongPtr(hWnd1, GWLP_HINSTANCE), NULL
        );
        SendMessage(hOnlineMode_1, BM_SETCHECK, BST_CHECKED, 0);
        SendMessage(hLAN_1, BM_SETCHECK, BST_CHECKED, 0);
        SendMessage(hWiteList_1, BM_SETCHECK, BST_CHECKED, 0);

        HWND hLabel_C = CreateWindow(
            L"STATIC", L"��3��������ѡ���ֹ�������׷����ó�",
            WS_VISIBLE | WS_CHILD,
            20, 770, 400, 30,
            hWnd1, NULL,
            (HINSTANCE)GetWindowLongPtr(hWnd1, GWLP_HINSTANCE), NULL
        );
        HWND hFroceTexture = CreateWindow(
            L"BUTTON", L"ǿ�Ʋ��ʰ�",
            WS_VISIBLE | WS_CHILD | BS_AUTOCHECKBOX,
            20, 820, 130, 40,
            hWnd1, (HMENU)CONF_FroceTexture,
            (HINSTANCE)GetWindowLongPtr(hWnd1, GWLP_HINSTANCE), NULL
        );
        HWND hDIYskin = CreateWindow(
            L"BUTTON", L"�����Զ���Ƥ��",
            WS_VISIBLE | WS_CHILD | BS_AUTOCHECKBOX,
            165, 820, 180, 40,
            hWnd1, (HMENU)CONF_BanSkin,
            (HINSTANCE)GetWindowLongPtr(hWnd1, GWLP_HINSTANCE), NULL
        );
        HWND hMute = CreateWindow(
            L"BUTTON", L"ȫԱ����",
            WS_VISIBLE | WS_CHILD | BS_AUTOCHECKBOX,
            360, 820, 100, 40,
            hWnd1, (HMENU)CONF_Mute,
            (HINSTANCE)GetWindowLongPtr(hWnd1, GWLP_HINSTANCE), NULL
        );
        HWND hFroceTexture_1 = CreateWindow(
            L"BUTTON", L"���޸�����",
            WS_VISIBLE | WS_CHILD | BS_AUTOCHECKBOX,
            20, 870, 130, 40,
            hWnd1, (HMENU)CONF_FroceTexture_NOEDIT,
            (HINSTANCE)GetWindowLongPtr(hWnd1, GWLP_HINSTANCE), NULL
        );
        HWND hDIYskin_1 = CreateWindow(
            L"BUTTON", L"���޸�����",
            WS_VISIBLE | WS_CHILD | BS_AUTOCHECKBOX,
            165, 870, 130, 40,
            hWnd1, (HMENU)CONF_BanSkin_NOEDIT,
            (HINSTANCE)GetWindowLongPtr(hWnd1, GWLP_HINSTANCE), NULL
        );
        HWND hMute_1 = CreateWindow(
            L"BUTTON", L"���޸�����",
            WS_VISIBLE | WS_CHILD | BS_AUTOCHECKBOX,
            360, 870, 130, 40,
            hWnd1, (HMENU)CONF_Mute_NOEDIT,
            (HINSTANCE)GetWindowLongPtr(hWnd1, GWLP_HINSTANCE), NULL
        );
        SendMessage(hDIYskin_1, BM_SETCHECK, BST_CHECKED, 0);
        SendMessage(hMute_1, BM_SETCHECK, BST_CHECKED, 0);
        SendMessage(hFroceTexture_1, BM_SETCHECK, BST_CHECKED, 0);

        HWND hCompare = CreateWindow(
            L"BUTTON", L"�����У��",
            WS_VISIBLE | WS_CHILD | BS_GROUPBOX,
            20, 940, 440, 100,
            hWnd1, NULL,
            (HINSTANCE)GetWindowLongPtr(hWnd1, GWLP_HINSTANCE), NULL
        );
        HWND hCompare_1 = CreateWindow(
            L"BUTTON", L"���޸�",
            WS_VISIBLE | WS_CHILD | BS_AUTORADIOBUTTON | WS_GROUP,
            40, 980, 90, 40,
            hWnd1, (HMENU)CONF_AntiCheat_NOEDIT,
            (HINSTANCE)GetWindowLongPtr(hWnd1, GWLP_HINSTANCE), NULL
        );
        HWND hCompare_2 = CreateWindow(
            L"BUTTON", L"�ر�",
            WS_VISIBLE | WS_CHILD | BS_AUTORADIOBUTTON,
            150, 980, 80, 40,
            hWnd1, (HMENU)CONF_AntiCheat_OFF,
            (HINSTANCE)GetWindowLongPtr(hWnd1, GWLP_HINSTANCE), NULL
        );
        HWND hCompare_3 = CreateWindow(
            L"BUTTON", L"����",
            WS_VISIBLE | WS_CHILD | BS_AUTORADIOBUTTON,
            250, 980, 80, 40,
            hWnd1, (HMENU)CONF_AntiCheat_ON,
            (HINSTANCE)GetWindowLongPtr(hWnd1, GWLP_HINSTANCE), NULL
        );
        HWND hCompare_4 = CreateWindow(
            L"BUTTON", L"���ϸ�",
            WS_VISIBLE | WS_CHILD | BS_AUTORADIOBUTTON,
            350, 980, 80, 40,
            hWnd1, (HMENU)CONF_AntiCheat_STRICT,
            (HINSTANCE)GetWindowLongPtr(hWnd1, GWLP_HINSTANCE), NULL
        );
        SendMessage(hCompare_1, BM_SETCHECK, BST_CHECKED, 0);


        HWND hOpenConfig = CreateWindow(
            L"BUTTON", L"�������ļ�",
            WS_VISIBLE | WS_CHILD ,
            240, 1070, 160, 40,
            hWnd1, (HMENU)CONF_OPENCONFIG,
            (HINSTANCE)GetWindowLongPtr(hWnd1, GWLP_HINSTANCE), NULL
        );
        HWND hConfigOK = CreateWindow(
            L"BUTTON", L"�ύ",
            WS_VISIBLE | WS_CHILD ,
            410, 1070, 110, 40,
            hWnd1, (HMENU)CONF_OK,
            (HINSTANCE)GetWindowLongPtr(hWnd1, GWLP_HINSTANCE), NULL
        );

        break;
    }
    case WM_CLOSE:
    {
        INT result = MessageBox(hWnd1,
            L"�Ƿ��ύ�������ĵ����ݣ�\n�����ȡ���������༭", TITLE,
            MB_YESNOCANCEL | MB_ICONWARNING);
        if (result == IDYES)
        {

            DestroyWindow(hWnd1);
        }
        else if (result == IDNO)
        {
            DestroyWindow(hWnd1);
        }
        break;
    }
    case WM_DESTROY:
        hConfig = NULL;
        break;
    default:
        return DefWindowProc(hWnd1, msg, wParam, lParam);
	}
}