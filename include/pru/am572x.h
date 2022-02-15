/* SPDX-License-Identifier: BSD-2-Clause-FreeBSD
 *
 * pru/am572x.h -- PRU I/O registers definitions for PRU inside AM572x SoCs
 * Based on pru/am335x.h
 * 
 * Copyright (c) 2020 Vedant Paranjape
 * All rights reserved.
 */

#ifndef __PRU_AM572X_H__
#define __PRU_AM572X_H__


/* Local memory map (TRM section 30.1.4.4.1.2) */
#define __LOCAL_DATA_RAM_BASE		0x00000000
#define __PEER_DATA_RAM_BASE		0x00002000
#define __SHARED_DATA_RAM_BASE		0x00010000
#define __INTC_BASE			0x00020000
#define __PRU0_CTRL_REGS_BASE		0x00022000
#define __PRU1_CTRL_REGS_BASE		0x00024000
#define __CFG_BASE			0x00026000
#define __UART0_BASE			0x00028000
#define __IEP_BASE			0x0002E000
#define __ECAP0_BASE			0x00030000
#define __MII_RT_CFG_BASE		0x00032000
#define __MII_MDIO_BASE			0x00032400
#define __EXTERNAL_PRU_SS_BASE  0x00040000
#define __SYS_OCP_HP0_BASE		0x00080000

/* ====================== CTABLE base addresses ====================== */
#pragma ctable_entry 0 0x00020000
#pragma ctable_entry 1 0x48040000
#pragma ctable_entry 2 0x4802a000
#pragma ctable_entry 3 0x00030000
#pragma ctable_entry 4 0x00026000
#pragma ctable_entry 5 0x48060000
#pragma ctable_entry 6 0x48030000
#pragma ctable_entry 7 0x00028000
#pragma ctable_entry 8 0x46000000
#pragma ctable_entry 9 0x4a100000
#pragma ctable_entry 10 0x48318000
#pragma ctable_entry 11 0x48022000
#pragma ctable_entry 12 0x48024000
#pragma ctable_entry 13 0x48318000
#pragma ctable_entry 14 0x481cc000
#pragma ctable_entry 15 0x481d0000
#pragma ctable_entry 16 0x481a0000
#pragma ctable_entry 17 0x4819c000
#pragma ctable_entry 18 0x48300000
#pragma ctable_entry 19 0x48302000
#pragma ctable_entry 20 0x48304000
#pragma ctable_entry 21 0x00032400
#pragma ctable_entry 22 0x480c8000
#pragma ctable_entry 23 0x480ca000
/* 24-31 are user-defined base addresses. */

/* ====================== PRU CTRL module ====================== */
#define PRU_CTRL_CONTROL_OFFS		0x00
#define PRU_CTRL_STATUS_OFFS		0x04
#define PRU_CTRL_WAKEUP_EN_OFFS		0x08
#define PRU_CTRL_CYCLE_OFFS		0x0c
#define PRU_CTRL_STALL_OFFS		0x10
#define PRU_CTRL_CTBIR0_OFFS		0x20
#define PRU_CTRL_CTBIR1_OFFS		0x24
#define PRU_CTRL_CPPR0_OFFS		0x28
#define PRU_CTRL_CPPR1_OFFS		0x2c

struct __PRU_CONTROL_S {
	const volatile unsigned int SOFT_RST_N		: 1;
	volatile unsigned int ENABLE			: 1;
	volatile unsigned int SLEEPING			: 1;
	volatile unsigned int COUNTER_ENABLE		: 1;
	const volatile unsigned int __reserved_1	: 4;
	volatile unsigned int SINGLE_STEP		: 1;
	const volatile unsigned int __reserved_2	: 5;
	const volatile unsigned int PRU_BIG_ENDIAN	: 1;
	const volatile unsigned int RUNSTATE		: 1;
	volatile unsigned int PCOUNTER_RST_VAL		: 16;
};

struct __PRU_STATUS_S {
	const volatile unsigned int PCOUNTER		: 16;
	const volatile unsigned int __reserved_1	: 16;
};

struct __PRU_CTBIR0_S {
	volatile unsigned int C24_BLK_INDEX		 : 8;
	const volatile unsigned int __reserved_1 : 8;
	volatile unsigned int C25_BLK_INDEX		 : 8;
	const volatile unsigned int __reserved_2 : 8;
};

struct __PRU_CTBIR1_S {
	volatile unsigned int C26_BLK_INDEX		 : 8;
	const volatile unsigned int __reserved_1 : 8;
	volatile unsigned int C27_BLK_INDEX		 : 8;
	const volatile unsigned int __reserved_2 : 8;
};

struct __PRU_CTPPR0_S {
	volatile unsigned int C28_POINTER		: 16;
	volatile unsigned int C29_POINTER		: 16;
};

struct __PRU_CTPPR1_S {
	volatile unsigned int C30_POINTER		: 16;
	volatile unsigned int C31_POINTER		: 16;
};

struct __PRU_CTRL {
	union {
		volatile unsigned int CONTROL;
		struct __PRU_CONTROL_S CONTROL_bit;
	};
	union {
		volatile unsigned int STATUS;
		struct __PRU_STATUS_S STATUS_bit;
	};
	volatile unsigned int WAKEUP_EN;
	volatile unsigned int CYCLE;
	volatile unsigned int STALL;
	volatile unsigned int __gap1[3];
	union {
		volatile unsigned int CTBIR0;
		struct __PRU_CTBIR0_S CTBIR0_bit;
	};
	union {
		volatile unsigned int CTBIR1;
		struct __PRU_CTBIR1_S CTBIR1_bit;
	};
	union {
		volatile unsigned int CTPPR0;
		struct __PRU_CTPPR0_S CTPPR0_bit;
	};
	union {
		volatile unsigned int CTPPR1;
		struct __PRU_CTPPR1_S CTPPR1_bit;
	};
};

#define PRU0_CTRL	(*((struct __PRU_CTRL *)__PRU0_CTRL_REGS_BASE))
#define PRU1_CTRL	(*((struct __PRU_CTRL *)__PRU1_CTRL_REGS_BASE))

#if defined(__AM572X_ICSS0_PRU0__) || defined(__AM572X_ICSS1_PRU0__)
  #define PRU_CTRL	PRU0_CTRL
#elif defined(__AM572X_ICSS0_PRU1__) || defined(__AM572X_ICSS1_PRU1__)
  #define PRU_CTRL	PRU1_CTRL
#else
  #error "Unrecognized AM572X PRU core - check your -mmcu option"
#endif



/* ====================== PRU INTC module ====================== */
#define PRU_INTC_REVID_OFFS		0x00
#define PRU_INTC_CR_OFFS		0x04
#define PRU_INTC_GER_OFFS		0x10
#define PRU_INTC_GNLR_OFFS		0x1C
#define PRU_INTC_SISR_OFFS		0x20
#define PRU_INTC_SICR_OFFS		0x24
#define PRU_INTC_EISR_OFFS		0x28
#define PRU_INTC_EICR_OFFS		0x2c
#define PRU_INTC_HIEISR_OFFS		0x34
#define PRU_INTC_HIDISR_OFFS		0x38
#define PRU_INTC_GPIR_OFFS		0x80
#define PRU_INTC_SRSR0_OFFS		0x200
#define PRU_INTC_SRSR1_OFFS		0x204
#define PRU_INTC_SECR0_OFFS		0x280
#define PRU_INTC_SECR1_OFFS		0x284
#define PRU_INTC_ESR0_OFFS		0x300
#define PRU_INTC_ERS1_OFFS		0x304
#define PRU_INTC_ECR0_OFFS		0x380
#define PRU_INTC_ECR1_OFFS		0x384
#define PRU_INTC_CMR0_OFFS		0x400
#define PRU_INTC_CMR1_OFFS		0x404
#define PRU_INTC_CMR2_OFFS		0x408
#define PRU_INTC_CMR3_OFFS		0x40c
#define PRU_INTC_CMR4_OFFS		0x410
#define PRU_INTC_CMR5_OFFS		0x414
#define PRU_INTC_CMR6_OFFS		0x418
#define PRU_INTC_CMR7_OFFS		0x41c
#define PRU_INTC_CMR8_OFFS		0x420
#define PRU_INTC_CMR9_OFFS		0x424
#define PRU_INTC_CMR10_OFFS		0x428
#define PRU_INTC_CMR11_OFFS		0x42c
#define PRU_INTC_CMR12_OFFS		0x430
#define PRU_INTC_CMR13_OFFS		0x434
#define PRU_INTC_CMR14_OFFS		0x438
#define PRU_INTC_CMR15_OFFS		0x43c
#define PRU_INTC_HMR0_OFFS		0x800
#define PRU_INTC_HMR1_OFFS		0x804
#define PRU_INTC_HMR2_OFFS		0x808
#define PRU_INTC_HIPIR0_OFFS		0x900
#define PRU_INTC_HIPIR1_OFFS		0x904
#define PRU_INTC_HIPIR2_OFFS		0x908
#define PRU_INTC_HIPIR3_OFFS		0x90c
#define PRU_INTC_HIPIR4_OFFS		0x910
#define PRU_INTC_HIPIR5_OFFS		0x914
#define PRU_INTC_HIPIR6_OFFS		0x918
#define PRU_INTC_HIPIR7_OFFS		0x91c
#define PRU_INTC_HIPIR8_OFFS		0x920
#define PRU_INTC_HIPIR9_OFFS		0x924
#define PRU_INTC_SIPR0_OFFS		0xd00
#define PRU_INTC_SIPR1_OFFS		0xd04
#define PRU_INTC_SITR0_OFFS		0xd80
#define PRU_INTC_SITR1_OFFS		0xd84
#define PRU_INTC_HINLR0_OFFS		0x1100
#define PRU_INTC_HINLR1_OFFS		0x1104
#define PRU_INTC_HINLR2_OFFS		0x1108
#define PRU_INTC_HINLR3_OFFS		0x110c
#define PRU_INTC_HINLR4_OFFS		0x1110
#define PRU_INTC_HINLR5_OFFS		0x1114
#define PRU_INTC_HINLR6_OFFS		0x1118
#define PRU_INTC_HINLR7_OFFS		0x111c
#define PRU_INTC_HINLR8_OFFS		0x1120
#define PRU_INTC_HINLR9_OFFS		0x1124
#define PRU_INTC_HIER_OFFS		0x1500


struct __PRU_INTC_REVID_S {
	const volatile unsigned int REVISION : 32;
};


struct __PRU_INTC_CR_S {
	const volatile unsigned int __reserved_1  : 1;
	volatile unsigned int WAKEUP_MODE		  : 1;
	volatile unsigned int NEST_MODE			  : 2;
	volatile unsigned int PRIORITY_HOLD_MODE  : 1;
	const volatile unsigned int __reserved_2  : 27;
};


struct __PRU_INTC_GER_S {
	volatile unsigned int ENABLE_HINT_ANY		: 1;
	const volatile unsigned int __reserved_2	: 31;
};


struct __PRU_INTC_GNLR_S {
	volatile unsigned int GLB_NEST_LEVEL		: 9;
	const volatile unsigned int __reserved_1	: 22;
	volatile unsigned int AUTO_OVERRIDE			: 1;
};


struct __PRU_INTC_SISR_S {
	volatile unsigned int STATUS_SET_INDEX		: 10;
	const volatile unsigned int __reserved_1	: 22;
};


struct __PRU_INTC_SICR_S {
	volatile unsigned int STATUS_CLR_INDEX		: 10;
	const volatile unsigned int __reserved_1	: 22;
};


struct __PRU_INTC_EISR_S {
	volatile unsigned int ENABLE_SET_INDEX		: 10;
	const volatile unsigned int __reserved_1	: 22;
};


struct __PRU_INTC_EICR_S {
	volatile unsigned int ENABLE_CLR_INDEX		: 10;
	const volatile unsigned int __reserved_1	: 22;
};


struct __PRU_INTC_HIEISR_S {
	volatile unsigned int HINT_ENABLE_SET_INDEX	: 10;
	const volatile unsigned int __reserved_1	: 22;
};


struct __PRU_INTC_HIDISR_S {
	volatile unsigned int HINT_ENABLE_CLR_INDEX	: 10;
	const volatile unsigned int __reserved_1	: 22;
};

struct __PRU_INTC_GPIR_S {
	const volatile unsigned int GLB_PRI_INTR	: 10;
	const volatile unsigned int __reserved_1	: 21;
	const volatile unsigned int GLB_NONE		: 1;
};



struct __PRU_INTC_CMR_S {
	volatile unsigned int CH_MAP			 : 4;
	const volatile unsigned int __reserved_1 : 4;
} __attribute__((packed));


struct __PRU_INTC_HMR_S {
	volatile unsigned int HINT_MAP			 : 4;
	const volatile unsigned int __reserved_1 : 4;
} __attribute__((packed));


struct __PRU_INTC_HIPIR_S {
	const volatile unsigned int PRI_HINT		: 10;
	const volatile unsigned int __reserved_1	: 21;
	const volatile unsigned int NONE_HINT		: 1;
};


struct __PRU_INTC_HINLR_S {
	volatile unsigned int AUTO_OVERRIDE		 : 10;
	const volatile unsigned int __reserved_1 : 21;
	volatile unsigned int NEST_HINT			 : 1;
};

struct __PRU_INTC_HIER_S {
	volatile unsigned int ENABLE_HINT		 : 10;
	const volatile unsigned int __reserved_1 : 22;
};

struct __PRU_INTC {
	union {
		const volatile unsigned int REVID;
		struct __PRU_INTC_REVID_S REVID_bit;
	};
	union {
		volatile unsigned int CR;
		struct __PRU_INTC_CR_S CR_bit;
	};
	unsigned int __gap1[2];
	union {
		volatile unsigned int GER;
		struct __PRU_INTC_GER_S GER_bit;
	};
	unsigned int __gap2[2];
	union {
		volatile unsigned int GNLR;
		struct __PRU_INTC_GNLR_S GNLR_bit;
	};
	union {
		volatile unsigned int SISR;
		struct __PRU_INTC_SISR_S SISR_bit;
	};
	union {
		volatile unsigned int SICR;
		struct __PRU_INTC_SICR_S SICR_bit;
	};
	union {
		volatile unsigned int EISR;
		struct __PRU_INTC_EISR_S EISR_bit;
	};
	union {
		volatile unsigned int EICR;
		struct __PRU_INTC_EICR_S EICR_bit;
	};
	unsigned int __gap3[1];
	union {
		volatile unsigned int HIEISR;
		struct __PRU_INTC_HIEISR_S HIEISR_bit;
	};
	union {
		volatile unsigned int HIDISR;
		struct __PRU_INTC_HIEISR_S HIDISR_bit;
	};
	unsigned int __gap4[17];
	union {
		volatile unsigned int GPIR;
		struct __PRU_INTC_GPIR_S GPIR_bit;
	};
	unsigned int __gap5[95];
	volatile unsigned int SRSR0;
	volatile unsigned int SRSR1;
	unsigned int __gap6[30];
	volatile unsigned int SECR0;
	volatile unsigned int SECR1;
	unsigned int __gap7[30];
	volatile unsigned int ESR0;
	volatile unsigned int ERS1;
	unsigned int __gap8[30];
	volatile unsigned int ECR0;
	volatile unsigned int ECR1;
	unsigned int __gap9[30];
	union {
		volatile unsigned int CMR0;
		struct __PRU_INTC_CMR_S CMR0_bit;
	};
	union {
		volatile unsigned int CMR1;
		struct __PRU_INTC_CMR_S CMR1_bit;
	};
	union {
		volatile unsigned int CMR2;
		struct __PRU_INTC_CMR_S CMR2_bit;
	};
	union {
		volatile unsigned int CMR3;
		struct __PRU_INTC_CMR_S CMR3_bit;
	};
	union {
		volatile unsigned int CMR4;
		struct __PRU_INTC_CMR_S CMR4_bit;
	};
	union {
		volatile unsigned int CMR5;
		struct __PRU_INTC_CMR_S CMR5_bit;
	};
	union {
		volatile unsigned int CMR6;
		struct __PRU_INTC_CMR_S CMR6_bit;
	};
	union {
		volatile unsigned int CMR7;
		struct __PRU_INTC_CMR_S CMR7_bit;
	};
	union {
		volatile unsigned int CMR8;
		struct __PRU_INTC_CMR_S CMR8_bit;
	};
	union {
		volatile unsigned int CMR9;
		struct __PRU_INTC_CMR_S CMR9_bit;
	};
	union {
		volatile unsigned int CMR10;
		struct __PRU_INTC_CMR_S CMR10_bit;
	};
	union {
		volatile unsigned int CMR11;
		struct __PRU_INTC_CMR_S CMR11_bit;
	};
	union {
		volatile unsigned int CMR12;
		struct __PRU_INTC_CMR_S CMR12_bit;
	};
	union {
		volatile unsigned int CMR13;
		struct __PRU_INTC_CMR_S CMR13_bit;
	};
	union {
		volatile unsigned int CMR14;
		struct __PRU_INTC_CMR_S CMR14_bit;
	};
	union {
		volatile unsigned int CMR15;
		struct __PRU_INTC_CMR_S CMR15_bit;
	};
	unsigned int __gap10[240];
	union {
		volatile unsigned int HMR0;
		struct __PRU_INTC_HMR_S HMR0_bit;
	};
	union {
		volatile unsigned int HMR1;
		struct __PRU_INTC_HMR_S HMR1_bit;
	};
	union {
		volatile unsigned int HMR2;
		struct __PRU_INTC_HMR_S HMR2_bit;
	};
	unsigned int __gap11[61];
	union {
		volatile unsigned int HIPIR0;
		struct __PRU_INTC_HIPIR_S HIPIR0_bit;
	};
	union {
		volatile unsigned int HIPIR1;
		struct __PRU_INTC_HIPIR_S HIPIR1_bit;
	};
	union {
		volatile unsigned int HIPIR2;
		struct __PRU_INTC_HIPIR_S HIPIR2_bit;
	};
	union {
		volatile unsigned int HIPIR3;
		struct __PRU_INTC_HIPIR_S HIPIR3_bit;
	};
	union {
		volatile unsigned int HIPIR4;
		struct __PRU_INTC_HIPIR_S HIPIR4_bit;
	};
	union {
		volatile unsigned int HIPIR5;
		struct __PRU_INTC_HIPIR_S HIPIR5_bit;
	};
	union {
		volatile unsigned int HIPIR6;
		struct __PRU_INTC_HIPIR_S HIPIR6_bit;
	};
	union {
		volatile unsigned int HIPIR7;
		struct __PRU_INTC_HIPIR_S HIPIR7_bit;
	};
	union {
		volatile unsigned int HIPIR8;
		struct __PRU_INTC_HIPIR_S HIPIR8_bit;
	};
	union {
		volatile unsigned int HIPIR9;
		struct __PRU_INTC_HIPIR_S HIPIR9_bit;
	};
	unsigned int __gap12[246];
	volatile unsigned int SIPR0;
	volatile unsigned int SIPR1;
	unsigned int __gap13[30];
	volatile unsigned int SITR0;
	volatile unsigned int SITR1;
	unsigned int __gap14[222];
	union {
		volatile unsigned int HINLR0;
		struct __PRU_INTC_HINLR_S HINLR0_bit;
	};
	union {
		volatile unsigned int HINLR1;
		struct __PRU_INTC_HINLR_S HINLR1_bit;
	};
	union {
		volatile unsigned int HINLR2;
		struct __PRU_INTC_HINLR_S HINLR2_bit;
	};
	union {
		volatile unsigned int HINLR3;
		struct __PRU_INTC_HINLR_S HINLR3_bit;
	};
	union {
		volatile unsigned int HINLR4;
		struct __PRU_INTC_HINLR_S HINLR4_bit;
	};
	union {
		volatile unsigned int HINLR5;
		struct __PRU_INTC_HINLR_S HINLR5_bit;
	};
	union {
		volatile unsigned int HINLR6;
		struct __PRU_INTC_HINLR_S HINLR6_bit;
	};
	union {
		volatile unsigned int HINLR7;
		struct __PRU_INTC_HINLR_S HINLR7_bit;
	};
	union {
		volatile unsigned int HINLR8;
		struct __PRU_INTC_HINLR_S HINLR8_bit;
	};
	union {
		volatile unsigned int HINLR9;
		struct __PRU_INTC_HINLR_S HINLR9_bit;
	};
	unsigned int __gap15[246];
	union {
		volatile unsigned int HIER;
		struct __PRU_INTC_HIER_S HIER_bit;
	};
};
#define PRU_INTC	(*((struct __PRU_INTC *)__INTC_BASE))

/* ====================== PRU UART module ====================== */
/* TODO */

/* ====================== PRU eCAP module ====================== */
/* TODO */

/* ====================== PRU CFG module ====================== */
#define PRU_CFG_REVID_OFFS		0x00
#define PRU_CFG_SYSCFG_OFFS		0x04
#define PRU_CFG_GPCFG0_OFFS		0x08
#define PRU_CFG_GPCFG1_OFFS		0x0c
#define PRU_CFG_CGR_OFFS		0x10
#define PRU_CFG_ISRP_OFFS		0x14
#define PRU_CFG_ISP_OFFS		0x18
#define PRU_CFG_IESP_OFFS		0x1c
#define PRU_CFG_IECP_OFFS		0x20
#define PRU_CFG_PMAO_OFFS		0x28
#define PRU_CFG_MII_RT_OFFS		0x2c
#define PRU_CFG_IEPCLK_OFFS		0x30
#define PRU_CFG_SPP_OFFS		0x34
#define PRU_CFG_PIN_MIX_OFFS		0x40

struct __PRU_CFG_SYSCFG_S {
	volatile unsigned int IDLE_MODE				: 2;
	volatile unsigned int STANDBY_MODE			: 2;
	volatile unsigned int STANDBY_INIT			: 1;
	const volatile unsigned int SUB_MWAIT		: 1;
	const volatile unsigned int __reserved_1	: 26;
};

struct __PRU_CFG_GPCFG_S {
	volatile unsigned int GPI_MODE			 : 2;
	volatile unsigned int GPI_CLK_MODE		 : 1;
	volatile unsigned int GPI_DIV0			 : 5;
	volatile unsigned int GPI_DIV1			 : 5;
	volatile unsigned int GPI_SB			 : 1;
	volatile unsigned int GPO_MODE			 : 1;
	volatile unsigned int GPO_DIV0			 : 5;
	volatile unsigned int GPO_DIV1			 : 5;
	volatile unsigned int GPO_SH_SEL		 : 1;
	const volatile unsigned int __reserved_1 : 6;
};

struct __PRU_CFG_CGR_S {
	volatile unsigned int PRU0_CLK_STOP_REQ			: 1;
	const volatile unsigned int PRU0_CLK_STOP_ACK	: 1;
	volatile unsigned int PRU0_CLK_EN				: 1;
	volatile unsigned int PRU1_CLK_STOP_REQ			: 1;
	const volatile unsigned int PRU1_CLK_STOP_ACK	: 1;
	volatile unsigned int PRU1_CLK_EN				: 1;
	volatile unsigned int INTC_CLK_STOP_REQ			: 1;
	const volatile unsigned int INTC_CLK_STOP_ACK	: 1;
	volatile unsigned int INTC_CLK_EN				: 1;
	volatile unsigned int UART_CLK_STOP_REQ			: 1;
	const volatile unsigned int UART_CLK_STOP_ACK	: 1;
	volatile unsigned int UART_CLK_EN				: 1;
	volatile unsigned int ECAP_CLK_STOP_REQ			: 1;
	const volatile unsigned int ECAP_CLK_STOP_ACK	: 1;
	volatile unsigned int ECAP_CLK_EN				: 1;
	volatile unsigned int IEP_CLK_STOP_REQ			: 1;
	const volatile unsigned int IEP_CLK_STOP_ACK	: 1;
	volatile unsigned int IEP_CLK_EN				: 1;
	const volatile unsigned int __reserved_1		: 14;
};

struct __PRU_CFG_ISPx_S {
	volatile unsigned int PRU0_IMEM_PE		 : 4;
	volatile unsigned int PRU0_DMEM_PE		 : 4;
	volatile unsigned int PRU1_IMEM_PE		 : 4;
	volatile unsigned int PRU1_DMEM_PE		 : 4;
	volatile unsigned int RAM_PE			 : 4;
	const volatile unsigned int __reserved_1 : 12;
};


struct __PRU_CFG_PMAO_S {
	volatile unsigned int PMAO_PRU0			 : 1;
	volatile unsigned int PMAO_PRU1			 : 1;
	const volatile unsigned int __reserved_1 : 30;
};

struct __PRU_CFG_MII_RT_S {
	volatile unsigned int MII_RT_EVENT_EN	 : 1;
	const volatile unsigned int __reserved_1 : 31;
};


struct __PRU_CFG_IEPCLK_S {
	volatile unsigned int OCP_EN			 : 1;
	const volatile unsigned int __reserved_1 : 31;
};

struct __PRU_CFG_SPP_S {
	volatile unsigned int PRU1_PAD_HP_EN	 : 1;
	volatile unsigned int XFR_SHIFT_EN		 : 1;
	const volatile unsigned int __reserved_1 : 31;
};


struct __PRU_CFG_PIN_MX_S {
	const volatile unsigned int __reserved_1		: 8;
	volatile unsigned int PWM0_REMAP_EN				: 1;
	volatile unsigned int PWM3_REMAP_EN				: 1;
	const volatile unsigned int __reserved_2		: 22;
};

struct __PRU_CFG {
	volatile unsigned int REVID;
	union {
		volatile unsigned int SYSCFG;
		struct __PRU_CFG_SYSCFG_S SYSCFG_bit;
	};
	union {
		volatile unsigned int GPCFG0;
		struct __PRU_CFG_GPCFG_S GPCFG0_bit;
#if defined(__AM572X_ICSS0_PRU0__) || defined(__AM572X_ICSS1_PRU0__)
		volatile unsigned int GPCFG;
		struct __PRU_CFG_GPCFG_S GPCFG_bit;
#endif
	};
	union {
		volatile unsigned int GPCFG1;
		struct __PRU_CFG_GPCFG_S GPCFG1_bit;
#if defined(__AM572X_ICSS0_PRU1__) || defined(__AM572X_ICSS1_PRU1__)
		volatile unsigned int GPCFG;
		struct __PRU_CFG_GPCFG_S GPCFG_bit;
#endif
	};
	union {
		volatile unsigned int CGR;
		struct __PRU_CFG_CGR_S CGR_bit;
	};
	union {
		volatile unsigned int ISRP;
		struct __PRU_CFG_ISPx_S ISRP_bit;
	};
	union {
		volatile unsigned int ISP;
		struct __PRU_CFG_ISPx_S ISP_bit;
	};
	union {
		volatile unsigned int IESP;
		struct __PRU_CFG_ISPx_S IESP_bit;
	};
	union {
		volatile unsigned int IECP;
		struct __PRU_CFG_ISPx_S IECP_bit;
	};
	unsigned int ___reserved1[1];
	union {
		volatile unsigned int PMAO;
		struct __PRU_CFG_PMAO_S PMAO_bit;
	};
	union {
		volatile unsigned int MII_RT;
		struct __PRU_CFG_MII_RT_S MII_RT_bit;
	};
	union {
		volatile unsigned int IEPCLK;
		struct __PRU_CFG_IEPCLK_S IEPCLK_bit;
	};
	union {
		volatile unsigned int SPP;
		struct __PRU_CFG_SPP_S SPP_bit;
	};
	volatile unsigned int __gap1[2];
	union {
		volatile unsigned int PIN_MX;
		struct __PRU_CFG_PIN_MX_S PIN_MX_bit;
	};
};
#define PRU_CFG	(*((struct __PRU_CFG *)__CFG_BASE))


#endif
