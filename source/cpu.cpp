#include <iostream>
#include <chrono>
#include <thread>
#include "cpu.h"
#include "memory.h"

CPU::CPU(Memory memory) {  
    this->memory = memory; 
    this->isRunning = true; 
}

void CPU::reset(){
    address = 0x0000;
    register_a = 0x00;
    register_b = 0x00;
    instruction_register = 0x00;
    extended_register_flag = false;
    carry_flag = false;
}

void CPU::run(){
    while(isRunning){
     fetch();
     decode();
     std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }}

//Get the instruction at the current memory location and step the memory counter.
void CPU::fetch(){
     instruction_register = memory.access(address);
     std::cout << "Fetch " << instruction_register << " from " << address << std::endl;
     incrementAddressRegister();
}

//Figure out what the instruction means.
void CPU::decode(){
    switch(instruction_register){
        case 0x00:
            break;
        case 0xFF:
            extended_register_flag = true;
            break;
    }

    if (extended_register_flag == true){
        extended_register_flag = false;
        incrementAddressRegister();
        instruction_register = memory.access(address);
        switch(instruction_register){
            case 0x00:
                std::cout << "Extended NOP" << std::endl;
                break;
        }
    }
}

int CPU::incrementAddressRegister(){
    if (address == 0xFFFF){address == 0x00;}
    address++;
    return address;
}
