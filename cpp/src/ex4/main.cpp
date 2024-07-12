#include <iostream>
#include <vector>

#include "cppTypes.hpp"

using namespace std;

void fillVector(vector<NumberBased*> &types);
void displayAllVector(const vector<NumberBased*> &typesToShow);
void displayTypeInfo(NumberBased* type);
void displayDatatypeLimit(NumberBased* type);
void displayDatatypeSize(NumberBased* type);

int main()
{
    vector<NumberBased*> types;
    fillVector(types);
    displayAllVector(types);
}

void fillVector(vector<NumberBased*> &types)
{
    CharType* charType = new CharType;
    UCharType* ucharType = new UCharType;
    types.push_back(charType);
    types.push_back(ucharType);

    auto shortType = new ShortType;
    auto ushortType = new UShortType;
    types.push_back(shortType);
    types.push_back(ushortType);

    auto intType = new IntType;
    auto uintType = new UIntType;
    types.push_back(intType);
    types.push_back(uintType);

    auto longType = new LongType;
    auto ulongType = new ULongType;
    types.push_back(longType);
    types.push_back(ulongType);

    auto longlongType = new LongLongType;
    auto ulonglongType = new ULongLongType;
    types.push_back(longlongType);
    types.push_back(ulonglongType);
}

void displayAllVector(const vector<NumberBased*> &typesToShow)
{
    for(auto type: typesToShow)
    {
        displayTypeInfo(type);
    }
}

void displayTypeInfo(NumberBased* type)
{
    cout << "----- Info of " << type->getName() << "-----" << endl;
    displayDatatypeSize(type);
    displayDatatypeLimit(type);
}

void displayDatatypeSize(NumberBased* type)
{
    string unit = "bytes";
    if (type->size() == 1)
    {
        unit = "byte";
    }
    cout << "Size = "  << type->size() << " " << unit << endl;
}

void displayDatatypeLimit(NumberBased* type)
{
    cout << "Limits values are [ " << type->minValue() << " ; " << type->maxValue() << " ]" << endl;
}


