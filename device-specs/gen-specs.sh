#!/bin/bash

# Generate additional MCU-specific specs for some cores.
# AM4, AM5 and AM6 have way too many variants to maintain
# them manually.


gen_spec()
{
  local soc=${1}
  local icss=${2}
  local core=${3}
  local imem_size=${4}
  local dmem_size=${5}
  local heap_size=${6}
  local stack_size=${7}

  local outf
  local line

  if [ "x${icss}" = "x" ]; then
    outf=${soc}.${core}
    line="-D__${soc}_${core}__ -D__${soc}__"
  else
    outf=${soc}.${icss}.${core}
    line="-D__${soc}_${icss}_${core}__ -D__${soc}_${icss}__ -D__${soc}__"
  fi
  echo '*cpp_device:' > "${outf}"
  # Convert entire line to upper case. It contains only macro names and -D flag.
  echo "${line^^[a-z]}" >> "${outf}"
  echo >> "${outf}"
  echo '*link_device:' >> "${outf}"
  echo "%{!r:--defsym=__IMEM_SIZE=${imem_size} --defsym=__DMEM_SIZE=${dmem_size} --defsym=__HEAP_SIZE=${heap_size} --defsym=__STACK_SIZE=${stack_size}}" >> "${outf}"
}

for c in pru0 pru1; do
  gen_spec am335x "" $c 8K 8K 32 512
done

# SPRUHL7I, 30.1.1, Features
for c in pru0 pru1; do
  gen_spec am437x icss0 $c 4K 4K 32 256
done
for c in pru0 pru1; do
  gen_spec am437x icss1 $c 12K 8K 32 512
done


# SPRUHZ6L, 30.1.1.1, PRU-ICSS Key Features for SR2.0.
for i in icss0 icss1; do
  for c in pru0 pru1; do
    gen_spec am572x $i $c 12K 8K 32 512
  done
done

# SPRUIM2B, 6.4.1.1 PRU_ICSSG Key Features
for i in icssg0 icssg1; do
  for c in 0 1; do
    gen_spec am64x $i pru$c 12K 8K 32 512
    gen_spec am64x $i rtu_pru$c 8K 0 0 0
    gen_spec am64x $i tx_pru$c 6K 0 0 0
  done
done

# SPRUID7E, 6.5.1.1, PRU_ICSSG Key Features for SR2.0.
# SR1.0 is assumed deprecated.
for i in icssg0 icssg1 icssg2; do
  for c in 0 1; do
    gen_spec am65x $i pru$c 12K 8K 32 512
    gen_spec am65x $i rtu_pru$c 8K 0 0 0
    gen_spec am65x $i tx_pru$c 6K 0 0 0
  done
done

# SPRUIL1B, 6.6.1.1 PRU_ICSSG Key Features
for i in icssg0 icssg1; do
  for c in 0 1; do
    gen_spec tda4vm $i pru$c 12K 8K 32 512
    gen_spec tda4vm $i rtu_pru$c 8K 0 0 0
    gen_spec tda4vm $i tx_pru$c 6K 0 0 0
  done
done
