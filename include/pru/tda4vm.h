/* SPDX-License-Identifier: BSD-2-Clause-FreeBSD
 *
 * pru/tda4vm.h -- PRU I/O registers definitions for PRU inside TDA4 SoCs
 * Source: SPRUJ61 – AUGUST 2022
 *
 * Copyright (c) 2022 Dimitar Dimitrov <dimitar@dinux.eu>
 * All rights reserved.
 */

#ifndef __PRU_TDA4VM_H__
#define __PRU_TDA4VM_H__


/* Local memory map
 * Section "5.4.1.2 PRU_ICSSG Local Data Memory Map"
 */
#define __LOCAL_DATA_RAM_BASE		0x00000000
#define __PEER_DATA_RAM_BASE		0x00002000
#define __RAT_SLICE0_BASE		0x00008000
#define __RAT_SLICE1_BASE		0x00009000
#define __SHARED_DATA_RAM_BASE		0x00010000
#define __INTC_BASE			0x00020000
#define __PRU0_CTRL_REGS_BASE		0x00022000
#define __RTU_PRU0_CTRL_REGS_BASE	0x00023000
#define __RTU_PRU1_CTRL_REGS_BASE	0x00023800
#define __PRU1_CTRL_REGS_BASE		0x00024000
#define __PROTECT_BASE			0x00024C00
#define __TX_PRU0_CTRL_REGS_BASE	0x00025000
#define __TX_PRU1_CTRL_REGS_BASE	0x00025800
#define __CFG_BASE			0x00026000
#define __PA_STATS_QRAM_BASE		0x00027000
#define __UART0_BASE			0x00028000
#define __TM_CFG_PRU0_BASE		0x0002A000
#define __TM_CFG_RTU0_BASE		0x0002A100
#define __TM_CFG_PRU1_BASE		0x0002A200
#define __TM_CFG_RTU1_BASE		0x0002A300
#define __TM_CFG_TX_PRU0_BASE		0x0002A400
#define __TM_CFG_TX_PRU1_BASE		0x0002A500
#define __PA_STATS_CRAM_BASE		0x0002C000
#define __IEP0_BASE			0x0002E000
#define __IEP1_BASE			0x0002F000
#define __ECAP0_BASE			0x00030000
#define __MII_RT_CFG_BASE		0x00032000
#define __SGMII0_CFG_BASE		0x00032100
#define __SGMII1_CFG_BASE		0x00032200
#define __MII_MDIO_BASE			0x00032400
#define __ICSS_G_CFG_BASE		0x00033000
#define __PA_STATS_CFG_BASE		0x0003C000

/* ====================== CTABLE base addresses ====================== */
#pragma ctable_entry 0 0x00020000
#pragma ctable_entry 1 0x0002F000
#pragma ctable_entry 2 0x0002F100
#pragma ctable_entry 3 0x00030000
#pragma ctable_entry 4 0x00026000
#pragma ctable_entry 5 0x00026100
#pragma ctable_entry 6 0x00020200
#pragma ctable_entry 7 0x00028000
#pragma ctable_entry 8 0x0002E100
#pragma ctable_entry 9 0x00033000

#if defined(__TDA4VM_ICSSG0_PRU0__) || defined(__TDA4VM_ICSSG1_PRU0__)
  #pragma ctable_entry 10 0x0002A000
#elif defined(__TDA4VM_ICSSG0_RTU_PRU0__) || defined(__TDA4VM_ICSSG1_RTU_PRU0__)
  #pragma ctable_entry 10 0x0002A100
#elif defined(__TDA4VM_ICSSG0_PRU1__) || defined(__TDA4VM_ICSSG1_PRU1__)
  #pragma ctable_entry 10 0x0002A200
#elif defined(__TDA4VM_ICSSG0_RTU_PRU1__) || defined(__TDA4VM_ICSSG1_RTU_PRU1__)
  #pragma ctable_entry 10 0x0002A300
#endif

#if defined(__TDA4VM_ICSSG0_PRU0__) || defined(__TDA4VM_ICSSG1_PRU0__)
  #pragma ctable_entry 11 0x00022000
#elif defined(__TDA4VM_ICSSG0_RTU_PRU0__) || defined(__TDA4VM_ICSSG1_RTU_PRU0__)
  #pragma ctable_entry 11 0x00023000
#elif defined(__TDA4VM_ICSSG0_PRU1__) || defined(__TDA4VM_ICSSG1_PRU1__)
  #pragma ctable_entry 11 0x00024000
#elif defined(__TDA4VM_ICSSG0_RTU_PRU1__) || defined(__TDA4VM_ICSSG1_RTU_PRU1__)
  #pragma ctable_entry 11 0x00023800
#endif

#pragma ctable_entry 12 0x00027000
#pragma ctable_entry 13 0x0002C000
#pragma ctable_entry 14 0x00024800
#pragma ctable_entry 15 0x60000000
#pragma ctable_entry 16 0x70000000
#pragma ctable_entry 17 0x80000000
#pragma ctable_entry 18 0x90000000
#pragma ctable_entry 19 0xA0000000
#pragma ctable_entry 20 0xB0000000
#pragma ctable_entry 21 0x00032400

#if defined(__TDA4VM_ICSSG0_PRU0__) || defined(__TDA4VM_ICSSG1_PRU0__) || defined(__TDA4VM_ICSSG0_RTU_PRU0__) || defined(__TDA4VM_ICSSG1_RTU_PRU0__)
  #pragma ctable_entry 22 0x00008000
#elif defined(__TDA4VM_ICSSG0_PRU1__) || defined(__TDA4VM_ICSSG1_PRU1__) || defined(__TDA4VM_ICSSG0_RTU_PRU1__) || defined(__TDA4VM_ICSSG1_RTU_PRU1__)
  #pragma ctable_entry 22 0x00009000
#endif

#pragma ctable_entry 23 0xC0000000

/* 24-31 are user-defined base addresses. */

/* ====================== PRU CTRL module ====================== */
struct __PRU_CONTROL_S {
	const volatile unsigned int SOFT_RST_N		: 1;
	volatile unsigned int ENABLE			: 1;
	volatile unsigned int SLEEPING			: 1;
	volatile unsigned int COUNTER_ENABLE		: 1;
	volatile unsigned int __reserved_1		: 4;
	volatile unsigned int SINGLE_STEP		: 1;
	volatile unsigned int __reserved_2		: 4;
	volatile unsigned int TS_ENABLE			: 1;
	const volatile unsigned int __reserved_3	: 1;
	const volatile unsigned int RUNSTATE		: 1;
	volatile unsigned int PCOUNTER_RST_VAL		: 16;
};

struct __PRU_STATUS_S {
	const volatile unsigned int PCOUNTER		: 16;
	const volatile unsigned int __reserved_1	: 16;
};

struct __PRU_CTBIR0_S {
	volatile unsigned int C24_BLK_INDEX		: 8;
	const volatile unsigned int __reserved_1	: 8;
	volatile unsigned int C25_BLK_INDEX		: 8;
	const volatile unsigned int __reserved_2	: 8;
};

struct __PRU_CTBIR1_S {
	volatile unsigned int C26_BLK_INDEX		: 8;
	const volatile unsigned int __reserved_1	: 8;
	volatile unsigned int C27_BLK_INDEX		: 8;
	const volatile unsigned int __reserved_2	: 8;
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
#define RTU_PRU0_CTRL	(*((struct __PRU_CTRL *)__RTU_PRU0_CTRL_REGS_BASE))
#define TX_PRU0_CTRL	(*((struct __PRU_CTRL *)__TX_PRU0_CTRL_REGS_BASE))
#define PRU1_CTRL	(*((struct __PRU_CTRL *)__PRU1_CTRL_REGS_BASE))
#define RTU_PRU1_CTRL	(*((struct __PRU_CTRL *)__RTU_PRU1_CTRL_REGS_BASE))
#define TX_PRU1_CTRL	(*((struct __PRU_CTRL *)__TX_PRU1_CTRL_REGS_BASE))

#if defined(__TDA4VM_ICSSG0_PRU0__) || defined(__TDA4VM_ICSSG1_PRU0__)
  #define PRU_CTRL	PRU0_CTRL
#elif defined(__TDA4VM_ICSSG0_PRU1__) || defined(__TDA4VM_ICSSG1_PRU1__)
  #define PRU_CTRL	PRU1_CTRL
#elif defined(__TDA4VM_ICSSG0_RTU_PRU0__) || defined(__TDA4VM_ICSSG1_RTU_PRU0__)
  #define PRU_CTRL	RTU_PRU0_CTRL
#elif defined(__TDA4VM_ICSSG0_RTU_PRU1__) || defined(__TDA4VM_ICSSG1_RTU_PRU1__)
  #define PRU_CTRL	RTU_PRU1_CTRL
#elif defined(__TDA4VM_ICSSG0_TX_PRU0__) || defined(__TDA4VM_ICSSG1_TX_PRU0__)
  #define PRU_CTRL	TX_PRU0_CTRL
#elif defined(__TDA4VM_ICSSG0_TX_PRU1__) || defined(__TDA4VM_ICSSG1_TX_PRU1__)
  #define PRU_CTRL	TX_PRU1_CTRL
#else
  #error "Unrecognized TDA4VM PRU core - check your -mmcu option"
#endif


/* ====================== ICSS INTC module ====================== */

struct __ICSS_INTC_REVID_S {
	const volatile unsigned int REV_MINOR		: 6;
	const volatile unsigned int REV_CUSTOM		: 2;
	const volatile unsigned int REV_MAJOR		: 3;
	const volatile unsigned int REV_RTL		: 5;
	const volatile unsigned int REV_MODULE		: 12;
	const volatile unsigned int __reserved_1	: 2;
	const volatile unsigned int REV_SCHEME		: 2;
};


struct __ICSS_INTC_CR_S {
	volatile unsigned int __reserved_1		: 1;
	volatile unsigned int WAKEUP_MODE		: 1;
	volatile unsigned int NEST_MODE			: 2;
	volatile unsigned int PRIORITY_HOLD_MODE	: 1;
	volatile unsigned int __reserved_3		: 27;
};


struct __ICSS_INTC_GER_S {
	volatile unsigned int EN_HINT_ANY		: 1;
	volatile unsigned int __reserved_2		: 31;
};


struct __ICSS_INTC_GNLR_S {
	volatile unsigned int GLB_NEST_LEVEL		: 9;
	volatile unsigned int __reserved_1		: 22;
	volatile unsigned int GLB_NEST_AUTO_OVR		: 1;
};


struct __ICSS_INTC_SISR_S {
	volatile unsigned int STATUS_SET_INDEX		: 10;
	volatile unsigned int __reserved_1		: 22;
};


struct __ICSS_INTC_SICR_S {
	volatile unsigned int STATUS_CLR_INDEX		: 10;
	volatile unsigned int __reserved_1		: 22;
};


struct __ICSS_INTC_EISR_S {
	volatile unsigned int ENABLE_SET_INDEX		: 10;
	volatile unsigned int __reserved_1		: 22;
};


struct __ICSS_INTC_EICR_S {
	volatile unsigned int ENABLE_CLR_INDEX		: 10;
	volatile unsigned int __reserved_1		: 22;
};


struct __ICSS_INTC_HIEISR_S {
	volatile unsigned int HINT_ENABLE_SET_INDEX	: 10;
	volatile unsigned int __reserved_1		: 22;
};

struct __ICSS_INTC_HIEICR_S {
	volatile unsigned int HINT_ENABLE_CLR_INDEX	: 10;
	volatile unsigned int __reserved_1		: 22;
};


struct __ICSS_INTC_GPIR_S {
	volatile unsigned int GLB_PRI_INTR		: 10;
	volatile unsigned int __reserved_1		: 21;
	volatile unsigned int GLB_NONE			: 1;
};


#define __ICSS_STR2(A,B) A ## B
#define __ICSS_STR(A,B) __ICSS_STR2(A,B)

#define __ICSS_INTC_CMR_decl(N,O0,O1,O2,O3) \
        union { \
                volatile unsigned int CH_MAP_REG_ ## N;  \
		struct { \
        		volatile unsigned int __ICSS_STR(CH_MAP_,O0) : 5; \
        		volatile unsigned int __reserved_1           : 3; \
        		volatile unsigned int __ICSS_STR(CH_MAP_,O1) : 5; \
        		volatile unsigned int __reserved_2           : 3; \
        		volatile unsigned int __ICSS_STR(CH_MAP_,O2) : 5; \
        		volatile unsigned int __reserved_3           : 3; \
        		volatile unsigned int __ICSS_STR(CH_MAP_,O3) : 5; \
        		volatile unsigned int __reserved_4           : 3; \
		} __attribute__((packed)) CH_MAP_REG ## N ## _bit; \
        };

#define __ICSS_INTC_HMR_decl(N,O0,O1,O2,O3) \
        union { \
                volatile unsigned int HINT_MAP_REG ## N;  \
		struct { \
        		volatile unsigned int __ICSS_STR(HINT_MAP_,O0) : 5; \
        		volatile unsigned int __reserved_1            : 3; \
        		volatile unsigned int __ICSS_STR(HINT_MAP_,O1) : 5; \
        		volatile unsigned int __reserved_2            : 3; \
        		volatile unsigned int __ICSS_STR(HINT_MAP_,O2) : 5; \
        		volatile unsigned int __reserved_3            : 3; \
        		volatile unsigned int __ICSS_STR(HINT_MAP_,O3) : 5; \
        		volatile unsigned int __reserved_4            : 3; \
		} __attribute__((packed)) HINT_MAP_REG ## N ## _bit; \
        };

#define __ICSS_INTC_PRI_HINT_decl(N) \
        union { \
                volatile unsigned int PRI_HINT_REG ## N;  \
		struct { \
        		volatile unsigned int __ICSS_STR(PRI_HINT_,N) : 10; \
        		volatile unsigned int __reserved_1            : 21; \
        		volatile unsigned int __ICSS_STR(NONE_HINT_,N) : 1; \
		} __attribute__((packed)) PRI_HINT_REG ## N ## _bit; \
        };

#define __ICSS_INTC_NEST_LEVEL_decl(N) \
        union { \
                volatile unsigned int NEST_LEVEL_REG ## N;  \
		struct { \
        		volatile unsigned int __ICSS_STR(NEST_HINT,N) : 9; \
        		volatile unsigned int __reserved_1            : 22; \
        		volatile unsigned int __ICSS_STR(NEST_AUTO_OVR,N) : 1; \
		} __attribute__((packed)) NEXT_LEVEL_REG ## N ## _bit; \
        };


struct __ICSS_INTC_HIER_S {
	volatile unsigned int ENABLE_HINT_0		: 1;
	volatile unsigned int ENABLE_HINT_1		: 1;
	volatile unsigned int ENABLE_HINT_2		: 1;
	volatile unsigned int ENABLE_HINT_3		: 1;
	volatile unsigned int ENABLE_HINT_4		: 1;
	volatile unsigned int ENABLE_HINT_5		: 1;
	volatile unsigned int ENABLE_HINT_6		: 1;
	volatile unsigned int ENABLE_HINT_7		: 1;
	volatile unsigned int ENABLE_HINT_8		: 1;
	volatile unsigned int ENABLE_HINT_9		: 1;
	volatile unsigned int ENABLE_HINT_10		: 1;
	volatile unsigned int ENABLE_HINT_11		: 1;
	volatile unsigned int ENABLE_HINT_12		: 1;
	volatile unsigned int ENABLE_HINT_13		: 1;
	volatile unsigned int ENABLE_HINT_14		: 1;
	volatile unsigned int ENABLE_HINT_15		: 1;
	volatile unsigned int ENABLE_HINT_16		: 1;
	volatile unsigned int ENABLE_HINT_17		: 1;
	volatile unsigned int ENABLE_HINT_18		: 1;
	volatile unsigned int ENABLE_HINT_19		: 1;
	volatile unsigned int __reserved_1		: 12;
};

struct __ICSS_INTC {
	union {	/* 0x00 */
		const volatile unsigned int REVISION_REG;
		struct __ICSS_INTC_REVID_S REVISION_REG_bit;
	};
	union {	/* 0x04 */
		volatile unsigned int CONTROL_REG;
		struct __ICSS_INTC_CR_S CONTROL_REG_bit;
	};
	unsigned int __gap1[2];
	union {	/* 0x10 */
		volatile unsigned int GLOBAL_ENABLE_HINT_REG;
		struct __ICSS_INTC_GER_S GLOBAL_ENABLE_HINT_REG_bit;
	};
	unsigned int __gap2[2];
	union {	/* 0x1C */
		volatile unsigned int GLB_NEST_LEVEL_REG;
		struct __ICSS_INTC_GNLR_S GLB_NEST_LEVEL_REG_bit;
	};
	union {	/* 0x20 */
		volatile unsigned int STATUS_SET_INDEX_REG;
		struct __ICSS_INTC_SISR_S STATUS_SET_INDEX_REG_bit;
	};
	union {	/* 0x24 */
		volatile unsigned int STATUS_CLR_INDEX_REG;
		struct __ICSS_INTC_SICR_S STATUS_CLR_INDEX_REG_bit;
	};
	union {	/* 0x28 */
		volatile unsigned int ENABLE_SET_INDEX_REG;
		struct __ICSS_INTC_EISR_S ENABLE_SET_INDEX_REG_bit;
	};
	union {	/* 0x2C */
		volatile unsigned int ENABLE_CLR_INDEX_REG;
		struct __ICSS_INTC_EICR_S ENABLE_CLR_INDEX_REG_bit;
	};
	unsigned int __gap3[1];
	union {	/* 0x34 */
		volatile unsigned int HINT_ENABLE_SET_INDEX_REG;
		struct __ICSS_INTC_HIEISR_S HINT_ENABLE_SET_INDEX_REG_bit;
	};
	union { /* 0x38 */
		volatile unsigned int HINT_ENABLE_CLR_INDEX_REG;
		struct __ICSS_INTC_HIEICR_S HINT_ENABLE_CLR_INDEX_REG_bit;
	};
	unsigned int __gap4[17];
	union { /* 0x80 */
		volatile unsigned int GLB_PRI_INTR_REG;
		struct __ICSS_INTC_GPIR_S GLB_PRI_INTR_REG_bit;
	};
	unsigned int __gap5[95];
	volatile unsigned int RAW_STATUS_REG0;	/* 0x200 */
	volatile unsigned int RAW_STATUS_REG1;
	volatile unsigned int RAW_STATUS_REG2;
	volatile unsigned int RAW_STATUS_REG3;
	volatile unsigned int RAW_STATUS_REG4;
	unsigned int __gap6[27];
	volatile unsigned int ENA_STATUS_REG0;	/* 0x280 */
	volatile unsigned int ENA_STATUS_REG1;
	volatile unsigned int ENA_STATUS_REG2;
	volatile unsigned int ENA_STATUS_REG3;
	volatile unsigned int ENA_STATUS_REG4;
	unsigned int __gap7[27];
	volatile unsigned int ENABLE_REG0;	/* 0x300 */
	volatile unsigned int ENABLE_REG1;
	volatile unsigned int ENABLE_REG2;
	volatile unsigned int ENABLE_REG3;
	volatile unsigned int ENABLE_REG4;
	unsigned int __gap8[27];
	volatile unsigned int ENABLE_CLR_REG0;	/* 0x380 */
	volatile unsigned int ENABLE_CLR_REG1;
	volatile unsigned int ENABLE_CLR_REG2;
	volatile unsigned int ENABLE_CLR_REG3;
	volatile unsigned int ENABLE_CLR_REG4;
	unsigned int __gap9[27];
	__ICSS_INTC_CMR_decl(0, 0,1,2,3);	/* 0x400 */
	__ICSS_INTC_CMR_decl(1, 4,5,6,7);
	__ICSS_INTC_CMR_decl(2, 8,9,10,11);
	__ICSS_INTC_CMR_decl(3, 12,13,14,15);
	__ICSS_INTC_CMR_decl(4, 16,17,18,19);
	__ICSS_INTC_CMR_decl(5, 20,21,22,23);
	__ICSS_INTC_CMR_decl(6, 24,25,26,27);
	__ICSS_INTC_CMR_decl(7, 28,29,30,31);
	__ICSS_INTC_CMR_decl(8, 32,33,34,35);
	__ICSS_INTC_CMR_decl(9, 36,37,38,39);
	__ICSS_INTC_CMR_decl(10, 40,41,42,43);
	__ICSS_INTC_CMR_decl(11, 44,45,46,47);
	__ICSS_INTC_CMR_decl(12, 48,49,50,51);
	__ICSS_INTC_CMR_decl(13, 52,53,54,55);
	__ICSS_INTC_CMR_decl(14, 56,57,58,59);
	__ICSS_INTC_CMR_decl(15, 60,61,62,63);
	__ICSS_INTC_CMR_decl(16, 64,65,66,67);
	__ICSS_INTC_CMR_decl(17, 68,69,70,71);
	__ICSS_INTC_CMR_decl(18, 72,73,74,75);
	__ICSS_INTC_CMR_decl(19, 76,77,78,79);
	__ICSS_INTC_CMR_decl(20, 80,81,82,83);
	__ICSS_INTC_CMR_decl(21, 84,85,86,87);
	__ICSS_INTC_CMR_decl(22, 88,89,90,91);
	__ICSS_INTC_CMR_decl(23, 92,93,94,95);
	__ICSS_INTC_CMR_decl(24, 96,97,98,99);
	__ICSS_INTC_CMR_decl(25, 100,101,102,103);
	__ICSS_INTC_CMR_decl(26, 104,105,106,107);
	__ICSS_INTC_CMR_decl(27, 108,109,110,111);
	__ICSS_INTC_CMR_decl(28, 112,113,114,115);
	__ICSS_INTC_CMR_decl(29, 116,117,118,119);
	__ICSS_INTC_CMR_decl(30, 120,121,122,123);
	__ICSS_INTC_CMR_decl(31, 124,125,126,127);
	__ICSS_INTC_CMR_decl(32, 128,129,130,131);
	__ICSS_INTC_CMR_decl(33, 132,133,134,135);
	__ICSS_INTC_CMR_decl(34, 136,137,138,139);
	__ICSS_INTC_CMR_decl(35, 140,141,142,143);
	__ICSS_INTC_CMR_decl(36, 144,145,146,147);
	__ICSS_INTC_CMR_decl(37, 148,149,150,151);
	__ICSS_INTC_CMR_decl(38, 152,153,154,155);
	__ICSS_INTC_CMR_decl(39, 156,157,158,159);
	unsigned int __gap10[256-40];
	__ICSS_INTC_HMR_decl(0, 0,1,2,3);	/* 0x800 */
	__ICSS_INTC_HMR_decl(1, 4,5,6,7);
	__ICSS_INTC_HMR_decl(2, 8,9,10,11);
	__ICSS_INTC_HMR_decl(3, 12,13,14,15);
	__ICSS_INTC_HMR_decl(4, 16,17,18,19);
	unsigned int __gap11[59];
	__ICSS_INTC_PRI_HINT_decl(0);		/* 0x900 */
	__ICSS_INTC_PRI_HINT_decl(1);
	__ICSS_INTC_PRI_HINT_decl(2);
	__ICSS_INTC_PRI_HINT_decl(3);
	__ICSS_INTC_PRI_HINT_decl(4);
	__ICSS_INTC_PRI_HINT_decl(5);
	__ICSS_INTC_PRI_HINT_decl(6);
	__ICSS_INTC_PRI_HINT_decl(7);
	__ICSS_INTC_PRI_HINT_decl(8);
	__ICSS_INTC_PRI_HINT_decl(9);
	__ICSS_INTC_PRI_HINT_decl(10);
	__ICSS_INTC_PRI_HINT_decl(11);
	__ICSS_INTC_PRI_HINT_decl(12);
	__ICSS_INTC_PRI_HINT_decl(13);
	__ICSS_INTC_PRI_HINT_decl(14);
	__ICSS_INTC_PRI_HINT_decl(15);
	__ICSS_INTC_PRI_HINT_decl(16);
	__ICSS_INTC_PRI_HINT_decl(17);
	__ICSS_INTC_PRI_HINT_decl(18);
	__ICSS_INTC_PRI_HINT_decl(19);
	unsigned int __gap12[0xD00/4 - 0x900/4 - 20];
	volatile unsigned int POLARITY_REG0;	/* 0xD00 */
	volatile unsigned int POLARITY_REG1;
	volatile unsigned int POLARITY_REG2;
	volatile unsigned int POLARITY_REG3;
	volatile unsigned int POLARITY_REG4;
	unsigned int __gap13[27];
	volatile unsigned int TYPE_REG0;	/* 0xD80 */
	volatile unsigned int TYPE_REG1;
	volatile unsigned int TYPE_REG2;
	volatile unsigned int TYPE_REG3;
	volatile unsigned int TYPE_REG4;
	unsigned int __gap14[219];
	__ICSS_INTC_NEST_LEVEL_decl(0);	/* 0x1100 */
	__ICSS_INTC_NEST_LEVEL_decl(1);
	__ICSS_INTC_NEST_LEVEL_decl(2);
	__ICSS_INTC_NEST_LEVEL_decl(3);
	__ICSS_INTC_NEST_LEVEL_decl(4);
	__ICSS_INTC_NEST_LEVEL_decl(5);
	__ICSS_INTC_NEST_LEVEL_decl(6);
	__ICSS_INTC_NEST_LEVEL_decl(7);
	__ICSS_INTC_NEST_LEVEL_decl(8);
	__ICSS_INTC_NEST_LEVEL_decl(9);
	__ICSS_INTC_NEST_LEVEL_decl(10);
	__ICSS_INTC_NEST_LEVEL_decl(11);
	__ICSS_INTC_NEST_LEVEL_decl(12);
	__ICSS_INTC_NEST_LEVEL_decl(13);
	__ICSS_INTC_NEST_LEVEL_decl(14);
	__ICSS_INTC_NEST_LEVEL_decl(15);
	__ICSS_INTC_NEST_LEVEL_decl(16);
	__ICSS_INTC_NEST_LEVEL_decl(17);
	__ICSS_INTC_NEST_LEVEL_decl(18);
	__ICSS_INTC_NEST_LEVEL_decl(19);
	unsigned int __gap15[0x1500/4 - 0x1100/4 - 20];
	union {	/* 0x1500 */
		volatile unsigned int ENABLE_HINT_REG0;
		struct __ICSS_INTC_HIER_S ENABLE_HINT_REG0_bit;
	};
};
#define ICSS_INTC	(*((struct __ICSS_INTC *)__INTC_BASE))

/* Alias used in TI's RPMSG examples. */
#define CT_INTC		ICSS_INTC

/* ====================== PRU UART module ====================== */
/* TODO */

/* ====================== PRU eCAP module ====================== */
/* TODO */

/* ====================== ICSSG CFG module ====================== */

struct __ICSSG_CFG_PID_REG_S {
	volatile unsigned int REVMIN			: 6;
	volatile unsigned int CUSTOM			: 2;
	volatile unsigned int REVMAJ			: 3;
	volatile unsigned int REVRTL			: 5;
	volatile unsigned int MODID			: 16;
};

struct __ICSSG_CFG_HWDIS_S {
	volatile unsigned int HWDIS			: 8;
	volatile unsigned int __reserved_1		: 24;
};

struct __ICSSG_CFG_GPCFGx_S {
	volatile unsigned int GPI_MODE			: 2;
	volatile unsigned int GPI_CLK_MODE		: 1;
	volatile unsigned int GPI_DIV0			: 5;
	volatile unsigned int GPI_DIV1			: 5;
	volatile unsigned int GPI_SB			: 1;
	volatile unsigned int GPO_MODE			: 1;
	volatile unsigned int GPO_DIV0			: 5;
	volatile unsigned int GPO_DIV1			: 5;
	volatile unsigned int GPO_SH1_SEL		: 1;
	volatile unsigned int PR1_GP_MUX_SEL		: 4;
	volatile unsigned int __reserved_1		: 2;
};

struct __ICSSG_CFG_GPCFG0_S {
	volatile unsigned int PRU0_GPI_MODE		: 2;
	volatile unsigned int PRU0_GPI_CLK_MODE		: 1;
	volatile unsigned int PRU0_GPI_DIV0		: 5;
	volatile unsigned int PRU0_GPI_DIV1		: 5;
	volatile unsigned int PRU0_GPI_SB		: 1;
	volatile unsigned int PRU0_GPO_MODE		: 1;
	volatile unsigned int PRU0_GPO_DIV0		: 5;
	volatile unsigned int PRU0_GPO_DIV1		: 5;
	volatile unsigned int PRU0_GPO_SH1_SEL		: 1;
	volatile unsigned int PR1_PRU0_GP_MUX_SEL	: 4;
	volatile unsigned int PRU0___reserved_1		: 2;
};

struct __ICSSG_CFG_GPCFG1_S {
	volatile unsigned int PRU1_GPI_MODE		: 2;
	volatile unsigned int PRU1_GPI_CLK_MODE		: 1;
	volatile unsigned int PRU1_GPI_DIV0		: 5;
	volatile unsigned int PRU1_GPI_DIV1		: 5;
	volatile unsigned int PRU1_GPI_SB		: 1;
	volatile unsigned int PRU1_GPO_MODE		: 1;
	volatile unsigned int PRU1_GPO_DIV0		: 5;
	volatile unsigned int PRU1_GPO_DIV1		: 5;
	volatile unsigned int PRU1_GPO_SH1_SEL		: 1;
	volatile unsigned int PR1_PRU1_GP_MUX_SEL	: 4;
	volatile unsigned int PRU1___reserved_1		: 2;
};

struct __ICSSG_CFG_CGR_S {
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
	volatile unsigned int __reserved_2		: 11;
	volatile unsigned int ICSS_PWR_IDLE		: 1;
	const volatile unsigned int ICSS_STOP_REQ	: 1;
	volatile unsigned int ICSS_STOP_ACK		: 1;
};

struct __ICSSG_CFG {
	union {
		volatile unsigned int PID_REG;
		struct __ICSSG_CFG_PID_REG_S PID_REG_bit;
	};
	union {
		volatile unsigned int HWDIS_REG;
		struct __ICSSG_CFG_HWDIS_S HWDIS_REG_bit;
	};
	union {
		volatile unsigned int GPCFG0_REG;
		struct __ICSSG_CFG_GPCFG0_S GPCFG0_REG_bit;
#if defined(__TDA4VM_ICSSG0_PRU0__) || defined(__TDA4VM_ICSSG0_RTU_PRU0__) || defined(__TDA4VM_ICSSG0_TX_PRU0__) || defined(__TDA4VM_ICSSG1_PRU0__) || defined(__TDA4VM_ICSSG1_RTU_PRU0__) || defined(__TDA4VM_ICSSG1_TX_PRU0__)
		volatile unsigned int GPCFG_REG;
		struct __ICSSG_CFG_GPCFGx_S GPCFG_REG_bit;
#endif
	};
	union {
		volatile unsigned int GPCFG1_REG;
		struct __ICSSG_CFG_GPCFG1_S GPCFG1_REG_bit;
#if defined(__TDA4VM_ICSSG0_PRU1__) || defined(__TDA4VM_ICSSG0_RTU_PRU1__) || defined(__TDA4VM_ICSSG0_TX_PRU1__) || defined(__TDA4VM_ICSSG1_PRU1__) || defined(__TDA4VM_ICSSG1_RTU_PRU1__) || defined(__TDA4VM_ICSSG1_TX_PRU1__)
		volatile unsigned int GPCFG_REG;
		struct __ICSSG_CFG_GPCFGx_S GPCFG_REG_bit;
#endif
	};
	union {	/* 0x10 */
		volatile unsigned int CGR_REG;
		struct __ICSSG_CFG_CGR_S CGR_REG_bit;
	};
	union {
		volatile unsigned int GPECFG0_REG;
	};
	union {
		volatile unsigned int GPECFG1_REG;
	};
	unsigned int __gap0[4];
	union {	/* 0x2c */
		volatile unsigned int MII_RT_REG;
	};
	union {	/* 0x30 */
		volatile unsigned int IEPCLK_REG;
	};
	union {	/* 0x34 */
		volatile unsigned int SPP_REG;
	};
	unsigned int __gap1[1];
	union {	/* 0x3c */
		volatile unsigned int CORE_SYNC_REG;
	};
	union {	/* 0x40 */
		volatile unsigned int SA_MX_REG;
	};
	/* TODO - add the rest of the registers. */
};

/* Name per TI documentation. */
#define ICSSG_CFG	(*((struct __ICSSG_CFG *)__CFG_BASE))

/* Alias used in TI's RPMSG examples. */
#define CT_CFG		ICSSG_CFG

/* ====================== PRU PROT module ====================== */
/* TODO */

/* ====================== PRU RAT_SLICE module ====================== */
/* TODO */

/* ====================== PRU TASKS module ====================== */
/* TODO */

/* ====================== PRU RAM module ====================== */
/* TODO */


#endif

