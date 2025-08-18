# SPDX-License-Identifier: BSD-2-Clause-FreeBSD
#
# Copyright 2023-2025 Dimitar Dimitrov <dimitar@dinux.eu>
# All rights reserved.

if ENABLE_TESTSUITE

TESTS = check-run.sh check-inspect.sh
EXTRA_DIST = check-run.sh check-inspect.sh test-common.h

check_PROGRAMS = \
	check_am18xx_options \
	check_am335x_options \
	check_am335x_offsets \
	check_am335x_offsets2 \
	check_am62x_offsets \
	check_am62x_offsets2 \
	check_am572x_offsets \
	check_tda4vm_offsets \
	check_tda4vm_offsets2

check_am18xx_options_SOURCES = check_am18xx_options.c
check_am18xx_options_CFLAGS = -B$(top_srcdir) -mmcu=am18xx.pru0 -minrt

check_am335x_options_SOURCES = check_am335x_options.c
check_am335x_options_CFLAGS = -B$(top_srcdir) -mmcu=am335x.pru0 -minrt

check_am335x_offsets_SOURCES = check_am335x_offsets.c
check_am335x_offsets_CFLAGS = -B$(top_srcdir) -mmcu=am335x.pru0
check_am335x_offsets2_SOURCES = check_am335x_offsets2.c
check_am335x_offsets2_CFLAGS = -B$(top_srcdir) -mmcu=am335x.pru1

check_am62x_offsets_SOURCES = check_am62x_offsets.c
check_am62x_offsets_CFLAGS = -B$(top_srcdir) -mmcu=am62x.pru0
check_am62x_offsets2_SOURCES = check_am62x_offsets2.c
check_am62x_offsets2_CFLAGS = -B$(top_srcdir) -mmcu=am62x.pru1

check_am572x_offsets_SOURCES = check_am572x_offsets.c
check_am572x_offsets_CFLAGS = -B$(top_srcdir) -mmcu=am572x.icss1.pru0

check_tda4vm_offsets_SOURCES = check_tda4vm_offsets.c
check_tda4vm_offsets_CFLAGS = -B$(top_srcdir) -mmcu=tda4vm.icssg1.pru0
check_tda4vm_offsets2_SOURCES = check_tda4vm_offsets2.c
check_tda4vm_offsets2_CFLAGS = -B$(top_srcdir) -mmcu=tda4vm.icssg1.pru1

endif
