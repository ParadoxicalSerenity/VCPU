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
}

void CPU::run(){
    while(isRunning){
     fetch();
     decode();
     execute();
     store();
     std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }}
  
void CPU::fetch(){
     instruction_register = memory.access(address);
     std::cout << "Fetch " << instruction_register << " from " << address << std::endl;
     address++;
}

void CPU::decode(){
    switch(instruction_register){
        case 0x00:
            std::cout << "NOP\n";
            break;
        case 0xFF:
            std::cout << "Extended Register\n";
            extended_register = true;
            break;
    }

    if (extended_register == true){
        //Advance to next memory location and perform a read and decode that.
    }
    std::cout << "Decode\n";
}
void CPU::execute(){
    std::cout << "Execute\n";
}
void CPU::store(){
    std::cout << "Store\n";
}

