#include <iostream>

#include "inputParser.hpp"

int main(int argc, char *argv[])
{
    InputParser ip = InputParser(argc, argv);
    std::cout << ip.present() << std::endl;
}