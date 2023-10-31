#include "main.h"
#include "operands.h"

byte haulted = 0;

#define array_size(x) sizeof(x)/sizeof(x[0])

byte main_memory[MEM_SIZE] = {0};
byte read_only_memory[MEM_SIZE] = {
    OP_SET_MEM_IMMEDIATE,0,'H',
    OP_SET_MEM_IMMEDIATE,1,'e',
    OP_SET_MEM_IMMEDIATE,2,'l',
    OP_SET_MEM_IMMEDIATE,3,'l',
    OP_SET_MEM_IMMEDIATE,4,'o',
    OP_SET_MEM_IMMEDIATE,5,' ',
    OP_SET_MEM_IMMEDIATE,6,'W',
    OP_SET_MEM_IMMEDIATE,7,'o',
    OP_SET_MEM_IMMEDIATE,8,'r',
    OP_SET_MEM_IMMEDIATE,9,'l',
    OP_SET_MEM_IMMEDIATE,10,'d',
    OP_SET_MEM_IMMEDIATE,11,'!',
    OP_SET_MEM_IMMEDIATE,12,'\n',
    OP_SET_MEM_IMMEDIATE,13,'\0',
};
byte registers[REGISTERS_COUNT] = {0};

void print(byte address) {
    printf("%s",main_memory + address);
}

void execute_current_instruction() {
    byte ci = read_only_memory[INSTRUCTION_POINTER];
    if(ci < array_size(operands_1_args)) { 
        operands_1_args[ci](read_only_memory[INSTRUCTION_POINTER+1]);
        INSTRUCTION_POINTER+=2;
        return;
    ci-=array_size(operands_1_args);
    if(ci < array_size(operands_2_args))
        operands_2_args[ci](read_only_memory[INSTRUCTION_POINTER+1],read_only_memory[INSTRUCTION_POINTER+2]);
        INSTRUCTION_POINTER+=3;
        return;
    } 
    printf("rut roh");
    exit(-1);
}

void fib() {
    int i = 0;
    int n = 0;
    //0 = t1
    //1 = t2
    //2 = nextTerm
    //int t1 = 0, t2 = 1;
    set_reg_immediate(0,0);
    set_reg_immediate(1,1);
    set_reg_immediate(2,1);
    add_reg_reg(2,0);
    set_mem_immediate(0,0);
    set_mem_immediate(1,0);
    set_mem_immediate(2,1);
    // print 3rd to nth terms
    for (i = 3; i <= 14; ++i) {
        set_reg_reg(0,1);
        set_reg_reg(1,2);
        set_reg_reg(2,0);
        add_reg_reg(2,1);
        set_mem_reg(i,2);
    }
}

int main() {
    while (!haulted)
    {
        execute_current_instruction();
    }
    print(0);
    return 0;
}
