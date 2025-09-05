#include "Win32.h"
#include "Config.h"
#include "Function.h"
#include "SharedValue.h"

#include <vector>


//basic
static std::vector<std::string> ConfigRead()
{
	std::ifstream read("server.properties");
	Err(&read, _T("�������ļ�ʧ��"));
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
	Err(&write, _T("д�������ļ�ʧ��"));
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
	if (newText != "���޸�")
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
				if(IsDlgButtonChecked(hWnd1, id) != BST_CHECKED)
					l = target + "=true";
				else l = target + "=false";
				return;
			}
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
				if (IsDlgButtonChecked(hWnd1, id) != BST_CHECKED)
					l = target + "=false";
				else l = target + "=true";
				return;
			}
		}
	}
}


//special



//whole
void Submit(HWND hWnd1)
{
	std::vector<std::string> configText = ConfigRead();
	ConfigSet_EDIT(configText, hWnd1, 
		"server-name",  CONF_ServerName);

	ConfigWrite(configText);
	MessageBox(hWnd,
		L"�ѳ����ύ", TITLE,
		MB_OK);
}