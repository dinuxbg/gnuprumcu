#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include <pru/io.h>

#include "test-common.h"

#ifndef __AM335X__
  #error
#endif

#ifndef __AM335X_PRU0__
  #error
#endif

#ifdef __AM335X_PRU1__
  #error
#endif

int main(void)
{
	check_addr(&PRU0_CTRL.CTPPR1, 0x22000+ 0x2C);
	check_addr(&PRU_CTRL.CTPPR1, 0x22000+ 0x2C);
	check_addr(&PRU_INTC.HIER, 0x20000+ 0x1500);
	check_addr(&PRU_CFG.PIN_MX, 0x26000 + 0x40);
	return 0;
}
