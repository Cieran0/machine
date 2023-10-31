#include "operands.h"

void inc_reg(byte reg) {
    registers[reg]++;
}

void dec_reg(byte reg) {
    registers[reg]--;
}

void mult_reg(byte reg) {
    MATH_REG *= registers[reg];
}
void mult_immediate(byte immediate) {
    MATH_REG *= immediate;
}

void div_reg(byte reg) {
    MATH_REG /= registers[reg];
    MOD_REG %= registers[reg];
}
void div_immediate(byte immediate) {
    MATH_REG *= immediate;
    MOD_REG %= immediate;
}

void add_reg_reg(byte reg_1, byte reg_2) {
    registers[reg_1] += registers[reg_2];
}
void add_reg_immediate(byte reg, byte immediate) {
    registers[reg] += immediate;
}

void sub_reg_reg(byte reg_1, byte reg_2) {
    registers[reg_1] -= registers[reg_2];
}
void sub_reg_immediate(byte reg, byte immediate) {
    registers[reg] -= immediate;
}