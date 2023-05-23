#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include <pru/io.h>

#include "test-common.h"

#if !defined(__AM572X__) || defined(__AM572X_ICSS0__) || !defined(__AM572X_ICSS1__)
  #error
#endif

#if defined(__AM572X_ICSS0_PRU0__) || !defined(__AM572X_ICSS1_PRU0__)
  #error
#endif

#if defined(__AM572X_ICSS0_PRU1__) || defined(__AM572X_ICSS1_PRU1__)
  #error
#endif

int main(void)
{
	check_addr(&PRU0_CTRL.CTPPR1, 0x22000+ 0x2C);
	check_addr(&PRU_CTRL.CTPPR1, 0x22000+ 0x2C);
	check_addr(&PRU_INTC.HIER, 0x20000+ 0x1500);

	check_addr(&PRU_CFG.PMAO, 0x26000 + 0x28);
	check_addr(&PRU_CFG.SPP, 0x26000 + 0x34);
	check_addr(&PRU_CFG.PIN_MX, 0x26000 + 0x40);
	return 0;
}
