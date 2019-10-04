![build status](https://gitlab.com/dinuxbg/gnuprumcu/badges/master/pipeline.svg)

# Linker scripts and device specs for PRU MCU variants

## Introduction
This package contains the linker scripts, device specs and I/O headers for the different PRU variants in different TI SoCs.

Install this package to allow the "-mmcu=" GCC compiler option to pick the correct settings for your board.

## Building from GIT
The autoconf and automake tools are needed to bootstrap the build scripts.

	autoreconf -vfi
	./configure --prefix=/usr/local --target=pru
	make
	make install

## Building from a released tarball
Use the standard configure and make steps.

	./configure --prefix=/usr/local --target=pru
	make
	make install

## Creating Debian Package

	debuild -i -us -uc -b
	ls -l ../gnupru_*.deb
