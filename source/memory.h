#pragma once

#include <array>

class Memory {
    private:
    std::array<int, 0xFFFF> bytes;
    public:
    Memory();
    int access(int address);
};