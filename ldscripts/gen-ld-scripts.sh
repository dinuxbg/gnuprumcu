#!/bin/bash

# Generate additional MCU-specific linker scripts by using the
# default PRU-LD linker script.
#
# We do it automatically so that:
#  1. We only change the default linker script in binutils.
#  2. All the default script complexity stays in binutils.
#  3. Here in libgloss we care only to enumerate all PRU variants with
#     their default memory sizes.

dump_modified()
{
  IMEM_SIZE=$1
  DMEM_SIZE=$2
  HEAP_SIZE=$3
  STACK_SIZE=$4

  echo "/* WARNING: automatically generated from the default pru-ld script! */"
  echo -e "\n\n"
  pru-ld --verbose | awk "
BEGIN { LDV_MARKER = 0; }
{
  if (\$0 == \"==================================================\" )
    {
      LDV_MARKER++;
    }
  else if (LDV_MARKER != 1)
    {
    }
  else if (\$0 ~ /^  imem.*ORIGIN =.*LENGTH =/)
    {
      print \"  imem   (x)   : ORIGIN = 0x20000000, LENGTH = $IMEM_SIZE\"
    }
  else if (\$0 ~ /^  dmem.*ORIGIN =.*LENGTH =/)
    {
      print \"  dmem   (rw!x) : ORIGIN = 0x0, LENGTH = $DMEM_SIZE\"
    }
  else if (\$0 ~ /^__HEAP_SIZE = DEFINED/)
    {
      print \"__HEAP_SIZE = DEFINED(__HEAP_SIZE) ? __HEAP_SIZE : $HEAP_SIZE ;\";
    }
  else if (\$0 ~ /^__STACK_SIZE = DEFINED/)
    {
      print \"__STACK_SIZE = DEFINED(__STACK_SIZE) ? __STACK_SIZE : $STACK_SIZE ;\";
    }
  else
    {
      print \$0;
    }
}"
}

#             IMEM DMEM   HEAP_SIZE    STACK_SIZE
dump_modified 8K   8K     "32"         "512"       | tee pruelf-am335x.pru0.x
dump_modified 8K   8K     "32"         "512"       | tee pruelf-am335x.pru1.x
dump_modified 4K   4K     "32"         "256"       | tee pruelf-am437x.icss0.pru0.x
dump_modified 4K   4K     "32"         "256"       | tee pruelf-am437x.icss0.pru1.x
dump_modified 8K   8K     "32"         "512"       | tee pruelf-am437x.icss1.pru0.x
dump_modified 8K   8K     "32"         "512"       | tee pruelf-am437x.icss1.pru1.x
dump_modified 12K  8K     "32"         "512"       | tee pruelf-am572x.icss0.pru0.x
dump_modified 12K  8K     "32"         "512"       | tee pruelf-am572x.icss0.pru1.x
dump_modified 12K  8K     "32"         "512"       | tee pruelf-am572x.icss1.pru0.x
dump_modified 12K  8K     "32"         "512"       | tee pruelf-am572x.icss1.pru1.x

# dump_modified 256K 65536K "32 * 1024 * 1024" "1024 * 1024" | tee pruelf-sim.x
