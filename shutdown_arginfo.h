/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: aa46df71271aa93352fcf92dc62f5bb0f638c0b1 */

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_sys_shutdown, 0, 0, boolean, 0)
ZEND_END_ARG_INFO()

#define arginfo_sys_logout arginfo_sys_shutdown

#define arginfo_sys_reboot arginfo_sys_shutdown

#define arginfo_sys_hibernate arginfo_sys_shutdown


ZEND_FUNCTION(sys_shutdown);
ZEND_FUNCTION(sys_logout);
ZEND_FUNCTION(sys_reboot);
ZEND_FUNCTION(sys_hibernate);


static const zend_function_entry ext_functions[] = {
	ZEND_FE(sys_shutdown, arginfo_sys_shutdown)
	ZEND_FE(sys_logout, arginfo_sys_logout)
	ZEND_FE(sys_reboot, arginfo_sys_reboot)
	ZEND_FE(sys_hibernate, arginfo_sys_hibernate)
	ZEND_FE_END
};
