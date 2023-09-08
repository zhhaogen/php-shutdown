/* shutdown extension for PHP */

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include "php.h"
#include "ext/standard/info.h"
#include "php_shutdown.h"
#include "shutdown_arginfo.h"
#include "wshutdown.h"

/* For compatibility with older PHP versions */
#ifndef ZEND_PARSE_PARAMETERS_NONE
#define ZEND_PARSE_PARAMETERS_NONE() \
	ZEND_PARSE_PARAMETERS_START(0, 0) \
	ZEND_PARSE_PARAMETERS_END()
#endif

/* {{{ bool sys_shutdown() */
PHP_FUNCTION(sys_shutdown)
{
	ZEND_PARSE_PARAMETERS_NONE();

	if(poweroff()){
		RETURN_TRUE;
		return;
	}
	RETURN_FALSE;
}
/* }}} */

/* {{{ bool sys_logout() */
PHP_FUNCTION(sys_logout)
{
	ZEND_PARSE_PARAMETERS_NONE();

	if(logout()){
		RETURN_TRUE;
		return;
	}
	RETURN_FALSE;
}
/* }}} */

/* {{{ bool sys_reboot() */
PHP_FUNCTION(sys_reboot)
{
	ZEND_PARSE_PARAMETERS_NONE();

	if(reboot()){
		RETURN_TRUE;
		return;
	}
	RETURN_FALSE;
}
/* }}} */

/* {{{ bool sys_hibernate() */
PHP_FUNCTION(sys_hibernate)
{
	ZEND_PARSE_PARAMETERS_NONE();

	if(hibernate()){
		RETURN_TRUE;
		return;
	}
	RETURN_FALSE;
}
/* }}} */

/* {{{ PHP_RINIT_FUNCTION */
PHP_RINIT_FUNCTION(shutdown)
{
#if defined(ZTS) && defined(COMPILE_DL_SHUTDOWN)
	ZEND_TSRMLS_CACHE_UPDATE();
#endif

	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION */
PHP_MINFO_FUNCTION(shutdown)
{
	php_info_print_table_start();
	php_info_print_table_row(2,"version",PHP_SHUTDOWN_VERSION);
	php_info_print_table_end();
}
/* }}} */

/* {{{ shutdown_module_entry */
zend_module_entry shutdown_module_entry = {
	STANDARD_MODULE_HEADER,
	"shutdown",					/* Extension name */
	ext_functions,					/* zend_function_entry */
	NULL,							/* PHP_MINIT - Module initialization */
	NULL,							/* PHP_MSHUTDOWN - Module shutdown */
	PHP_RINIT(shutdown),			/* PHP_RINIT - Request initialization */
	NULL,							/* PHP_RSHUTDOWN - Request shutdown */
	PHP_MINFO(shutdown),			/* PHP_MINFO - Module info */
	PHP_SHUTDOWN_VERSION,		/* Version */
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_SHUTDOWN
# ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
# endif
ZEND_GET_MODULE(shutdown)
#endif
