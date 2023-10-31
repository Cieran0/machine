#include "operands.h"

void (*operands_1_args[])(byte arg1) = {
    hault,
    inc_reg,
    dec_reg,
    mult_reg,
    mult_immediate,
    div_reg,
    div_immediate,
    goto_immediate,
    goto_reg,
    goto_mem
};
void (*operands_2_args[])(byte arg1, byte arg2) = {
    add_reg_reg,
    add_reg_immediate,
    sub_reg_reg,
    sub_reg_immediate,
    set_mem_immediate,
    set_mem_reg,
    set_reg_immediate,
    set_reg_mem,
    set_reg_reg
};
