cmake_minimum_required(VERSION 3.22)
project(VCPU)

set(CMAKE_CXX_STANDARD 14)

add_executable(VCPU source/main.cpp source/cpu.cpp source/memory.cpp source/cpu.h source/memory.h)