/* SPDX-License-Identifier: BSD-2-Clause-FreeBSD
 *
 * pru/io.h -- PRU I/O registers definitions
 *
 * Copyright (c) 2015-2019 Dimitar Dimitrov <dimitar@dinux.eu>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef __PRU_IO_H__
#define __PRU_IO_H__


static inline void write_r30(unsigned int val)
{
	asm volatile ("mov\tr30, %0" : : "r"(val));
}

static inline unsigned int read_r30(void)
{
	unsigned int val;
	asm volatile ("mov\t%0, r30" : "=r"(val) :);
	return val;
}

static inline void write_r31(unsigned int val)
{
	asm volatile ("mov\tr31, %0" : : "r"(val));
}

static inline unsigned int read_r31(void)
{
	unsigned int val;
	asm volatile ("mov\t%0, r31" : "=r"(val) :);
	return val;
}

#ifdef __cplusplus

/*
 * Elegant accessors for C++ users. Use __R30 and __R31 as normal
 * LHS and RHS variables to respectively read and write to R30/R31.
 */
class __R30_type {
public:
	void operator= (unsigned int rhs) const {
		write_r30(rhs);
	}
	operator unsigned int() const {
		return read_r30();
	}
};

class __R31_type {
public:
	void operator= (unsigned int rhs) const {
		write_r31(rhs);
	}
	operator unsigned int() const {
		return read_r31();
	}
};

__R30_type __R30 __attribute__((weak));
__R31_type __R31 __attribute__((weak));

#endif	/* __cplusplus */

static inline void __halt(void)
{
	asm volatile ("halt" : : : "memory");
}

#define PRU_R31_INTR_IN1_BIT		31
#define PRU_R31_INTR_IN1_MASK		(1u << 31)
#define PRU_R31_INTR_IN0_BIT		30
#define PRU_R31_INTR_IN0_MASK		(1u << 30)

#define PRU_R31_STATUS_BIT		0
#define PRU_R31_STATUS_MASK		(0x3fffffffu << 0)

#define PRU_R31_VEC_VALID_BIT		5
#define PRU_R31_VEC_VALID_MASK		(1u << 5)
#define PRU_R31_VEC_BIT			0
#define PRU_R31_VEC_MASK		(0xfu << 0)

#define PRU_R25_ACC_CARRY_BIT		1
#define PRU_R25_ACC_CARRY_MASK		(1u << 1)
#define PRU_R25_MAC_EN_BIT		0
#define PRU_R25_MAC_EN_MASK		(1u << 0)

/* XFR Device ID numbers */
#define XFR_ID_MAC			0
#define XFR_ID_BANK0			10
#define XFR_ID_BANK1			11
#define XFR_ID_BANK2			12
#define XFR_ID_PEER_CORE		14

#if defined(__AM335X_PRU0__) || defined(__AM335X_PRU1__)
#  include <pru/am335x.h>
#elif defined(__SIM__)
   /* perhaps warn? */
#else
#  warning "No matching PRU instance variant found for <pru/io.h>"
#endif

#endif
