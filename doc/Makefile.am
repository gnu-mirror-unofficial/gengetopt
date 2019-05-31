# Copyright (C) 1999-2009  Free Software Foundation, Inc.
#  
# This file is part of GNU gengetopt 
#
# GNU gengetopt is free software; you can redistribute it and/or modify 
# it under the terms of the GNU General Public License as published by 
# the Free Software Foundation; either version 3, or (at your option) 
# any later version. 
#
# GNU gengetopt is distributed in the hope that it will be useful, but 
# WITHOUT ANY WARRANTY; without even the implied warranty of 
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General
# Public License for more details. 
#
# You should have received a copy of the GNU General Public License along 
# with gengetopt; see the file COPYING. If not, write to the Free Software 
# Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA. 

PROGNAME = $(top_builddir)/src/gengetopt$(EXEEXT)
MAKE_SAMPLES = $(MAKE) $(AM_MAKEFLAGS) $(EXTRA_PROGRAMS)
SAMPLES_STAMP = samples.stamp
GGO_FILES = $(srcdir)/sample1.ggo $(srcdir)/sample2.ggo 

# man page
man_MANS = gengetopt.1

gengetopt.1: $(top_srcdir)/src/cmdline.ggo
	@if test x"$(HELP2MAN)" == x":"; then \
		echo >&2 "Error: help2man is required to create $@"; \
		exit 1; \
	fi
	$(HELP2MAN) --help-option="--detailed-help" -- $(PROGNAME) > $@


EXTRA_PROGRAMS = sample1 sample2
sample1_SOURCES = cmdline1.c main1.cc
sample2_SOURCES = cmdline2.c main2.c

# these are for gnulib
AM_CPPFLAGS = -I$(top_srcdir)/gl -I$(top_builddir)/gl

LDADD = $(top_builddir)/gl/libgnu.la

gengetoptdoc_DATA = gengetopt.html index.html 

gengetoptexamples_DATA = \
	README.example \
	cmdline1.c \
	cmdline1.h \
	cmdline2.c \
	cmdline2.h \
	main1.cc \
	main2.c \
	sample1.ggo \
	sample2.ggo

AM_MAKEINFOHTMLFLAGS=--no-split
# for including generated texinfo files

info_TEXINFOS = gengetopt.texi index.texi

GENERATEDINFOS = \
	cmdline1.h.texi \
	help_modes.output.texi \
	help_output.texi \
	main1.cc.texi \
	multiple_example.c.texi \
	sample1.ggo.texi \
	sample1.output.texi \
	sample1_2.output.texi \
	test_conf_parser.c.texi \
	test_conf_parser_ov2.c.texi \
	test_modes_cmd.ggo.texi \
	test_multiple_parsers.c.texi

gengetopt_TEXINFOS = $(GENERATEDINFOS)
BUILT_SOURCES = \
	$(GENERATEDINFOS) \
	cmdline1.c \
	cmdline1.h \
	cmdline2.c \
	cmdline2.h

SUFFIXES = .h.texi .cc.texi .c.texi .ggo.texi .ggo

.h.h.texi:
	cat $< | sed -f $(srcdir)/input.sed > $@

.cc.cc.texi:
	cat $< | sed -f $(srcdir)/input.sed > $@

test_conf_parser.c.texi: $(top_srcdir)/tests/test_conf_parser.c
	cat $< | sed -f $(srcdir)/input.sed > $@

test_conf_parser_ov2.c.texi: $(top_builddir)/tests/test_conf_parser_ov2.c
	cat $< | sed -f $(srcdir)/input.sed > $@

test_multiple_parsers.c.texi: $(top_srcdir)/tests/test_multiple_parsers.c
	cat $< | sed -f $(srcdir)/input.sed > $@

test_modes_cmd.ggo.texi: $(top_srcdir)/tests/test_modes_cmd.ggo
	cat $< | sed -f $(srcdir)/input.sed > $@

.c.c.texi:
	cat $< | sed -f $(srcdir)/input.sed > $@

.ggo.ggo.texi:
	cat $< | sed -f $(srcdir)/input.sed > $@

help_output.texi: $(top_srcdir)/src/cmdline.ggo
	$(PROGNAME) --show-help --set-package="gengetopt" \
		-i $(top_srcdir)/src/cmdline.ggo --set-version="" > $@

help_modes.output.texi: $(top_srcdir)/tests/test_modes_cmd.ggo
	$(PROGNAME) --show-help --long-help \
		-i $(top_srcdir)/tests/test_modes_cmd.ggo > $@

sample1.output.texi: sample1$(EXEEXT) sample1.ggo
	./sample1$(EXEEXT) --help | sed -f $(srcdir)/input.sed > $@

sample1_2.output.texi: sample1$(EXEEXT) sample1.ggo
	./sample1$(EXEEXT) --detailed-help | sed -f $(srcdir)/input.sed > $@

EXTRA_DIST = \
	$(GENERATEDINFOS) \
	$(gengetoptdoc_DATA) \
	$(man_MANS) \
	README.example \
	cmdline1.c \
	cmdline1.h \
	cmdline2.c \
	cmdline2.h \
	input.sed \
	multiple_example.c \
	sample1.ggo \
	sample2.ggo \
	samples.stamp \
	testdata

cmdline1.h: cmdline1.c
cmdline1.c: sample1.ggo
	$(PROGNAME) -Fcmdline1 --long-help -u --show-required \
		-i $(srcdir)/sample1.ggo

cmdline2.h: cmdline2.c
cmdline2.c: sample2.ggo
	$(PROGNAME) --input=$(srcdir)/sample2.ggo \
		--func-name=my_cmdline_parser --file-name=cmdline2 \
		--unnamed-opts --no-handle-help --no-handle-version

cmdline2.o: cmdline2.c
	$(COMPILE) \
		-DMY_CMDLINE_PARSER_PACKAGE=\"sample2\" \
		-DMY_CMDLINE_PARSER_VERSION=\"2.0\" \
		-c cmdline2.c

# session for tests
RUN_SAMPLE1 = ./sample1$(EXEEXT) -i 10 --flag-opt cmdline?.c
RUN_SAMPLE1_1 = ./sample1$(EXEEXT) --help --int-opt -34
# the next one generates an error 'cause -i option is not given
RUN_SAMPLE1_2 = ./sample1$(EXEEXT) -F
RUN_SAMPLE2 = ./sample2$(EXEEXT) -i 10 -l 20
RUN_SAMPLE2_1 = ./sample2$(EXEEXT) --version
RUN_SAMPLE2_2 = ./sample2$(EXEEXT) --help

if NO_CROSSCOMPILING

check-am: testdata
	rm -f test.out
	touch $(GGO_FILES)
	$(MAKE) $(AM_MAKEFLAGS) sample1$(EXEEXT) sample2$(EXEEXT)
	$(RUN_SAMPLE1) >> test.out && \
	$(RUN_SAMPLE1_1) >> test.out && \
	$(RUN_SAMPLE2) >> test.out || \
	$(RUN_SAMPLE1_2) 2>> test.out
	$(RUN_SAMPLE2_1) >> test.out 
	$(RUN_SAMPLE2_2) >> test.out 
	@echo expect no output from diff
	diff --unified $(srcdir)/testdata test.out

testdata:
	rm -f testdata
	$(RUN_SAMPLE1) >> testdata
	$(RUN_SAMPLE1_1) >> testdata
	$(RUN_SAMPLE2) >> testdata || \
	$(RUN_SAMPLE1_2) 2>> testdata
	$(RUN_SAMPLE2_1) >> testdata
	$(RUN_SAMPLE2_2) >> testdata

endif

# this is to build samples once gengetopt has changed
# this is for development only.
samples: $(SAMPLES_STAMP)
	$(MAKE) $(AM_MAKEFLAGS) $(EXTRA_PROGRAMS)

$(SAMPLES_STAMP): $(PROGNAME)
	touch $(GGO_FILES)
	echo timestamp > $(SAMPLES_STAMP)

clean_gen:
	rm -f -- $(GENERATEDINFOS)

CLEANFILES = $(EXTRA_PROGRAMS)

DISTCLEANFILES = \
	$(BUILT_SOURCES) \
	cmdline1.c \
	cmdline1.h \
	cmdline2.c \
	cmdline2.h \
	samples.stamp \
	test.out

MAINTAINERCLEANFILES = \
	$(SAMPLES_STAMP) \
	cmdline1.c \
	cmdline1.h \
	cmdline2.c \
	cmdline2.h
