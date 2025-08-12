#include "Win32.h"
#include "ID.h"
#include "Function.h"

//Send
bool SendCommand(const char* command)
{
	DWORD written;
	if (WriteFile(UIw_key, command, strlen(command), &written, NULL) != 0)
		return true;
	else return false;
}