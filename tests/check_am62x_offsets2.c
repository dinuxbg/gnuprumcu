#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include <pru/io.h>

#include "test-common.h"

#if !defined(__AM62X__) || defined(__AM62X_PRU0__) || !defined(__AM62X_PRU1__)
  #error
#endif

int main(void)
{
	check_addr(&PRU_CTRL.CTPPR1, 0x24000+ 0x2C);
	return 0;
}
