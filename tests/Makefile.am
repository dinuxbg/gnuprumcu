# SPDX-License-Identifier: BSD-2-Clause-FreeBSD
#
# Copyright 2023 Dimitar Dimitrov <dimitar@dinux.eu>
# All rights reserved.

TESTS = check.sh
EXTRA_DIST = check.sh test-common.h

check_PROGRAMS = \
	check_am335x_offsets \
	check_am335x_offsets2 \
	check_am62x_offsets \
	check_am62x_offsets2 \
	check_am572x_offsets \
	check_tda4vm_offsets \
	check_tda4vm_offsets2

check_am335x_offsets_SOURCES = check_am335x_offsets.c
check_am335x_offsets_CFLAGS = -mmcu=am335x.pru0
check_am335x_offsets2_SOURCES = check_am335x_offsets2.c
check_am335x_offsets2_CFLAGS = -mmcu=am335x.pru1

check_am62x_offsets_SOURCES = check_am62x_offsets.c
check_am62x_offsets_CFLAGS = -mmcu=am62x.pru0
check_am62x_offsets2_SOURCES = check_am62x_offsets2.c
check_am62x_offsets2_CFLAGS = -mmcu=am62x.pru1

check_am572x_offsets_SOURCES = check_am572x_offsets.c
check_am572x_offsets_CFLAGS = -mmcu=am572x.icss1.pru0

check_tda4vm_offsets_SOURCES = check_tda4vm_offsets.c
check_tda4vm_offsets_CFLAGS = -mmcu=tda4vm.icssg1.pru0
check_tda4vm_offsets2_SOURCES = check_tda4vm_offsets2.c
check_tda4vm_offsets2_CFLAGS = -mmcu=tda4vm.icssg1.pru1
