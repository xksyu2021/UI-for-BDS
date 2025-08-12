#include "Win32.h"
#include "ID.h"
#include "Function.h"

//Send
bool SendCommand(LPWSTR command)
{
	if (WriteFile(UIw_key, command, sizeof(command), NULL, NULL) != 0)
		return true;
	else {
		Err(TITLE, _T("Failed to send command!"));
		return false;
	}
}