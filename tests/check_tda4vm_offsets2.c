#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include <pru/io.h>

#include "test-common.h"

#if !defined(__TDA4VM__) || defined(__TDA4VM_ICSSG0__) || !defined(__TDA4VM_ICSSG1__)
  #error
#endif

#if defined(__TDA4VM_ICSSG1_PRU0__) || !defined(__TDA4VM_ICSSG1_PRU1__) || defined(__TDA4VM_ICSSG1_TX_PRU0__)
  #error
#endif

int main(void)
{
	check_addr(&PRU_CTRL.CTPPR1, 0x24000+ 0x2C);
	return 0;
}
