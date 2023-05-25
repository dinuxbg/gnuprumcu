/* SPDX-License-Identifier: BSD-2-Clause-FreeBSD
 *
 * pru/am62x.h -- PRU I/O registers definitions for PRU inside AM62x SoCs
 *
 * Copyright (c) 2023 Dimitar Dimitrov <dimitar@dinux.eu>
 * All rights reserved.
 */

/*
 * Reference: SPRUIV7A – MAY 2022 – REVISED NOVEMBER 2022
 */

#ifndef __PRU_AM62X_H__
#define __PRU_AM62X_H__


/* Local memory map (TRM section 7.4.3.4.1.2) */
#define __LOCAL_DATA_RAM_BASE		0x00000000
#define __PEER_DATA_RAM_BASE		0x00002000
#define __SHARED_DATA_RAM_BASE		0x00010000
#define __INTC_BASE			0x00020000
#define __PRU0_CTRL_REGS_BASE		0x00022000
#define __PRU1_CTRL_REGS_BASE		0x00024000
#define __PROTECT_BASE			0x00024C00
#define __CFG_BASE			0x00026000
#define __UART0_BASE			0x00028000
#define __IEP_BASE			0x0002E000
#define __ECAP0_BASE			0x00030000
#define __MII_RT_CFG_BASE		0x00032000
#define __MII_MDIO_BASE			0x00032400

/* ====================== CTABLE base addresses ====================== */
/* 7.4.4.2.1 PRU Constant Table */
#pragma ctable_entry 0 0x00020000
#pragma ctable_entry 1 0x0002f000
#pragma ctable_entry 2 0x0002f100
#pragma ctable_entry 3 0x00030000
#pragma ctable_entry 4 0x00026000
#pragma ctable_entry 5 0x00026100
#pragma ctable_entry 6 0x00020200
#pragma ctable_entry 7 0x00028000
#pragma ctable_entry 8 0x0002e100
#pragma ctable_entry 9 0x00033000
/* #pragma ctable_entry 10 RESERVED */
#if defined(__AM62X_PRU0__)
  #pragma ctable_entry 11 0x00022000
#elif defined(__AM62X_PRU1__)
  #pragma ctable_entry 11 0x00024000
#endif
/* #pragma ctable_entry 12 RESERVED */
/* #pragma ctable_entry 13 RESERVED */
/* #pragma ctable_entry 14 RESERVED */
#pragma ctable_entry 15 0x60000000
#pragma ctable_entry 16 0x70000000
#pragma ctable_entry 17 0x80000000
#pragma ctable_entry 18 0x90000000
#pragma ctable_entry 19 0xa0000000
#pragma ctable_entry 20 0xb0000000
#pragma ctable_entry 21 0x00032400
#if defined(__AM62X_PRU0__)
  #pragma ctable_entry 22 0x00008000
#elif defined(__AM62X_PRU1__)
  #pragma ctable_entry 22 0x00009000
#endif
#pragma ctable_entry 23 0xc0000000
/* 24-31 are user-defined base addresses. */

/* ====================== PRU CTRL module ====================== */
/* 7.5.8.105 PR1_PDSP0__IRAM__REGS_ICSSM_CONTROL Registers */

struct __PRU_CONTROL_S {
	const volatile unsigned int SOFT_RST_N		: 1;
	volatile unsigned int PDSP_ENABLE		: 1;
	volatile unsigned int PDSP_SLEEPING		: 1;
	volatile unsigned int COUNTER_ENABLE		: 1;
	volatile unsigned int RESTART			: 1;
	volatile unsigned int __reserved_1		: 3;
	volatile unsigned int SINGLE_STEP		: 1;
	volatile unsigned int __reserved_2		: 5;
	const volatile unsigned int PRU_BIG_ENDIAN	: 1;
	const volatile unsigned int PDSP_STATE		: 1;
	volatile unsigned int PCOUNTER_RST_VAL		: 16;
};

struct __PRU_STATUS_S {
	const volatile unsigned int PCOUNTER		: 16;
	const volatile unsigned int __reserved_1	: 16;
};

struct __PRU_CTBIR0_S {
	volatile unsigned int C24_BLK_INDEX		: 8;
	volatile unsigned int __reserved_1		: 8;
	volatile unsigned int C25_BLK_INDEX		: 8;
	volatile unsigned int __reserved_2		: 8;
};

struct __PRU_CTBIR1_S {
	volatile unsigned int C26_BLK_INDEX		: 8;
	volatile unsigned int __reserved_1		: 8;
	volatile unsigned int C27_BLK_INDEX		: 8;
	volatile unsigned int __reserved_2		: 8;
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
	volatile unsigned int WAKEUP_ENABLE;
	union {
		volatile unsigned int CYCLE;       /* Alias for source compatibility. */
		volatile unsigned int CYCLE_COUNT; /* Per AM62x TRM. */
	};
	union {
		volatile unsigned int STALL;
		volatile unsigned int STALL_COUNT;
	};
	volatile unsigned int __gap1[3];
	union {
		volatile unsigned int CTBIR0;
		volatile unsigned int CONSTANT_TABLE_BLOCK_INDEX_0;
		struct __PRU_CTBIR0_S CTBIR0_bit;
		struct __PRU_CTBIR0_S CONSTANT_TABLE_BLOCK_INDEX_0_bit;
	};
	union {
		volatile unsigned int CTBIR1;
		volatile unsigned int CONSTANT_TABLE_BLOCK_INDEX_1;
		struct __PRU_CTBIR1_S CTBIR1_bit;
		struct __PRU_CTBIR1_S CONSTANT_TABLE_BLOCK_INDEX_1_bit;
	};
	union {
		volatile unsigned int CTPPR0;
		volatile unsigned int CONSTANT_TABLE_PROG_PTR_0;
		struct __PRU_CTPPR0_S CTPPR0_bit;
		struct __PRU_CTPPR0_S CONSTANT_TABLE_PROG_PTR_0_bit;
	};
	union {
		volatile unsigned int CTPPR1;
		volatile unsigned int CONSTANT_TABLE_PROG_PTR_1;
		struct __PRU_CTPPR1_S CTPPR1_bit;
		struct __PRU_CTPPR1_S CONSTANT_TABLE_PROG_PTR_1_bit;
	};
};

#define PRU0_CTRL	(*((struct __PRU_CTRL *)__PRU0_CTRL_REGS_BASE))
#define PRU1_CTRL	(*((struct __PRU_CTRL *)__PRU1_CTRL_REGS_BASE))

#if defined(__AM62X_PRU0__)
  #define PRU_CTRL	PRU0_CTRL
#elif defined(__AM62X_PRU1__)
  #define PRU_CTRL	PRU1_CTRL
#else
  #error "Unrecognized AM62x PRU core - check your -mmcu option"
#endif



/* ====================== PRU INTC module ====================== */
/* 7.5.8.42 */

struct __PRU_INTC_REVID_S {
	const volatile unsigned int REV_MINOR		: 6;
	const volatile unsigned int REV_CUSTOM		: 2;
	const volatile unsigned int REV_MAJOR		: 3;
	const volatile unsigned int REV_RTL		: 5;
	const volatile unsigned int REV_MODULE		: 12;
	const volatile unsigned int __reserved_1	: 2;
	const volatile unsigned int REV_SCHEME		: 2;
};


struct __PRU_INTC_CONTROL_S {
	volatile unsigned int __reserved_1		: 1;
	volatile unsigned int WAKEUP_MODE		: 1;
	volatile unsigned int NEST_MODE			: 2;
	volatile unsigned int PRIORITY_HOLD_MODE	: 1;
	volatile unsigned int __reserved_3		: 27;
};


struct __PRU_INTC_GER_S {
	volatile unsigned int EN_HINT_ANY		: 1;
	volatile unsigned int __reserved_2		: 31;
};


struct __PRU_INTC_GNLR_S {
	volatile unsigned int GLB_NEST_LEVEL		: 9;
	volatile unsigned int __reserved_1		: 22;
	volatile unsigned int GLB_NEST_AUTO_OVR		: 1;
};


struct __PRU_INTC_SISR_S {
	volatile unsigned int STATUS_SET_INDEX		: 10;
	volatile unsigned int __reserved_1		: 22;
};


struct __PRU_INTC_SICR_S {
	volatile unsigned int STATUS_CLR_INDEX		: 10;
	volatile unsigned int __reserved_1		: 22;
};


struct __PRU_INTC_EISR_S {
	volatile unsigned int ENABLE_SET_INDEX		: 10;
	volatile unsigned int __reserved_1		: 22;
};


struct __PRU_INTC_EICR_S {
	volatile unsigned int ENABLE_CLR_INDEX		: 10;
	volatile unsigned int __reserved_1		: 22;
};


struct __PRU_INTC_HIEISR_S {
	volatile unsigned int HINT_ENABLE_SET_INDEX	: 10;
	volatile unsigned int __reserved_1		: 22;
};


struct __PRU_INTC_HIDISR_S {
	volatile unsigned int HINT_ENABLE_CLR_INDEX	: 10;
	volatile unsigned int __reserved_1		: 22;
};

struct __PRU_INTC_GPIR_S {
	volatile unsigned int GLB_PRI_INTR		: 10;
	volatile unsigned int __reserved_1		: 21;
	volatile unsigned int GLB_NONE			: 1;
};


#define __PRU_STR2(A,B) A ## B
#define __PRU_STR(A,B) __PRU_STR2(A,B)

#define __PRU_INTC_CMR_decl(N,O0,O1,O2,O3) \
        union { \
                volatile unsigned int CH_MAP_REG_ ## N;  \
		struct { \
        		volatile unsigned int __PRU_STR(CH_MAP_,O0) : 5; \
        		volatile unsigned int __reserved_1          : 3; \
        		volatile unsigned int __PRU_STR(CH_MAP_,O1) : 5; \
        		volatile unsigned int __reserved_2          : 3; \
        		volatile unsigned int __PRU_STR(CH_MAP_,O2) : 5; \
        		volatile unsigned int __reserved_3          : 3; \
        		volatile unsigned int __PRU_STR(CH_MAP_,O3) : 5; \
        		volatile unsigned int __reserved_4          : 3; \
		} __attribute__((packed)) CH_MAP_REG ## N ## _bit; \
        };

#define __PRU_INTC_HMR_decl(N,O0,O1,O2,O3) \
        union { \
                volatile unsigned int HINT_MAP_REG ## N;  \
		struct { \
        		volatile unsigned int __PRU_STR(HINT_MAP_,O0) : 5; \
        		volatile unsigned int __reserved_1            : 3; \
        		volatile unsigned int __PRU_STR(HINT_MAP_,O1) : 5; \
        		volatile unsigned int __reserved_2            : 3; \
        		volatile unsigned int __PRU_STR(HINT_MAP_,O2) : 5; \
        		volatile unsigned int __reserved_3            : 3; \
        		volatile unsigned int __PRU_STR(HINT_MAP_,O3) : 5; \
        		volatile unsigned int __reserved_4            : 3; \
		} __attribute__((packed)) HINT_MAP_REG ## N ## _bit; \
        };

#define __PRU_INTC_PRI_HINT_decl(N) \
        union { \
                volatile unsigned int PRI_HINT_REG ## N;  \
		struct { \
        		volatile unsigned int __PRU_STR(PRI_HINT_,N) : 10; \
        		volatile unsigned int __reserved_1            : 21; \
        		volatile unsigned int __PRU_STR(NONE_HINT_,N) : 1; \
		} __attribute__((packed)) PRI_HINT_REG ## N ## _bit; \
        };

#define __PRU_INTC_NEST_LEVEL_decl(N) \
        union { \
                volatile unsigned int NEST_LEVEL_REG ## N;  \
		struct { \
        		volatile unsigned int __PRU_STR(NEST_HINT,N) : 9; \
        		volatile unsigned int __reserved_1            : 22; \
        		volatile unsigned int __PRU_STR(NEST_AUTO_OVR,N) : 1; \
		} __attribute__((packed)) NEXT_LEVEL_REG ## N ## _bit; \
        };

struct __PRU_INTC_HIER_S {
	volatile unsigned int EN_HINT_0			: 1;
	volatile unsigned int EN_HINT_1			: 1;
	volatile unsigned int EN_HINT_2			: 1;
	volatile unsigned int EN_HINT_3			: 1;
	volatile unsigned int EN_HINT_4			: 1;
	volatile unsigned int EN_HINT_5			: 1;
	volatile unsigned int EN_HINT_6			: 1;
	volatile unsigned int EN_HINT_7			: 1;
	volatile unsigned int EN_HINT_8			: 1;
	volatile unsigned int EN_HINT_9			: 1;
	volatile unsigned int __reserved_1		: 22;
};

struct __PRU_INTC {
	union {
		const volatile unsigned int REVISION_REG;
		struct __PRU_INTC_REVID_S REVISION_REG_bit;
	};
	union {
		volatile unsigned int CONTROL_REG;
		struct __PRU_INTC_CONTROL_S CONTROL_REG_bit;
	};
	unsigned int __gap1[2];
	union {
		volatile unsigned int GLOBAL_ENABLE_HINT_REG;
		struct __PRU_INTC_GER_S GLOBAL_ENABLE_HINT_REG_bit;
	};
	unsigned int __gap2[2];
	union {
		volatile unsigned int GLB_NEST_LEVEL_REG;
		struct __PRU_INTC_GNLR_S GLB_NEST_LEVEL_REG_bit;
	};
	union {
		volatile unsigned int STATUS_SET_INDEX_REG;
		struct __PRU_INTC_SISR_S STATUS_SET_INDEX_REG_bit;
	};
	union {
		volatile unsigned int STATUS_CLR_INDEX_REG;
		struct __PRU_INTC_SICR_S STATUS_CLR_INDEX_REG_bit;
	};
	union {
		volatile unsigned int ENABLE_SET_INDEX_REG;
		struct __PRU_INTC_EISR_S ENABLE_SET_INDEX_REG_bit;
	};
	union {
		volatile unsigned int ENABLE_CLR_INDEX_REG;
		struct __PRU_INTC_EICR_S ENABLE_CLR_INDEX_REG_bit;
	};
	unsigned int __gap3[1];
	union {
		volatile unsigned int HINT_ENABLE_SET_INDEX_REG;
		struct __PRU_INTC_HIEISR_S HINT_ENABLE_SET_INDEX_REG_bit;
	};
	union {
		volatile unsigned int HINT_ENABLE_CLR_INDEX_REG;
		struct __PRU_INTC_HIDISR_S HINT_ENABLE_CLR_INDEX_REG_bit;
	};
	unsigned int __gap4[17];
	union {
		volatile unsigned int GLB_PRI_INTR_REG;
		struct __PRU_INTC_GPIR_S GLB_PRI_INTR_REG_bit;
	};
	unsigned int __gap5[95];
	volatile unsigned int RAW_STATUS_REG0;
	volatile unsigned int RAW_STATUS_REG1;
	unsigned int __gap6[30];
	volatile unsigned int ENA_STATUS_REG0;
	volatile unsigned int ENA_STATUS_REG1;
	unsigned int __gap7[30];
	volatile unsigned int ENABLE_REG0;
	volatile unsigned int ENABLE_REG1;
	unsigned int __gap8[30];
	volatile unsigned int ENABLE_CLR_REG0;
	volatile unsigned int ENABLE_CLR_REG1;
	unsigned int __gap9[30];
	__PRU_INTC_CMR_decl(0, 0,1,2,3);	/* 0x400 */
	__PRU_INTC_CMR_decl(1, 4,5,6,7);
	__PRU_INTC_CMR_decl(2, 8,9,10,11);
	__PRU_INTC_CMR_decl(3, 12,13,14,15);
	__PRU_INTC_CMR_decl(4, 16,17,18,19);
	__PRU_INTC_CMR_decl(5, 20,21,22,23);
	__PRU_INTC_CMR_decl(6, 24,25,26,27);
	__PRU_INTC_CMR_decl(7, 28,29,30,31);
	__PRU_INTC_CMR_decl(8, 32,33,34,35);
	__PRU_INTC_CMR_decl(9, 36,37,38,39);
	__PRU_INTC_CMR_decl(10, 40,41,42,43);
	__PRU_INTC_CMR_decl(11, 44,45,46,47);
	__PRU_INTC_CMR_decl(12, 48,49,50,51);
	__PRU_INTC_CMR_decl(13, 52,53,54,55);
	__PRU_INTC_CMR_decl(14, 56,57,58,59);
	__PRU_INTC_CMR_decl(15, 60,61,62,63);
	unsigned int __gap10[240];
	__PRU_INTC_HMR_decl(0, 0,1,2,3);	/* 0x800 */
	__PRU_INTC_HMR_decl(1, 4,5,6,7);
	__PRU_INTC_HMR_decl(2, 8,9,10,11);
	unsigned int __gap11[61];
	__PRU_INTC_PRI_HINT_decl(0);		/* 0x900 */
	__PRU_INTC_PRI_HINT_decl(1);
	__PRU_INTC_PRI_HINT_decl(2);
	__PRU_INTC_PRI_HINT_decl(3);
	__PRU_INTC_PRI_HINT_decl(4);
	__PRU_INTC_PRI_HINT_decl(5);
	__PRU_INTC_PRI_HINT_decl(6);
	__PRU_INTC_PRI_HINT_decl(7);
	__PRU_INTC_PRI_HINT_decl(8);
	__PRU_INTC_PRI_HINT_decl(9);
	unsigned int __gap12[246];
	volatile unsigned int POLARITY_REG0;
	volatile unsigned int POLARITY_REG1;
	unsigned int __gap13[30];
	volatile unsigned int TYPE_REG0;
	volatile unsigned int TYPE_REG1;
	unsigned int __gap14[222];
	__PRU_INTC_NEST_LEVEL_decl(0);	/* 0x1100 */
	__PRU_INTC_NEST_LEVEL_decl(1);
	__PRU_INTC_NEST_LEVEL_decl(2);
	__PRU_INTC_NEST_LEVEL_decl(3);
	__PRU_INTC_NEST_LEVEL_decl(4);
	__PRU_INTC_NEST_LEVEL_decl(5);
	__PRU_INTC_NEST_LEVEL_decl(6);
	__PRU_INTC_NEST_LEVEL_decl(7);
	__PRU_INTC_NEST_LEVEL_decl(8);
	__PRU_INTC_NEST_LEVEL_decl(9);
	unsigned int __gap15[246];
	union {
		volatile unsigned int ENABLE_HINT_REG0;
		struct __PRU_INTC_HIER_S ENABLE_HINT_REG0_bit;
	};
};
#define PRU_INTC	(*((struct __PRU_INTC *)__INTC_BASE))

/* Alias used by TI's RPMSG examples. */
#define CT_INTC		PRU_INTC

/* ====================== PRU UART module ====================== */
/* TODO */

/* ====================== PRU eCAP module ====================== */
/* TODO */

/* ====================== PRU CFG module ====================== */

struct __PRU_CFG_HWDIS_S {
	volatile unsigned int HWDIS			: 8;
	volatile unsigned int __reserved_1		: 24;
};

struct __PRU_CFG_GPCFG_S {
	volatile unsigned int GPI_MODE			: 2;
	volatile unsigned int GPI_CLK_MODE		: 1;
	volatile unsigned int GPI_DIV0			: 5;
	volatile unsigned int GPI_DIV1			: 5;
	volatile unsigned int GPI_SB			: 1;
	volatile unsigned int GPO_MODE			: 1;
	volatile unsigned int GPO_DIV0			: 5;
	volatile unsigned int GPO_DIV1			: 5;
	volatile unsigned int GPO_SH1_SEL		: 1;
	volatile unsigned int GP_MUX_SEL		: 4;
	volatile unsigned int __reserved_1		: 2;
};

struct __PRU_CFG_CGR_S {
	volatile unsigned int __reserved_1		: 6;
	volatile unsigned int INTC_CLK_STOP_REQ		: 1;
	const volatile unsigned int INTC_CLK_STOP_ACK	: 1;
	volatile unsigned int INTC_CLK_EN		: 1;
	volatile unsigned int UART_CLK_STOP_REQ		: 1;
	const volatile unsigned int UART_CLK_STOP_ACK	: 1;
	volatile unsigned int UART_CLK_EN		: 1;
	volatile unsigned int ECAP_CLK_STOP_REQ		: 1;
	const volatile unsigned int ECAP_CLK_STOP_ACK	: 1;
	volatile unsigned int ECAP_CLK_EN		: 1;
	volatile unsigned int IEP_CLK_STOP_REQ		: 1;
	const volatile unsigned int IEP_CLK_STOP_ACK	: 1;
	volatile unsigned int IEP_CLK_EN		: 1;
	volatile unsigned int AUTO_SLICE0_CLK_GATE_EN	: 1;
	volatile unsigned int AUTO_SLICE1_CLK_GATE_EN	: 1;
	volatile unsigned int TOP_HALF_CLK_GATE_EN	: 1;
	volatile unsigned int BOTTOM_HALF_CLK_GATE_EN	: 1;
	volatile unsigned int __reserved_2		: 7;
	volatile unsigned int ICSS_PWR_IDLE		: 1;
	const volatile unsigned int ICSS_STOP_REQ	: 1;
	volatile unsigned int ICSS_STOP_ACK		: 1;
};

struct __PRU_CFG_GPECFG_S {
	volatile unsigned int GPI_SB_P			: 1;
	volatile unsigned int GPI_SHIFT_EN		: 1;
	volatile unsigned int __reserved_1		: 2;
	volatile unsigned int GPO_SHIFT_SWAP		: 1;
	volatile unsigned int GPO_SHIFT_CLK_FREE	: 1;
	volatile unsigned int GPO_SHIFT_GP_EN		: 1;
	volatile unsigned int __reserved_2		: 1;
	volatile unsigned int GPO_SHIFT_CNT		: 8;
	volatile unsigned int GPO_SHIFT_CLK_HIGH	: 1;
	volatile unsigned int GPO_SHIFT_CLK_DONE	: 1;
	volatile unsigned int __reserved_3		: 14;
};


struct __PRU_CFG_RESET_ISO_S {
	volatile unsigned int RESET_ISO_REQ		: 1;
	volatile unsigned int RESET_ISO_ACK		: 1;
	volatile unsigned int RESET_ISO_EDGE		: 1;
	volatile unsigned int __reserved_1		: 29;
};

struct __PRU_CFG_IEPCLK_S {
	volatile unsigned int OCP_CLK_EN		: 1;
	volatile unsigned int SLV_EN			: 1;
	volatile unsigned int __reserved_1		: 30;
};

struct __PRU_CFG_SPP_S {
	volatile unsigned int PRU1_PAD_HP_EN		: 1;
	volatile unsigned int XFR_SHIFT_EN		: 1;
	volatile unsigned int XFR_BYTE_SHIFT_EN		: 1;
	volatile unsigned int RTU_XFR_SHIFT_EN		: 1;
	volatile unsigned int __reserved_1		: 28;
};


struct __PRU_CFG_SPIN_S {
	volatile unsigned int SPIN_CLOCK_TX_PRU_EN	: 1;
	volatile unsigned int __reserved_1		: 31;
};

struct __PRU_CFG_SYNC_S {
	volatile unsigned int CORE_VBUSP_SYNC_EN	: 1;
	volatile unsigned int __reserved_1		: 31;
};

struct __PRU_CFG {
	volatile unsigned int PID_REG;
	union {
		volatile unsigned int HWDIS_REG;
		struct __PRU_CFG_HWDIS_S HWDIS_REG_bit;
	};
	union {
		volatile unsigned int GPCFG0_REG;
		struct __PRU_CFG_GPCFG_S GPCFG0_REG_bit;
#if defined(__AM62X_PRU0__)
		volatile unsigned int GPCFG_REG;
		struct __PRU_CFG_GPCFG_S GPCFG_REG_bit;
#endif
	};
	union {
		volatile unsigned int GPCFG1_REG;
		struct __PRU_CFG_GPCFG_S GPCFG1_REG_bit;
#if defined(__AM62X_PRU1__)
		volatile unsigned int GPCFG_REG;
		struct __PRU_CFG_GPCFG_S GPCFG_REG_bit;
#endif
	};
	union {
		volatile unsigned int CGR_REG;
		struct __PRU_CFG_CGR_S CGR_REG_bit;
	};
	union {
		volatile unsigned int GPECFG0_REG;
		struct __PRU_CFG_GPECFG_S GPECFG0_REG_bit;
#if defined(__AM62X_PRU0__)
		volatile unsigned int GPECFG_REG;
		struct __PRU_CFG_GPECFG_S GPECFG_REG_bit;
#endif
	};
	union {
		volatile unsigned int GPECFG1_REG;
		struct __PRU_CFG_GPECFG_S GPECFG1_REG_bit;
#if defined(__AM62X_PRU1__)
		volatile unsigned int GPECFG_REG;
		struct __PRU_CFG_GPECFG_S GPECFG_REG_bit;
#endif
	};
	union {
		volatile unsigned int RESET_ISO_REG;
		struct __PRU_CFG_RESET_ISO_S RESET_ISO_REG_bit;
	};
	volatile unsigned int __gap1[4];
	union {
		volatile unsigned int IEPCLK_REG;
		struct __PRU_CFG_IEPCLK_S IEPCLK_REG_bit;
	};
	union {
		volatile unsigned int SPP_REG;
		struct __PRU_CFG_SPP_S SPP_REG_bit;
	};
	union {
		volatile unsigned int SPIN_CFG_REG;
		struct __PRU_CFG_SPIN_S SPIN_CFG_REG_bit;
	};
	union {
		volatile unsigned int CORE_SYNC_REG;
		struct __PRU_CFG_SYNC_S CORE_SYNC_REG_bit;
	};
};
#define PRU_CFG	(*((struct __PRU_CFG *)__CFG_BASE))

/* Alias used in TI's RPMSG examples. */
#define CT_CFG	PRU_CFG

#endif
