#include <iostream>
#include <vector>
#include "cpu.h"
#include "memory.h"
/**
 * 0x00 = NOP
 * 0x01 = Load next byte into Register A
 * 0xFF = Extended Registers
*/

int main (){
    std::cout << "::::::::\n";
    std::cout << "::VCPU::\n";
    std::cout << "::::::::\n";
    Memory memory = Memory();
    CPU cpu = CPU(memory);
    cpu.reset();
    cpu.run();
    return 0;
}