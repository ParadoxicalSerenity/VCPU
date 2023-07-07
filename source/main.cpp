#include <iostream>
#include <vector>
#include <chrono>
#include <thread>

/**
 * 0x00 = NOP
 * 0x01 = Load next byte into Register A
 * 0xFF = Extended Registers
*/

class Memory {
    private:
    std::vector<int> bytes = {0x00,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,};
    public:
        int access(int address){return bytes.at(address);}
};

class CPU
{
    public:
    //We will want to setup anything the CPU needs in the constructor, like memory.
    CPU(Memory memory) {  
        this->memory = memory;   
    }
    void reset(){
        address = 0x0000;
    }
    void run(){
        while(isRunning){
     fetch();
     decode();
     execute();
     store();
     std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }}
    private:

    bool isRunning = true;

    Memory memory;

    //CPU Flags and Registers
    int address;
    int register_a;
    int instruction_register;
    bool extended_register;


    void fetch(){
         instruction_register = memory.access(address);
         std::cout << "Fetch " << instruction_register << " from " << address << std::endl;
         address++;
    }
    void decode(){
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
    void execute(){
        std::cout << "Execute\n";
    }
    void store(){
        std::cout << "Store\n";
    }

};

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