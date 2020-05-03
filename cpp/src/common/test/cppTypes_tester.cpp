#include <iostream>
#include <vector>

#include "cppTypes.hpp"

void testNumberBaseType(NumberBased *type);

int main(int argc, char *argv[])
{
    if( argc < 2 )
    {
        std::cout << "empty run" << std::endl;
    } else
    {
        testNumberBaseType(new CharType);
        testNumberBaseType(new UCharType);

        testNumberBaseType(new ShortType);
        testNumberBaseType(new UShortType);

        testNumberBaseType(new IntType);
        testNumberBaseType(new UIntType);

        testNumberBaseType(new LongType);
        testNumberBaseType(new ULongType);

        testNumberBaseType(new LongLongType);
        testNumberBaseType(new ULongLongType);
    }
    return 0;
}

void testNumberBaseType(NumberBased *type)
{
    std::cout << type->getName() << std::endl;
    std::cout << type->size() << std::endl;
    std::cout << type->maxValue() << std::endl;
    std::cout << type->maxValue() << std::endl;
}