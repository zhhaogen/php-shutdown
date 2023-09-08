dnl config.m4 for extension shutdown

dnl Comments in this file start with the string 'dnl'.
dnl Remove where necessary.

dnl If your extension references something external, use 'with':

dnl PHP_ARG_WITH([shutdown],
dnl   [for shutdown support],
dnl   [AS_HELP_STRING([--with-shutdown],
dnl     [Include shutdown support])])

dnl Otherwise use 'enable':

PHP_ARG_ENABLE([shutdown],
  [whether to enable shutdown support],
  [AS_HELP_STRING([--enable-shutdown],
    [Enable shutdown support])],
  [no])

if test "$PHP_SHUTDOWN" != "no"; then
  dnl Write more examples of tests here...

  dnl Remove this code block if the library does not support pkg-config.
  dnl PKG_CHECK_MODULES([LIBFOO], [foo])
  dnl PHP_EVAL_INCLINE($LIBFOO_CFLAGS)
  dnl PHP_EVAL_LIBLINE($LIBFOO_LIBS, SHUTDOWN_SHARED_LIBADD)

  dnl If you need to check for a particular library version using PKG_CHECK_MODULES,
  dnl you can use comparison operators. For example:
  dnl PKG_CHECK_MODULES([LIBFOO], [foo >= 1.2.3])
  dnl PKG_CHECK_MODULES([LIBFOO], [foo < 3.4])
  dnl PKG_CHECK_MODULES([LIBFOO], [foo = 1.2.3])

  dnl Remove this code block if the library supports pkg-config.
  dnl --with-shutdown -> check with-path
  dnl SEARCH_PATH="/usr/local /usr"     # you might want to change this
  dnl SEARCH_FOR="/include/shutdown.h"  # you most likely want to change this
  dnl if test -r $PHP_SHUTDOWN/$SEARCH_FOR; then # path given as parameter
  dnl   SHUTDOWN_DIR=$PHP_SHUTDOWN
  dnl else # search default path list
  dnl   AC_MSG_CHECKING([for shutdown files in default path])
  dnl   for i in $SEARCH_PATH ; do
  dnl     if test -r $i/$SEARCH_FOR; then
  dnl       SHUTDOWN_DIR=$i
  dnl       AC_MSG_RESULT(found in $i)
  dnl     fi
  dnl   done
  dnl fi
  dnl
  dnl if test -z "$SHUTDOWN_DIR"; then
  dnl   AC_MSG_RESULT([not found])
  dnl   AC_MSG_ERROR([Please reinstall the shutdown distribution])
  dnl fi

  dnl Remove this code block if the library supports pkg-config.
  dnl --with-shutdown -> add include path
  dnl PHP_ADD_INCLUDE($SHUTDOWN_DIR/include)

  dnl Remove this code block if the library supports pkg-config.
  dnl --with-shutdown -> check for lib and symbol presence
  dnl LIBNAME=SHUTDOWN # you may want to change this
  dnl LIBSYMBOL=SHUTDOWN # you most likely want to change this

  dnl If you need to check for a particular library function (e.g. a conditional
  dnl or version-dependent feature) and you are using pkg-config:
  dnl PHP_CHECK_LIBRARY($LIBNAME, $LIBSYMBOL,
  dnl [
  dnl   AC_DEFINE(HAVE_SHUTDOWN_FEATURE, 1, [ ])
  dnl ],[
  dnl   AC_MSG_ERROR([FEATURE not supported by your shutdown library.])
  dnl ], [
  dnl   $LIBFOO_LIBS
  dnl ])

  dnl If you need to check for a particular library function (e.g. a conditional
  dnl or version-dependent feature) and you are not using pkg-config:
  dnl PHP_CHECK_LIBRARY($LIBNAME, $LIBSYMBOL,
  dnl [
  dnl   PHP_ADD_LIBRARY_WITH_PATH($LIBNAME, $SHUTDOWN_DIR/$PHP_LIBDIR, SHUTDOWN_SHARED_LIBADD)
  dnl   AC_DEFINE(HAVE_SHUTDOWN_FEATURE, 1, [ ])
  dnl ],[
  dnl   AC_MSG_ERROR([FEATURE not supported by your shutdown library.])
  dnl ],[
  dnl   -L$SHUTDOWN_DIR/$PHP_LIBDIR -lm
  dnl ])
  dnl
  dnl PHP_SUBST(SHUTDOWN_SHARED_LIBADD)

  dnl In case of no dependencies
  AC_DEFINE(HAVE_SHUTDOWN, 1, [ Have shutdown support ])

  PHP_NEW_EXTENSION(shutdown, shutdown.c, $ext_shared)
fi
