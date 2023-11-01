![build status](https://git.beagleboard.org/beagleboard/gnuprumcu/badges/master/pipeline.svg)

# Device specs and I/O headers for PRU MCU variants

## Introduction
This package contains the device specs and I/O headers for the different PRU variants in different TI SoCs.

Install this package to allow the "-mmcu=" GCC compiler option to pick the correct settings for your board. For example, to build firmware for PRU0 from the ICSSG1 instance on Beagleboard-AI64, run GCC with the following option:

	pru-gcc -mmcu=tda4vm.icssg1.pru0 -Os -Wall main.c -o firmware.elf

For a full list of supported specs see [here](./MCU-LIST.md).

## Building from GIT
The autoconf and automake tools are needed to bootstrap the build scripts.

	autoreconf -vfi
	./configure --prefix=/usr/local --host=pru
	make
	make install

## Building from a released tarball
Use the standard configure and make steps.

	./configure --prefix=/usr/local --host=pru
	make
	make install

## Creating Debian Package

	debuild -i -us -uc -b
	ls -l ../gnuprumcu_*.deb
