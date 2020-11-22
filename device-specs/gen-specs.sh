#!/bin/bash

# Generate additional MCU-specific specs for some cores.
# AM4, AM5 and AM6 have way too many variants to maintain
# them manually.


# echo ${var^^h}
gen_spec()
{
  local soc=${1}
  local ICSS_LIST=${2}
  local PRU_LIST=${3}

  local icss
  local pru
  local outf
  local line

  for icss in ${ICSS_LIST}
  do
    for pru in ${PRU_LIST}
    do
      outf=${soc}.${icss}.${pru}
      echo '*cpp_device:' > ${outf}
      line="-D__${soc}_${icss}_${pru}__ -D__${soc}_${icss}__ -D__${soc}__"
      echo ${line^^[a-z]} >> ${outf}
      echo >> ${outf}
      echo '*link_device:' >> ${outf}
      echo "%{!r:-Tpruelf-${soc}.${icss}.${pru}.x}" >> ${outf}
    done
  done
}

gen_spec am437x "icss0 icss1" "pru0 pru1"
gen_spec am572x "icss0 icss1" "pru0 pru1"
gen_spec am65x "icssg0 icssg1 icssg2" "pru0 pru1 rtu_pru0 rtu_pru1 tx_pru0 tx_pru1"
