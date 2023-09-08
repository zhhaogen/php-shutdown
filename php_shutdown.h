/* shutdown extension for PHP */

#ifndef PHP_SHUTDOWN_H
# define PHP_SHUTDOWN_H

extern zend_module_entry shutdown_module_entry;
# define phpext_shutdown_ptr &shutdown_module_entry

# define PHP_SHUTDOWN_VERSION "1.0.0"

# if defined(ZTS) && defined(COMPILE_DL_SHUTDOWN)
ZEND_TSRMLS_CACHE_EXTERN()
# endif

#endif	/* PHP_SHUTDOWN_H */
