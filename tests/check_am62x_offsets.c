#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include <pru/io.h>

#include "test-common.h"

#if !defined(__AM62X__) || !defined(__AM62X_PRU0__) || defined(__AM62X_PRU1__)
  #error
#endif

int main(void)
{
	check_addr(&PRU0_CTRL.CTPPR1, 0x22000+ 0x2C);
	check_addr(&PRU_CTRL.CTPPR1, 0x22000+ 0x2C);
	check_addr(&PRU_INTC.ENABLE_HINT_REG0, 0x20000+ 0x1500);

	check_addr(&PRU_CFG.RESET_ISO_REG, 0x26000 + 0x1c);
	check_addr(&PRU_CFG.IEPCLK_REG, 0x26000 + 0x30);
	check_addr(&PRU_CFG.SPP_REG, 0x26000 + 0x34);
	check_addr(&PRU_CFG.CORE_SYNC_REG, 0x26000 + 0x3c);
	return 0;
}
