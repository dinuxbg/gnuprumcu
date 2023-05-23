#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

static inline void check_addr(volatile void *ptr, const uint32_t addr)
{
	uintptr_t A = (uintptr_t)ptr;
	if (A != addr) {
		abort();
	}
}
