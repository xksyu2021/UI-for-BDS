#include "Win32.h"
#include "Function.h"
#include "SharedValue.h"

//Send
bool SendCommand(LPCSTR command)
{
	DWORD size = strlen(command);
	if (WriteFile(UIw_key, command, size, NULL, NULL) != 0)
	{
		FlushFileBuffers(UIw_key);
		return true;
	}
	else
	{
		Err(_T("��������ʧ��\n��������Ϊ�������ѱ��ر�"));
		return false;
	}
}

bool SendCommand_NoErr(LPCSTR command)
{
	DWORD size = strlen(command);
	if (WriteFile(UIw_key, command, size, NULL, NULL) != 0)
	{
		FlushFileBuffers(UIw_key);
		return true;
	}
	else
	{
		return false;
	}
}

bool SendCommand_WithID(const std::string& front, const std::string& id, const std::string& behind)
{
	std::string temp = front + " " + id + " " + behind + "\n";
	return SendCommand(temp.c_str());
}