#include <array>
#include "memory.h"

Memory::Memory(){
    bytes.fill(0x00);
    bytes[0] = 0xFF;
    bytes[1] = 0x00;
    bytes[2] = 0x01;
    bytes[3] = 0x55;
    bytes[4] = 0x02;
    bytes[5] = 0xAA;
}

int Memory::access(int address){
    return bytes[address];
}

