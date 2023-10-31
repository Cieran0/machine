#pragma once
#include "main.h"
void set_mem_immediate(byte address, byte immediate);
void set_mem_reg(byte address, byte reg);
void set_reg_immediate(byte reg, byte immediate);
void set_reg_mem(byte address, byte reg);
void set_reg_reg(byte reg_1, byte reg_2);
void inc_reg(byte reg);
void dec_reg(byte reg);
void mult_reg(byte reg);
void mult_immediate(byte immediate);
void div_reg(byte reg);
void div_immediate(byte immediate);
void add_reg_reg(byte reg_1, byte reg_2);
void add_reg_immediate(byte reg, byte immediate);
void sub_reg_reg(byte reg_1, byte reg_2);
void sub_reg_immediate(byte reg, byte immediate);
