#!/bin/bash

# Generate additional MCU-specific linker scripts by using the
# default PRU-LD linker script.
#
# We do it automatically so that:
#  1. We only change the default linker script in binutils.
#  2. All the default script complexity stays in binutils.
#  3. Here in libgloss we care only to enumerate all PRU variants with
#     their default memory sizes.
#

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

# Delete the "guard" of Data RAM address zero.  It generates errors
# for cores without Data RAM.  This should really be fixed with an option
# to the linker, though.
del_nullprot()
{
  awk "
BEGIN { COMMENT_MARKER = 0; }
{
  if (\$0 == \"    /* DATA memory starts at address 0.  So to avoid placing a valid static\" )
    {
      COMMENT_MARKER = 1;
    }
  if (COMMENT_MARKER == 1)
    {
      if (\$0 == \"    . += (. == 0 ? 4 : 0);\" )
        {
          COMMENT_MARKER = 0;
        }
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

# SPRUHL7I, 30.1.1, Features
dump_modified 4K   4K     "32"         "256"       | tee pruelf-am437x.icss0.pru0.x
dump_modified 4K   4K     "32"         "256"       | tee pruelf-am437x.icss0.pru1.x
dump_modified 12K  8K     "32"         "512"       | tee pruelf-am437x.icss1.pru0.x
dump_modified 12K  8K     "32"         "512"       | tee pruelf-am437x.icss1.pru1.x

# SPRUHZ6L, 30.1.1.1, PRU-ICSS Key Features for SR2.0.
# SR1.0 is assumed deprecated.
dump_modified 12K  8K     "32"         "512"       | tee pruelf-am572x.icss0.pru0.x
dump_modified 12K  8K     "32"         "512"       | tee pruelf-am572x.icss0.pru1.x
dump_modified 12K  8K     "32"         "512"       | tee pruelf-am572x.icss1.pru0.x
dump_modified 12K  8K     "32"         "512"       | tee pruelf-am572x.icss1.pru1.x

# SPRUID7E, 6.5.1.1, PRU_ICSSG Key Features for SR2.0.
# SR1.0 is assumed deprecated.
for icss in icssg0 icssg1 icssg2
do
  for prui in 0 1
  do
    #             IMEM DMEM   HEAP_SIZE    STACK_SIZE
    dump_modified 12K  8K     "32"         "512"       | tee pruelf-am65x.${icss}.pru${prui}.x
    dump_modified 8K   0K     "0"          "0"         | del_nullprot | tee pruelf-am65x.${icss}.rtu_pru${prui}.x
    dump_modified 6K   0K     "0"          "0"         | del_nullprot | tee pruelf-am65x.${icss}.tx_pru${prui}.x
  done
done

# SPRUIL1B, 6.6.1.1 PRU_ICSSG Key Features
for icss in icssg0 icssg1
do
  for prui in 0 1
  do
    #             IMEM DMEM   HEAP_SIZE    STACK_SIZE
    dump_modified 12K  8K     "32"         "512"       | tee pruelf-tda4vm.${icss}.pru${prui}.x
    dump_modified 8K   0K     "0"          "0"         | del_nullprot | tee pruelf-tda4vm.${icss}.rtu_pru${prui}.x
    dump_modified 6K   0K     "0"          "0"         | del_nullprot | tee pruelf-tda4vm.${icss}.tx_pru${prui}.x
  done
done

# dump_modified 256K 65536K "32 * 1024 * 1024" "1024 * 1024" | tee pruelf-sim.x
