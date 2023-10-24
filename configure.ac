dnl Process this file with autoconf to produce a configure script.

dnl SPDX-License-Identifier: BSD-2-Clause-FreeBSD
dnl
dnl Copyright 2018-2023 Dimitar Dimitrov <dimitar@dinux.eu>
dnl All rights reserved.

AC_INIT([gnuprumcu],[0.9.4])

dnl Not sure why this has to be so early.
AC_CANONICAL_TARGET

AM_INIT_AUTOMAKE(foreign)
AM_SILENT_RULES([yes])

dnl create a config.h file (Automake will add -DHAVE_CONFIG_H)
AC_CONFIG_HEADERS([config.h])

AC_SUBST(VERSION)

ISODATE=`date +%Y-%m-%d`
AC_SUBST(ISODATE)

AC_CANONICAL_HOST

dnl Checks for programs.
AC_PROG_INSTALL
AC_PROG_CC

dnl Checks for libraries.

dnl Checks for additional header files.
AC_CHECK_HEADERS(stdint.h)

dnl Checks for typedefs, structures, and compiler characteristics.

AC_ARG_ENABLE([toolchain-check],
	      [AS_HELP_STRING([--disable-toolchain-check],
			      [disable pru toolchain verification])],
	      [],
	      [enable_toolchain_check=yes])

dnl ==========================================================================
AS_IF([test "x$enable_toolchain_check" != xno],
      [

dnl Not sure why configure picks system compiler, even when --host=pru
case "x`${CC} -dumpmachine`x" in
  xpru-elfx) ;;
  xprux) ;;
  *) AC_MSG_ERROR([C compiler is not targeting PRU. Please check your PATH.]) ;;
esac

dnl Check if compiler is working
AC_LINK_IFELSE([AC_LANG_PROGRAM([],[])],
    [AC_MSG_NOTICE([CC works.])], [AC_MSG_ERROR([CC cannot cross-compile a program.])])

dnl Check if we're running with recent-enough binutils.
AC_LINK_IFELSE([AC_LANG_PROGRAM([
#include <stdio.h>
    extern int __IMEM_SIZE;], [
    return (int)&__IMEM_SIZE > 0x100;
    ])],  [ld_suppports_dynamic_sizes="yes"], [ld_suppports_dynamic_sizes="no"])

     ],
     [ld_suppports_dynamic_sizes="yes"])

dnl Disable testsuite if a crosstoolchain cannot be verified.
AM_CONDITIONAL([ENABLE_TESTSUITE], [test $enable_toolchain_check = yes])

dnl ==========================================================================

dnl Checks for library functions.

dnl Sanity checks
case "$host" in
  pru-*-elf)
    AC_MSG_NOTICE([Building for pru host. Good.])
    ;;
  *)
    AC_MSG_ERROR([Please specify "--host=pru" option to configure.])
    ;;
esac

case "$ld_suppports_dynamic_sizes" in
  yes)
    AC_MSG_NOTICE([Binutils is recent enough.])
    ;;
  *)
    AC_MSG_ERROR([Please upgrade Binutils to at least version 2.37.])
    ;;
esac


AC_CONFIG_FILES([Makefile include/Makefile device-specs/Makefile tests/Makefile])
AC_OUTPUT
