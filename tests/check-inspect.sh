#!/bin/sh

# Inspect the built ELFs of the gnuprumcu internal tests

set -e

# TODO - get the PRU tools from Autoconf.
NM=pru-nm
OBJDUMP=pru-objdump

find_symbol()
{
  local F="${1}"
  shift
  local symbol=${1}
  shift
  local symbol_file

  ${NM} --format=just-symbols "${F}" | grep -w ${symbol}
}

assert_symbol_present()
{
  local symbol_file=`find_symbol "${1}" ${2}`
  [ x"${symbol_file}" = x"${2}" ]
}

assert_symbol_missing()
{
  local symbol_file=`find_symbol "${1}" ${2}`
  [ x"${symbol_file}" = x"" ]
}

find_opcode()
{
  local F="${1}"
  shift
  local opc=${1}
  shift

  ${OBJDUMP} --disassemble --wide --no-addresses "${F}" | grep -o -w "${opc}" | uniq
}

assert_opcode_present()
{
  local opc_file=`find_opcode "${1}" ${2}`
  [ x"${opc_file}" = x"${2}" ]
}

assert_opcode_missing()
{
  local opc_file=`find_opcode "${1}" ${2}`
  [ x"${opc_file}" = x"" ]
}

assert_symbol_present ./check_am18xx_options __pruabi_softmpyi
assert_symbol_present ./check_am18xx_options __pruabi_softmpyll
assert_opcode_missing ./check_am18xx_options fill
assert_opcode_missing ./check_am18xx_options zero
assert_opcode_missing ./check_am18xx_options loop
assert_opcode_missing ./check_am18xx_options xin

assert_symbol_missing ./check_am335x_options __pruabi_softmpyi
assert_symbol_missing ./check_am335x_options __pruabi_softmpyll
assert_opcode_present ./check_am335x_options fill
assert_opcode_present ./check_am335x_options zero
assert_opcode_present ./check_am335x_options loop
assert_opcode_present ./check_am335x_options xin
