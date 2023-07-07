#include <vector>
#include "memory.h"

Memory::Memory(){
    bytes = {0x00,0xFF,0x00,0x00,0x00,0xFF,0x00,0x00};
}

int Memory::access(int address){
    return bytes.at(address);
}

