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

    //CPU Flags and Registers
    int address;
    int register_a;
    int instruction_register;
    
    bool extended_register;

    void fetch();
    void decode();
    void execute();
    void store();
};