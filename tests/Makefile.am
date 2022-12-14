LOG_DRIVER = env AM_TAP_AWK='$(AWK)' $(SHELL) \
    ./my-test-driver

TESTS = check-00-test check-01-add 02-sub

check_PROGRAMS = \
	check-00-test \
	check-01-add \
    02-sub

check_00_test_SOURCES = 00-test.c
check_00_test_CFLAGS  = -I$(top_srcdir)/src
check_00_test_LDADD   = $(top_builddir)/src/libmylib.la
check_00_test_LDFLAGS = -L$(top_srcdir)/src

check_01_add_SOURCES = 01-add.c
check_01_add_CFLAGS = \
	-I$(top_srcdir)/src \
	@CHECK_CFLAGS@

check_01_add_LDADD = \
	$(top_builddir)/src/libmylib.la \
	@CHECK_LIBS@

check_01_add_LDFLAGS = -L$(top_srcdir)/src

02_sub_SOURCES = 02-sub.c
02_sub_CFLAGS  = -I$(top_srcdir)/src @CHECK_CFLAGS@
02_sub_LDADD   = $(top_builddir)/src/libmylib.la @CHECK_LIBS@

clean-local:
	rm -f *.trs

