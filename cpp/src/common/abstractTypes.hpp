#include <string>

class CppType {    
    public:
        CppType(std::string name);
        ~CppType();
        std::string getName();
        virtual size_t size() = 0;
    private:
        std::string name;
};

class NumberBased: public CppType {
    public:
        NumberBased(std::string name);
        virtual unsigned long long int maxValue() = 0;
        virtual long long int minValue() = 0;
};

class UnsignedNumberBased: public NumberBased {
    public:
        UnsignedNumberBased(std::string name);
        virtual unsigned long long int maxValue() = 0;
        long long int minValue();
};