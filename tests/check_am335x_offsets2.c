#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include <pru/io.h>

#include "test-common.h"

#ifndef __AM335X__
  #error
#endif

#ifdef __AM335X_PRU0__
  #error
#endif

#ifndef __AM335X_PRU1__
  #error
#endif

int main(void)
{
	check_addr(&PRU_CTRL.CTPPR1, 0x24000+ 0x2C);
	return 0;
}
