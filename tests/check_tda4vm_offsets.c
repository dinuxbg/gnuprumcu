#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include <pru/io.h>

#include "test-common.h"

#if !defined(__TDA4VM__) || defined(__TDA4VM_ICSSG0__) || !defined(__TDA4VM_ICSSG1__)
  #error
#endif

#if !defined(__TDA4VM_ICSSG1_PRU0__) || defined(__TDA4VM_ICSSG1_PRU1__) || defined(__TDA4VM_ICSSG1_TX_PRU0__)
  #error
#endif

int main(void)
{
	check_addr(&PRU0_CTRL.CTPPR1, 0x22000+ 0x2C);
	check_addr(&PRU_CTRL.CTPPR1, 0x22000+ 0x2C);
	check_addr(&ICSS_INTC.ENABLE_HINT_REG0, 0x20000+ 0x1500);
	check_addr(&ICSSG_CFG.CORE_SYNC_REG, 0x26000 + 0x3c);
	return 0;
}
