# License here
#

AC_PREREQ(2.61)
AC_INIT(mta, 1.0-trunk, nospam@mtanet)
AM_CONFIG_HEADER(config.h)
AC_CONFIG_MACRO_DIR([m4])

if test x$prefix = xNONE; then
        prefix=/usr/local
fi

AC_SUBST(prefix)

AC_SUBST(INCLUDES)

# Checks for programs.
AC_PROG_CXX
AC_PROG_CC
AC_PROG_CPP
AC_PROG_INSTALL
AC_PROG_LN_S
AC_PROG_MAKE_SET
AC_PROG_LIBTOOL

AM_INIT_AUTOMAKE
AM_PROG_CC_C_O
AC_PROG_MAKE_SET

# Templates
AH_TEMPLATE([USING_BIG_ENDIAN], Define this if you are on a big-endian system.)
AH_TEMPLATE([USING_LITTLE_ENDIAN], Define this if you are on a non-big-endian system.)
AH_TEMPLATE([X64], Define this if you are under an X64-based operating system.)
AH_TEMPLATE([X86], Define this if you are under an X86-based 32bit operating system.)
AH_TEMPLATE([MTA_REVISION], The revision of the latest checkout)


# Checks for libraries.

# pcre
AX_PATH_LIB_PCRE()
AC_SUBST(PCRE_CFLAGS)
AC_SUBST(PCRE_LIBS)

# Checking for a 64bit system
AC_MSG_CHECKING([uname -m for detecting host operating system architecture])
ARCH=`uname -m`
case "$ARCH" in
	amd64*)
		dnl yay 21st century hardware
		AC_MSG_RESULT(x64 feel teh power)
		AC_DEFINE(X64)
		AC_SUBST(ARCH,x64)
	;;
	x86_64*)
		dnl yay 21st century hardware
		AC_MSG_RESULT(x64 feel teh power)
    AC_DEFINE(X64)
		AC_SUBST(ARCH,x64)
	;;
	*)
		AC_MSG_RESULT(x86 oh noes i ran out of address space)
		AC_DEFINE(X86)
		AC_SUBST(ARCH,x86)
	;;
esac

# Check for BigEndian
AC_C_BIGENDIAN([AC_DEFINE(USING_BIG_ENDIAN)],[AC_DEFINE(USING_LITTLE_ENDIAN)],[])

# Check for zlib
AC_CHECK_LIB(z, deflate,, AC_MSG_ERROR([can't find zlib]))

# Define compile/library flags.
AC_SUBST(AM_CXXFLAGS, "$AM_CXXFLAGS $INCLUDES -DLINUX $PCRE_CFLAGS -Wall -Wno-deprecated -DTIXML_USE_STL")
AC_SUBST(AM_LDFLAGS, "$AM_LDFLAGS")

# Checks for header files.
AC_CHECK_HEADERS(fcntl.h limits.h strings.h syslog.h unistd.h [sys/param.h] stdarg.h)

# Check for libraries
AC_CHECK_FUNCS(strndup strerror vsnprintf vasprintf open vsyslog strncasecmp)

# Checks for typedefs, structures, and compiler characteristics.
AC_HEADER_STDBOOL
AC_C_CONST
AC_C_INLINE

# Checks for library functions.

# Extract the latest SVN revision
AC_CHECK_PROG([SVNVERSION], [svnversion], yes)
if test -z "$SVNVERSION"; then
	AC_MSG_ERROR(Subversion 'svnversion' not found)
else
	MTA_REVISION=`/usr/bin/env svnversion -n`
	if test -z "$MTA_REVISION"; then MTA_REVISION="n/a"; fi

	AC_MSG_NOTICE(Extracted SVN version: $MTA_REVISION)
	AC_DEFINE_UNQUOTED(MTA_REVISION,["\$Rev: $MTA_REVISION \$"])
	AC_SUBST(MTA_REVISION)
fi

AC_CONFIG_FILES([
	Makefile
	vendor/Makefile
	vendor/tinyxml/Makefile
	vendor/pme/Makefile
	vendor/ehs/Makefile
	vendor/json-c/Makefile
	Shared/Makefile
	Shared/XML/Makefile
	MTA10_Server/Makefile
	MTA10_Server/sdk/Makefile
	MTA10_Server/core/Makefile
	MTA10_Server/mods/Makefile
	MTA10_Server/mods/deathmatch/Makefile
])

AC_OUTPUT
