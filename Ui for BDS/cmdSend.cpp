#include "Win32.h"
#include "ID.h"
#include "Function.h"

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
		Err(_T("Failed to send command!"));
		return false;
	}
}