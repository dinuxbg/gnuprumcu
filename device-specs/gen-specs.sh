#!/bin/bash

# Generate additional MCU-specific specs for some cores.
# AM4, AM5 and AM6 have way too many variants to maintain
# them manually.

set -e

# Where to document the list of supported targets.
MD_MCU_LIST=../MCU-LIST.md

# Generate spec file for one PRU core variant.
#   soc        : SoC name (e.g. am335x)
#   icss       : ICSS subsystem name (e.g. icssg0)
#   core       : Core name inside ICSS (e.g. pru0, tx_pru1)
#   imem_size  : IMEM size.
#   dmem_size  : DMEM size.
#   heap_size  : Default heap (dynamic memory pool for malloc) size.
#   stack_size : Default stack size.
gen_spec()
{
  local soc=${1}
  local armarch=${2}
  local icss=${3}
  local core=${4}
  local imem_size=${5}
  local dmem_size=${6}
  local heap_size=${7}
  local stack_size=${8}

  local outf
  local line
  local common_page_size
  local max_page_size

  if [ "x${icss}" = "x" ]; then
    outf=${soc}.${core}
    line="-D__${soc}_${core}__ -D__${soc}__"
  else
    outf=${soc}.${icss}.${core}
    line="-D__${soc}_${icss}_${core}__ -D__${soc}_${icss}__ -D__${soc}__"
  fi
  if [ "x${armarch}" = "xarm32" ]; then
    common_page_size=1
    max_page_size=1
  elif [ "x${armarch}" = "xarm64" ]; then
    # remoteproc running on 64-bit hosts
    # has stricter alignment requirements.
    common_page_size=4
    max_page_size=8
  else
    echo "Unrecognized architecture!"
    exit 1
  fi

  echo '*cpp_device:' > "${outf}"
  # Convert entire line to upper case. It contains only macro names and -D flag.
  echo "${line^^[a-z]}" >> "${outf}"
  echo >> "${outf}"
  echo '*link_device:' >> "${outf}"
  echo "%{!r:--gc-sections --defsym=__IMEM_SIZE=${imem_size} --defsym=__DMEM_SIZE=${dmem_size} --defsym=__HEAP_SIZE=${heap_size} --defsym=__STACK_SIZE=${stack_size} -z common-page-size=${common_page_size} -z max-page-size=${max_page_size}}" >> "${outf}"

  echo " * ${outf}" >> $MD_MCU_LIST
}

echo '# List of PRU device specs' > $MD_MCU_LIST

# SPRUH73Q, 4.1.1, Features
for c in pru0 pru1; do
  gen_spec am335x arm32 "" $c 8K 8K 32 512
done

# SPRUHL7I, 30.1.1, Features
for c in pru0 pru1; do
  gen_spec am437x arm32 icss0 $c 4K 4K 32 256
done
for c in pru0 pru1; do
  gen_spec am437x arm32 icss1 $c 12K 8K 32 512
done


# SPRUHZ6L, 30.1.1.1, PRU-ICSS Key Features for SR2.0.
for i in icss0 icss1; do
  for c in pru0 pru1; do
    gen_spec am572x arm32 $i $c 12K 8K 32 512
  done
done

# SPRUIV7B – MAY 2022 – REVISED SEPTEMBER 2023
# 7.4.3.4.1.1 PRUSS Local Instruction Memory Map
for c in pru0 pru1; do
  gen_spec am62x arm64 "" $c 16K 8K 32 512
done

# SPRUIM2B, 6.4.1.1 PRU_ICSSG Key Features
for i in icssg0 icssg1; do
  for c in 0 1; do
    gen_spec am64x arm64 $i pru$c 12K 8K 32 512
    gen_spec am64x arm64 $i rtu_pru$c 8K 0 0 0
    gen_spec am64x arm64 $i tx_pru$c 6K 0 0 0
  done
done

# SPRUID7E, 6.5.1.1, PRU_ICSSG Key Features for SR2.0.
# SR1.0 is assumed deprecated.
for i in icssg0 icssg1 icssg2; do
  for c in 0 1; do
    gen_spec am65x arm64 $i pru$c 12K 8K 32 512
    gen_spec am65x arm64 $i rtu_pru$c 8K 0 0 0
    gen_spec am65x arm64 $i tx_pru$c 6K 0 0 0
  done
done

# SPRUIL1B, 6.6.1.1 PRU_ICSSG Key Features
for i in icssg0 icssg1; do
  for c in 0 1; do
    gen_spec tda4vm arm64 $i pru$c 12K 8K 32 512
    gen_spec tda4vm arm64 $i rtu_pru$c 8K 0 0 0
    gen_spec tda4vm arm64 $i tx_pru$c 6K 0 0 0
  done
done
