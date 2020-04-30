#include "abstractTypes.hpp"

CppType::CppType(std::string name):
    name(name)
{}

CppType::~CppType()
{}

std::string CppType::getName()
{
    return name;
}


NumberBased::NumberBased(std::string name):
    CppType(name)
{}


UnsignedNumberBased::UnsignedNumberBased(std::string name):
    NumberBased(name)
{}

long long int UnsignedNumberBased::minValue()
{
    return 0;
}