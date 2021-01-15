dnl Process this file with autoconf to produce a configure script.

dnl SPDX-License-Identifier: BSD-2-Clause-FreeBSD
dnl
dnl Copyright 2018-2019 Dimitar Dimitrov <dimitar@dinux.eu>
dnl All rights reserved.

AC_INIT(gnuprumcu, 0.5.0)

dnl Not sure why this has to be so early.
AC_CANONICAL_TARGET

AM_INIT_AUTOMAKE(foreign)

dnl create a config.h file (Automake will add -DHAVE_CONFIG_H)
AM_CONFIG_HEADER(config.h)

AC_SUBST(VERSION)

ISODATE=`date +%Y-%m-%d`
AC_SUBST(ISODATE)

AC_CANONICAL_HOST

dnl Checks for programs.
AC_PROG_INSTALL
AC_PROG_CC

dnl Checks for libraries.

dnl Checks for header files.
AC_HEADER_STDC
AC_CHECK_HEADERS(unistd.h sys/param.h sys/time.h time.h sys/sysmacros.h string.h memory.h fcntl.h )


AC_HEADER_MAJOR
AC_FUNC_ALLOCA

dnl Checks for typedefs, structures, and compiler characteristics.

dnl Checks for library functions.

dnl Sanity checks
case "$target" in
  pru-*-elf)
    AC_MSG_NOTICE([Building for pru target. Good.])
    ;;
  *)
    AC_MSG_ERROR([Please specify "--target=pru" option to configure.])
    ;;
esac


AC_OUTPUT(Makefile include/Makefile ldscripts/Makefile device-specs/Makefile)
