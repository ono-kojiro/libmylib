#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([libmylib], [0.0.1], [ono.kojiro@gmail.com])
AC_CONFIG_MACRO_DIR([config])
AC_CONFIG_AUX_DIR([config])
AC_CONFIG_SRCDIR([src/mylib.c])
AC_CONFIG_HEADERS([config/config.h])

AC_REQUIRE_AUX_FILE([tap-driver.sh])

AC_CANONICAL_SYSTEM

AM_INIT_AUTOMAKE([foreign subdir-objects])

LT_INIT

# Checks for programs.
AC_PROG_CC

AC_PROG_AWK
AC_PROG_CPP
AC_PROG_CXX
AC_PROG_RANLIB

# Checks for libraries.
PKG_CHECK_MODULES([CHECK],
  [check],
  [
      #AC_MSG_NOTICE([found check])
	  found_check=1
  ],
  [
      #AC_MSG_NOTICE([NOT found check])
	  found_check=0
  ]
)

AC_ARG_ENABLE([check],
  [AC_HELP_STRING([--enable-check], [ use libcheck for unit test])],
  [
    case "${enableval}" in
	  yes)
        #AC_MSG_NOTICE([check is enabled])
	    enable_check=1
	    ;;
      no)
        #AC_MSG_NOTICE([check is disabled])
	    enable_check=0
	    ;;
    esac
  ],
  [
    enable_check=1
  ]
)

if test "$found_check" = "1" -a "$enable_check" = "1" ; then
  #AC_MSG_NOTICE([libcheck is enabled])
  AC_DEFINE([HAVE_LIBCHECK], [1], [Define if you want to use libcheck])
  use_check=1
else
  #AC_MSG_NOTICE([libcheck is disabled])
  use_check=0
fi

AM_CONDITIONAL([HAVE_LIBCHECK], [ test "$use_check" = "1" ])

# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.

AC_CONFIG_FILES([Makefile
                 src/Makefile
               ])

if test "$use_check" = "1" ; then
AC_CONFIG_FILES([tests/Makefile])
fi

AC_CONFIG_FILES([mkpackage.sh], [chmod +x mkpackage.sh])

AC_OUTPUT
