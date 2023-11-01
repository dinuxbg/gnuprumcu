![build status](https://git.beagleboard.org/beagleboard/gnuprumcu/badges/master/pipeline.svg)

# Device specs and I/O headers for PRU MCU variants

## Introduction
This package contains the device [specs](https://gcc.gnu.org/onlinedocs/gcc/Spec-Files.html) and I/O headers for the different PRU variants in different TI SoCs.

Install this package to allow the `-mmcu=` GCC compiler option to pick the correct settings for your board.

## Usage
Let's say that we're building firmware for PRU0 core from the ICSSG1 instance on [Beagleboard-AI64](https://www.beagleboard.org/boards/beaglebone-ai-64). In such case you must pass the `tda4vm.icssg1.pru0` spec to the GCC's `-mmcu=` command line option, e.g.:

	pru-gcc -mmcu=tda4vm.icssg1.pru0 -Os -Wall main.c -o firmware.elf

The above spec would in turn provide the correct IMEM and DMEM memory sizes to the linker. It would also add preprocessor defines to allow distinguishing PRU cores in C and ASM programs. Example:

	#if defined(__TDA4VM_ICSSG1_PRU0__)
		/* This C code section will be compiled only
		 * for PRU0 from ICSSG1 on Beaglebone-AI64. */
	#endif

	#if defined(__TDA4VM_ICSSG1__)
		/* This C code section will be compiled for any
		 * PRU core from ICSSG1 on Beaglebone-AI64. */
	#endif

	#if defined(__TDA4VM__)
		/* This C code section will be compiled for any
		 * PRU core from any ICSSG on Beaglebone-AI64. */
	#endif

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
