#pragma once 

#include "memory.h"
class CPU
{
    public:
        CPU(Memory memory);
        void reset();
        void run();

    private:

    bool isRunning;
    Memory memory;

    //Registers
    int address; //Word

    int register_a; //Byte
    int register_b; //Byte
    int instruction_register; // Byte

    //Flags
    bool extended_register_flag; //Bit
    bool carry_flag; //Bit

    int incrementAddressRegister();

    void fetch();
    void decode();
    void LoadValueIntoRegisterA();
    void LoadValueIntoRegisterB();
};