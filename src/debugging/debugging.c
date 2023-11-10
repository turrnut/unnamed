#include <stdio.h>
#include "debugging.h"
#include "../types/types.h"

void showIR(IR* ir, const char* testname) {
    printf("DEBUGGING: %s\n\n",testname);
    for (int idx = 0; idx < ir->counter;) {
        idx = showInstruction(ir, idx);
    }
}

static int displayUnknownInstruction(int inscode, int idx) {
    printf("Unkown instruction %d\n", inscode);
    return idx + 1;
}

static int displayInstruction(const char* ins, int idx) {
    printf("%s\n", ins);
    return idx + 1;
}

static int displayOneOperandInstruction(const char* ins, IR* ir, int idx) {
    uint8_t operand = ir->code[idx + 1];
    printf("%-16s\t%6d (", ins, operand);
    printStuff(ir->list.data[operand]);
    printf(")\n");
    return idx + 2;
}

int showInstruction(IR* ir, int idx) {
    printf("%06d\t", idx);
    uint8_t inst = ir->code[idx];
    switch (inst) {
        default:
            return displayUnknownInstruction(inst, idx);

        case INS_RET:
            return displayInstruction("INS_RET", idx);
        case INS_DEC:
            return displayOneOperandInstruction("INS_DEC", ir, idx);
    }
}

void printStuff(DataValue val) {
    printf("%g", val);
}
