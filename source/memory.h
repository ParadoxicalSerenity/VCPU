#pragma once

#include <vector>
class Memory {
    private:
    std::vector<int> bytes;
    public:
    Memory();
    int access(int address);
};