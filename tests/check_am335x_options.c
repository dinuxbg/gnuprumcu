#include <pru/io.h>

#ifndef __AM335X__
  #error
#endif

#ifndef __AM335X_PRU0__
  #error
#endif

#ifdef __AM335X_PRU1__
  #error
#endif

volatile unsigned v;
volatile unsigned a;
volatile unsigned b;

volatile long long vv;
volatile long long aa;
volatile long long bb;

int main(void)
{
	unsigned i;

	v = 0;
	v = ~0;
	v = a * b;

	vv = aa * bb;

	for (i=0; i<100; i++)
		v = a;
	vv = 0;
	vv = ~0;
	for(;;) {
	}
}
