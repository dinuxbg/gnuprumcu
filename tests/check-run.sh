#!/bin/sh

# Run the gnuprumcu internal tests

set -e

# TODO - get the PRU simulator executable from Autoconf.
pru-run ./check_am335x_offsets
pru-run ./check_am335x_offsets2
pru-run ./check_am572x_offsets
pru-run ./check_am62x_offsets
pru-run ./check_am62x_offsets2
pru-run ./check_tda4vm_offsets
pru-run ./check_tda4vm_offsets2
