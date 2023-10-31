#pragma once
#include "stdio.h"
#include "string.h"
#include "stdlib.h"

#define MEM_SIZE 256
#define MEM_END MEM_SIZE-1
#define REGISTERS_COUNT 8

typedef unsigned char byte;

extern byte main_memory[MEM_SIZE];
extern byte registers[REGISTERS_COUNT];

#define MATH_REG registers[0]
#define MOD_REG registers[1]