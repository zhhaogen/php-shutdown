#pragma once
#include <stdio.h>
#include <stdbool.h>
/**
* 获取关机权限 
*/
bool adjustPrivilege();
/**
* 关机 
*/
bool poweroff();
/**
* 注销 
*/
bool logout();
/**
* 重启 
*/
bool reboot();
/**
*休眠
*/
bool hibernate();