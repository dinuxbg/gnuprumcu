/* SPDX-License-Identifier: BSD-2-Clause-FreeBSD
 *
 * pru/io.h -- PRU I/O registers definitions
 *
 * Copyright (c) 2015-2019 Dimitar Dimitrov <dimitar@dinux.eu>
 * All rights reserved.
 */

#ifndef __PRU_IO_H__
#define __PRU_IO_H__

#if __GNUC__ < 11
/* __halt builtin was introduced with GCC 11. */
static inline void __halt(void)
{
	asm volatile ("halt" : : : "memory");
}
#endif	/* __GNUC__ < 11 */


#if __GNUC__ < 12 || defined (__cplusplus)

/* Prior to GCC 12 there was no __regio_symbol address space. */
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
 *
 * Even though GCC 12 introduced __regio_symbol for its C frontend,
 * named address spaces are still not available for the C++ frontend.
 * Hence we must still rely on write_r3x/read_r3x accessors.
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

#else	/* __GNUC__ >= 12 && !defined (__cplusplus) */

/*
 * GCC 12 C frontend introduced "fake" address spaces to access the
 * R30 and R31 I/O CPU registers.
 *
 * If used correctly, the compiler should never create DRAM references
 * to these fake variables. Correct usage will result in "mov R30, rX"
 * and "mov rX, R30" statements.
 *
 * Do not use "asm volatile" register variables!
 * See https://gcc.gnu.org/ml/gcc-patches/2015-01/msg02241.html
 */
extern volatile __regio_symbol unsigned int __R30;
extern volatile __regio_symbol unsigned int __R31;

/* For backwards compatibility with existing user source code. */
static inline void write_r30(unsigned int val) { __R30 = val; }
static inline void write_r31(unsigned int val) { __R31 = val; }
static inline unsigned int read_r30(void) { return __R30; }
static inline unsigned int read_r31(void) { return __R31; }

#endif	/* __GNUC__ < 12 || defined (__cplusplus) */

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
#elif defined(__AM572X_ICSS0_PRU0__) || defined(__AM572X_ICSS1_PRU0__) || defined(__AM572X_ICSS0_PRU1__) || defined(__AM572X_ICSS1_PRU1__)
#  include <pru/am572x.h>
#else
#  pragma message "No matching PRU instance variant found for <pru/io.h>"
#endif

#endif
