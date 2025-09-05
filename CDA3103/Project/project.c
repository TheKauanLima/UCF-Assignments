// Semester Project: CDA3103C
// Written by: Kauan Lima
// 4/18/2025
#include "spimcore.h"
#define MemSize (65536 >> 2)

/* ALU */
/* 10 Points */
void ALU(unsigned A, unsigned B, char ALUControl, unsigned *ALUresult, char *Zero)
{
    switch (ALUControl)
    {
    case 0: // add
        *ALUresult = A + B;
        break;
    case 1: // sub
        *ALUresult = A - B;
        break;
    case 2: // slt
        *ALUresult = ((int)A < (int)B);
        break;
    case 3: // sltu
        *ALUresult = (A < B);
        break;
    case 4: // and
        *ALUresult = A & B;
        break;
    case 5: // or
        *ALUresult = A | B;
        break;
    case 6: // B = extended_value, shift left 16
        *ALUresult = (B << 16);
        break;
    default:
        break;
    }

    *Zero = (*ALUresult == 0);
}

/* instruction fetch */
/* 10 Points */
int instruction_fetch(unsigned PC, unsigned *Mem, unsigned *instruction)
{
    // check if memory is valid
    if (PC % 4 != 0 || PC >> 2 >= MemSize)
        return 1;
    // obtain instruction from memory
    *instruction = Mem[PC >> 2];
    return 0;
}

/* instruction partition */
/* 10 Points */
void instruction_partition(unsigned instruction, unsigned *op, unsigned *r1, unsigned *r2, unsigned *r3, unsigned *funct, unsigned *offset, unsigned *jsec)
{
    // mask the required # of bits from instruction into each pointer
    *op = (instruction >> 26) & 0x3F;  // 6 bits
    *r1 = (instruction >> 21) & 0x1F;  // 5 bits
    *r2 = (instruction >> 16) & 0x1F;  // 5 bits
    *r3 = (instruction >> 11) & 0x1F;  // 5 bits
    *funct = (instruction) & 0x3F;     // 6 bits
    *offset = (instruction) & 0xFFFF;  // 16 bits
    *jsec = (instruction) & 0x3FFFFFF; // 26 bits
}

/* instruction decode */
/* 15 Points */
int instruction_decode(unsigned op, struct_controls *controls)
{
    // set the correct controls for different instructions
    switch (op)
    {
    case 0x00: // R-Type
        controls->RegDst = 1;
        controls->Jump = 0;
        controls->Branch = 0;
        controls->MemRead = 0;
        controls->MemtoReg = 0;
        controls->ALUOp = 7;
        controls->MemWrite = 0;
        controls->ALUSrc = 0;
        controls->RegWrite = 1;
        break;
    case 0x02: // jump
        controls->RegDst = 2;
        controls->Jump = 1;
        controls->Branch = 0;
        controls->MemRead = 0;
        controls->MemtoReg = 2;
        controls->ALUOp = 0;
        controls->MemWrite = 0;
        controls->ALUSrc = 2;
        controls->RegWrite = 0;
        break;
    case 0x04: // beq
        controls->RegDst = 2;
        controls->Jump = 0;
        controls->Branch = 1;
        controls->MemRead = 0;
        controls->MemtoReg = 2;
        controls->ALUOp = 1;
        controls->MemWrite = 0;
        controls->ALUSrc = 0;
        controls->RegWrite = 0;
        break;
    case 0x08: // addi
        controls->RegDst = 0;
        controls->Jump = 0;
        controls->Branch = 0;
        controls->MemRead = 0;
        controls->MemtoReg = 0;
        controls->ALUOp = 0;
        controls->MemWrite = 0;
        controls->ALUSrc = 1;
        controls->RegWrite = 1;
        break;
    case 0x0A: // slti
        controls->RegDst = 0;
        controls->Jump = 0;
        controls->Branch = 0;
        controls->MemRead = 0;
        controls->MemtoReg = 0;
        controls->ALUOp = 2;
        controls->MemWrite = 0;
        controls->ALUSrc = 1;
        controls->RegWrite = 1;
        break;
    case 0x0B: // sltiu
        controls->RegDst = 0;
        controls->Jump = 0;
        controls->Branch = 0;
        controls->MemRead = 0;
        controls->MemtoReg = 0;
        controls->ALUOp = 3;
        controls->MemWrite = 0;
        controls->ALUSrc = 1;
        controls->RegWrite = 1;
        break;
    case 0x0F: // lui
        controls->RegDst = 0;
        controls->Jump = 0;
        controls->Branch = 0;
        controls->MemRead = 0;
        controls->MemtoReg = 0;
        controls->ALUOp = 6;
        controls->MemWrite = 0;
        controls->ALUSrc = 1;
        controls->RegWrite = 1;
        break;
    case 0x23: // lw
        controls->RegDst = 0;
        controls->Jump = 0;
        controls->Branch = 0;
        controls->MemRead = 1;
        controls->MemtoReg = 1;
        controls->ALUOp = 0;
        controls->MemWrite = 0;
        controls->ALUSrc = 1;
        controls->RegWrite = 1;
        break;
    case 0x2B: // sw
        controls->RegDst = 2;
        controls->Jump = 0;
        controls->Branch = 0;
        controls->MemRead = 0;
        controls->MemtoReg = 2;
        controls->ALUOp = 0;
        controls->MemWrite = 1;
        controls->ALUSrc = 1;
        controls->RegWrite = 0;
        break;
    default: // illegal op
        return 1;
    }
    return 0;
}

/* Read Register */
/* 5 Points */
void read_register(unsigned r1, unsigned r2, unsigned *Reg, unsigned *data1, unsigned *data2)
{
    // read from reg into data
    *data1 = Reg[r1];
    *data2 = Reg[r2];
}

/* Sign Extend */
/* 10 Points */
void sign_extend(unsigned offset, unsigned *extended_value)
{
    // obtain msb by shifting 15 spaces and masking the first bit
    int msb = (offset >> 15) & 0x1;

    // if msb = 1, pad with 1s
    if (msb)
        *extended_value = offset | 0xFFFF0000;
    // if msb = 0, pad with 0s
    else
        *extended_value = offset & 0x0000FFFF;
}

/* ALU operations */
/* 10 Points */
int ALU_operations(unsigned data1, unsigned data2, unsigned extended_value, unsigned funct, char ALUOp, char ALUSrc, unsigned *ALUresult, char *Zero)
{
    // assign correct operand based on ALUSrc
    unsigned op2;
    if (ALUSrc)
        op2 = extended_value;
    else
        op2 = data2;

    // assigned correct control based on ALUOp and funct
    unsigned ALUControl;
    if (ALUOp == 7)
    {
        switch (funct)
        {
        case 0x20: // add
            ALUControl = 0;
            break;
        case 0x22: // sub
            ALUControl = 1;
            break;
        case 0x2A: // slt
            ALUControl = 2;
            break;
        case 0x2B: // sltu
            ALUControl = 2;
            break;
        case 0x24: // and
            ALUControl = 4;
            break;
        case 0x25: // or
            ALUControl = 5;
            break;
        default: // illegal op
            return 1;
        }
    }
    else
    {
        // halt if illegal ALUOp
        if (ALUOp < 0 || ALUOp > 7)
            return 1;
        ALUControl = ALUOp;
    }

    // call ALU
    ALU(data1, op2, ALUControl, ALUresult, Zero);
    return 0;
}

/* Read / Write Memory */
/* 10 Points */
int rw_memory(unsigned ALUresult, unsigned data2, char MemWrite, char MemRead, unsigned *memdata, unsigned *Mem)
{
    // halt if ALUresult stored as an ADDRESS is invalid
    if ((MemRead || MemWrite) &&
        ((ALUresult % 4 != 0) || (ALUresult >> 2) >= MemSize))
        return 1;

    // read data from memory if needed
    if (MemRead)
        *memdata = Mem[ALUresult >> 2];
    // write data to memory if needed
    if (MemWrite)
        Mem[ALUresult >> 2] = data2;
    return 0;
}

/* Write Register */
/* 10 Points */
void write_register(unsigned r2, unsigned r3, unsigned memdata, unsigned ALUresult, char RegWrite, char RegDst, char MemtoReg, unsigned *Reg)
{
    // exit if no memory needs to be written
    if (!RegWrite)
        return;

    // assign correct register to be overwritten
    unsigned reg;
    if (RegDst)
        reg = r3;
    else
        reg = r2;

    // assign correct value to write
    unsigned data;
    if (MemtoReg)
        data = memdata;
    else
        data = ALUresult;

    Reg[reg] = data;
}

/* PC update */
/* 10 Points */
void PC_update(unsigned jsec, unsigned extended_value, char Branch, char Jump, char Zero, unsigned *PC)
{
    // update PC by 4 (correct memory)
    *PC += 4;

    // trigger if beq is fulfilled
    if (Branch && Zero)
        *PC += (extended_value << 2);
    // trigger to jump
    if (Jump)
        *PC = (*PC & 0xF0000000) | (jsec << 2);
}
