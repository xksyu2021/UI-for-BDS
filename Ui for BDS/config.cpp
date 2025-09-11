#include "Win32.h"
#include "Config.h"
#include "Function.h"
#include "SharedValue.h"

#include <vector>

void Update(HWND hWnd1, int id, int id1 )
{
	if (wmEvent == BN_CLICKED && wmId == id)
		SendMessage(GetDlgItem(hWnd1,id1), BM_SETCHECK, BST_UNCHECKED, 0);
}

//basic
static std::vector<std::string> ConfigRead()
{
	std::ifstream read("server.properties");
	Err(&read, _T("打开配置文件失败"));
	std::vector<std::string> configs;
	std::string config;
	while (getline(read, config)) 
	{
		configs.push_back(config);
	}
	read.close();
	return configs;
}

static void ConfigWrite(std::vector<std::string> &configText)
{
	std::ofstream write("server.properties", std::ios::out);
	Err(&write, _T("写入配置文件失败"));
	for (const auto& in : configText)
	{
		write << in << "\n";
	}
	write.close();
}


//normal
static void ConfigSet_EDIT(std::vector<std::string> &configText, HWND hWnd1, std::string target, int id)
{
	char newText[1024] = { 0 };
	GetWindowTextA(GetDlgItem(hWnd1, id), newText, 1024);
	if (newText != "不修改")
	{
		for (auto& l : configText)
		{
			if (l.find(target) != std::string::npos)
			{
				l = target + '=' + newText;
			}
			return;
		}
	}
}
static void ConfigSet_CHECK_1(std::vector<std::string>& configText, HWND hWnd1, std::string target, int id, int no_id)
{
	if (IsDlgButtonChecked(hWnd1, no_id) != BST_CHECKED)
	{
		for (auto& l : configText)
		{
			if (l.find(target) != std::string::npos)
			{
				if(IsDlgButtonChecked(hWnd1, id) == BST_CHECKED)
					l = target + "=true";
				else l = target + "=false";
				return;
			}
		}
	}
}
static void ConfigSet_CHECK_2(std::vector<std::string>& configText, HWND hWnd1, std::string target, int id, int no_id)
{
	if (IsDlgButtonChecked(hWnd1, no_id) != BST_CHECKED)
	{
		for (auto& l : configText)
		{
			if (l.find(target) != std::string::npos)
			{
				if (IsDlgButtonChecked(hWnd1, id) == BST_CHECKED)
					l = target + "=false";
				else l = target + "=true";
				return;
			}
		}
	}
}


//DIY
static void ConfigSet_CheckDIY_Mute(std::vector<std::string>& configText, HWND hWnd1, std::string target, int id, int no_id)
{
	if (IsDlgButtonChecked(hWnd1, no_id) != BST_CHECKED)
	{
		for (auto& l : configText)
		{
			if (l.find(target) != std::string::npos)
			{
				if (IsDlgButtonChecked(hWnd1, id) == BST_CHECKED)
					l = target + "=Disabled";
				else l = target + "=None";
				return;
			}
		}
	}
}
static void ConfigSet_CheckDIY_AntiCheat(std::vector<std::string>& configText, HWND hWnd1)
{
	if (IsDlgButtonChecked(hWnd1, CONF_AntiCheat_NOEDIT) != BST_CHECKED)
	{
		std::string targetA = "server-authoritative-movement-strict", 
			targetB = "server-authoritative-dismount-strict",
			targetC = "server-authoritative-entity-interactions-strict";
		for (auto& l : configText)
		{
			bool check = (IsDlgButtonChecked(hWnd1, CONF_AntiCheat) == BST_CHECKED);
			if (l.find(targetA) != std::string::npos)
			{
				if(check)
					l = targetA + "=true";
				else l = targetA + "=false";
			}
			if (l.find(targetB) != std::string::npos)
			{
				if (check)
					l = targetB + "=true";
				else l = targetB + "=false";
			}
			if (l.find(targetC) != std::string::npos)
			{
				if (check)
					l = targetC + "=true";
				else l = targetC + "=false";
			}
		}
	}
}

static void ConfigSet_ComboDIY_Gamemode(std::vector<std::string>& configText, HWND hWnd1)
{
	int selected = SendMessage(hGamemode, CB_GETCURSEL, 0, 0);
	std::string target = "gamemode";
	switch (selected)
	{
	case 1:
		for (auto& l : configText)
		{
			if (l.find(target) != std::string::npos)
			{
				l = target + "=adventure";
				return;
			}
		}
		break;
	case 2:
		for (auto& l : configText)
		{
			if (l.find(target) != std::string::npos)
			{
				l = target + "=survival";
				return;
			}
		}
		break;
	case 3:
		for (auto& l : configText)
		{
			if (l.find(target) != std::string::npos)
			{
				l = target + "=creative";
				return;
			}
		}
		break;
	}
}
static void ConfigSet_ComboDIY_Difficuty(std::vector<std::string>& configText, HWND hWnd1)
{
	int selected = SendMessage(hDifficulty, CB_GETCURSEL, 0, 0);
	std::string target = "difficulty";
	switch (selected)
	{
	case 1:
		for (auto& l : configText)
		{
			if (l.find(target) != std::string::npos)
			{
				l = target + "=peaceful";
				return;
			}
		}
		break;
	case 2:
		for (auto& l : configText)
		{
			if (l.find(target) != std::string::npos)
			{
				l = target + "=easy";
				return;
			}
		}
		break;
	case 3:
		for (auto& l : configText)
		{
			if (l.find(target) != std::string::npos)
			{
				l = target + "=normal";
				return;
			}
		}
		break;
	case 4:
		for (auto& l : configText)
		{
			if (l.find(target) != std::string::npos)
			{
				l = target + "=hard";
				return;
			}
		}
		break;
	}
}
static void ConfigSet_ComboDIY_Level(std::vector<std::string>& configText, HWND hWnd1)
{
	int selected = SendMessage(hPermission, CB_GETCURSEL, 0, 0);
	std::string target = "default-player-permission-level";
	switch (selected)
	{
	case 1:
		for (auto& l : configText)
		{
			if (l.find(target) != std::string::npos)
			{
				l = target + "=visitor";
				return;
			}
		}
		break;
	case 2:
		for (auto& l : configText)
		{
			if (l.find(target) != std::string::npos)
			{
				l = target + "=member";
				return;
			}
		}
		break;
	case 3:
		for (auto& l : configText)
		{
			if (l.find(target) != std::string::npos)
			{
				l = target + "=operator";
				return;
			}
		}
		break;
	}
}

//whole
void Submit(HWND hWnd1)
{
	std::vector<std::string> configText = ConfigRead();

	//EDIT
	ConfigSet_EDIT(configText, hWnd1, 
		"server-name", CONF_ServerName);

	ConfigSet_EDIT(configText, hWnd1,
		"level-name", CONF_LevelName);
	ConfigSet_EDIT(configText, hWnd1,
		"level-seed", CONF_LevelSeed);
	ConfigSet_EDIT(configText, hWnd1,
		"max-players", CONF_MaxPlayer);
	
	//CHECK
	ConfigSet_CHECK_1(configText, hWnd1,
		"allow-cheats", CONF_Cheat, CONF_Cheat_NOEDIT);

	ConfigSet_CHECK_1(configText, hWnd1,
		"online-mode", CONF_OnlineMode, CONF_OnlineMode_NOEDIT);
	ConfigSet_CHECK_1(configText, hWnd1,
		"enable-lan-visibility", CONF_LanVisible, CONF_LanVisible_NOEDIT);
	ConfigSet_CHECK_1(configText, hWnd1,
		"allow-list", CONF_Whitelist, CONF_Whitelist_NOEDIT);

	ConfigSet_CHECK_1(configText, hWnd1,
		"texturepack-required", CONF_FroceTexture, CONF_FroceTexture_NOEDIT);
	ConfigSet_CHECK_1(configText, hWnd1,
		"disable-custom-skins", CONF_BanSkin, CONF_BanSkin_NOEDIT);

	//CheckDIY
	ConfigSet_CheckDIY_Mute(configText, hWnd1,
		"chat-restriction", CONF_Mute, CONF_Mute_NOEDIT);
	ConfigSet_CheckDIY_AntiCheat(configText, hWnd1);

	//ComboDIY
	ConfigSet_ComboDIY_Gamemode(configText, hWnd1);
	ConfigSet_ComboDIY_Difficuty(configText, hWnd1);
	ConfigSet_ComboDIY_Level(configText, hWnd1);

	//submit
	ConfigWrite(configText);
	MessageBox(hWnd,
		L"已尝试提交", TITLE,
		MB_OK);
}