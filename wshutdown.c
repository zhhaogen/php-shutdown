#include "wshutdown.h"
#include <windows.h>
#include <PowrProf.h>
#pragma comment(lib, "user32.lib")
#pragma comment(lib, "advapi32.lib")
#pragma comment(lib, "PowrProf.lib")
/**
* 关机 
*/
bool adjustPrivilege(){
	HANDLE hToken;
	TOKEN_PRIVILEGES tkp;
	// Get a token for this process.
	if (!OpenProcessToken(GetCurrentProcess(),TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &hToken))
	{
		return false;
	}
	// Get the LUID for the shutdown privilege.
	LookupPrivilegeValue(NULL, SE_SHUTDOWN_NAME, &tkp.Privileges[0].Luid); 
	tkp.PrivilegeCount = 1;  // one privilege to set
	tkp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
	// Get the shutdown privilege for this process.
	AdjustTokenPrivileges(hToken, FALSE, &tkp, 0,(PTOKEN_PRIVILEGES)NULL, 0); 
 
	if(GetLastError() != ERROR_SUCCESS){
		return false;
	}
	return true;
}
/**
* 关机 
*/
bool poweroff(){
	if(!adjustPrivilege()){
		return false;
	} 
	return ExitWindowsEx(EWX_POWEROFF | EWX_FORCE, SHTDN_REASON_MAJOR_OTHER);
}
/**
* 注销 
*/
bool logout(){
	if(!adjustPrivilege()){
		return false;
	}
	return ExitWindowsEx(EWX_LOGOFF | EWX_FORCE, SHTDN_REASON_MAJOR_OTHER);
}
/**
* 重启 
*/
bool reboot(){
	if(!adjustPrivilege()){
		return false;
	}
	return ExitWindowsEx(EWX_REBOOT | EWX_FORCE, SHTDN_REASON_MAJOR_OTHER);
}
/**
* 重启 
*/
bool hibernate(){
	if(!adjustPrivilege()){
		return false;
	}
	return SetSuspendState(true, true,true);
}