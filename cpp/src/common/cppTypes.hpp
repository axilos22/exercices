#include "abstractTypes.hpp"

#include <climits>

class CharType : public NumberBased
{
public:
    CharType() : NumberBased("Char"){};
    unsigned long long int maxValue() { return CHAR_MAX; }
    long long int minValue() { return CHAR_MIN; }
    size_t size() { return sizeof(char); }
};

class UCharType : public UnsignedNumberBased
{
public:
    UCharType() : UnsignedNumberBased("UChar"){};
    unsigned long long int maxValue() { return UCHAR_MAX; }
    size_t size() { return sizeof(unsigned char); }
};

class ShortType : public NumberBased
{
public:
    ShortType() : NumberBased("Short"){};
    unsigned long long int maxValue() { return SHRT_MAX; }
    long long int minValue() { return SHRT_MIN; }
    size_t size() { return sizeof(short); }
};

class UShortType : public UnsignedNumberBased
{
public:
    UShortType() : UnsignedNumberBased("UShort"){};
    unsigned long long int maxValue() { return USHRT_MAX; }
    size_t size() { return sizeof(unsigned short int); }
};

class IntType : public NumberBased
{
public:
    IntType() : NumberBased("Int"){};
    unsigned long long int maxValue() { return INT_MAX; }
    long long int minValue() { return INT_MIN; }
    size_t size() { return sizeof(int); }
};

class UIntType : public UnsignedNumberBased
{
public:
    UIntType() : UnsignedNumberBased("UInt"){};
    unsigned long long int maxValue() { return UINT_MAX; }
    size_t size() { return sizeof(unsigned int); }
};

class LongType : public NumberBased
{
public:
    LongType() : NumberBased("Long"){};
    unsigned long long int maxValue() { return LONG_MAX; }
    long long int minValue() { return LONG_MIN; }
    size_t size() { return sizeof(long); }
};

class ULongType : public UnsignedNumberBased
{
public:
    ULongType() : UnsignedNumberBased("ULong"){};
    unsigned long long int maxValue() { return ULONG_MAX; }
    size_t size() { return sizeof(unsigned long int); }
};

class LongLongType : public NumberBased
{
public:
    LongLongType() : NumberBased("LongLong"){};
    unsigned long long int maxValue() { return LLONG_MAX; }
    long long int minValue() { return LLONG_MIN; }
    size_t size() { return sizeof(long long int); }
};

class ULongLongType : public UnsignedNumberBased
{
public:
    ULongLongType() : UnsignedNumberBased("ULongLong"){};
    unsigned long long int maxValue() { return ULLONG_MAX; }
    size_t size() { return sizeof(unsigned long long int); }
};