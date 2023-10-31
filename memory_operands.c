#include "operands.h"

void set_mem_immediate(byte address, byte immediate) {
    main_memory[address]=immediate;
}

void set_mem_reg(byte address, byte reg) {
    main_memory[address]=registers[reg];
}

void set_reg_immediate(byte reg, byte immediate) {
    registers[reg] = immediate;
}

void set_reg_mem(byte address, byte reg) {
    registers[reg] = main_memory[address];
}

void set_reg_reg(byte reg_1, byte reg_2) {
    registers[reg_1] = registers[reg_2];
}