#include "main.h"
#include "operands.h"

byte main_memory[MEM_SIZE] = {0};
byte registers[REGISTERS_COUNT] = {0};

void hault(int error) {
    exit(error);
}

void print(byte address) {
    printf("%s",main_memory + address);
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
    fib();
    for (int i = 0; i < 14; i++)
    {
        printf("%d, ",main_memory[i]);
    }
    
    return 0;
}
