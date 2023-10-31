#pragma once
#include "main.h"

void hault(byte error);
void inc_reg(byte reg);
void dec_reg(byte reg);
void mult_reg(byte reg);
void mult_immediate(byte immediate);
void div_reg(byte reg);
void div_immediate(byte immediate);
void goto_immediate(byte immediate);
void goto_reg(byte reg);
void goto_mem(byte address);
void add_reg_reg(byte reg_1, byte reg_2);
void add_reg_immediate(byte reg, byte immediate);
void sub_reg_reg(byte reg_1, byte reg_2);
void sub_reg_immediate(byte reg, byte immediate);
void set_mem_immediate(byte address, byte immediate);
void set_mem_reg(byte address, byte reg);
void set_reg_immediate(byte reg, byte immediate);
void set_reg_mem(byte address, byte reg);
void set_reg_reg(byte reg_1, byte reg_2);

extern void (*operands_1_args[10])(byte arg1);
extern void (*operands_2_args[9])(byte arg1, byte arg2);
#define OP_HAULT 0
#define OP_INC_REG 1
#define OP_DEC_REG 2
#define OP_MULT_REG 3
#define OP_MULT_IMMEDIATE 4
#define OP_DIV_REG 5
#define OP_DIV_IMMEDIATE 6
#define OP_GOTO_IMMEDIATE 7
#define OP_GOTO_REG 8
#define OP_GOTO_MEM 9
#define OP_ADD_REG_REG 10
#define OP_ADD_REG_IMMEDIATE 11
#define OP_SUB_REG_REG 12
#define OP_SUB_REG_IMMEDIATE 13
#define OP_SET_MEM_IMMEDIATE 14
#define OP_SET_MEM_REG 15
#define OP_SET_REG_IMMEDIATE 16
#define OP_SET_REG_MEM 17
#define OP_SET_REG_REG 18
