# SPDX-License-Identifier: BSD-2-Clause-FreeBSD
#
# Copyright 2018-2021 Dimitar Dimitrov <dimitar@dinux.eu>
# All rights reserved.

SUBDIRS = include device-specs tests

EXTRA_DIST = debian README.md MCU-LIST.md

# Needed for "make distcheck"
DISTCHECK_CONFIGURE_FLAGS ?= --host=pru
