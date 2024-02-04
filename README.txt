CfgC

a C++ library for loading .cfg files into your C++ project

How to build:

commands:
    g++ -std=c++11 -Wall -I./include -c src/cfgc.cpp -o build/cfgc.o
    ar rcs lib/libcfgc32.a build/cfgc.o

first build the .o (object file) from teh source file then run the second command to build it into a .a library

RIMEMBER: create a lib and build folder in the root folder before building