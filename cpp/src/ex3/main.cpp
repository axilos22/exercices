#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum class cppTypes {
    CHAR,
    SHORT,
    INT,
    LONG,
    LONGLONG,
    FLOAT,
    DOUBLE,
    LONGDOUBLE,
    BOOL
};

const vector<cppTypes> displayedCppTypes = { cppTypes::CHAR, cppTypes::SHORT, cppTypes::INT, cppTypes::LONG, cppTypes::LONGLONG, cppTypes::FLOAT, cppTypes::DOUBLE, cppTypes::LONGDOUBLE, cppTypes::BOOL};

size_t sizeofType(cppTypes typeName);
void display(cppTypes type, size_t size);
string displayType(cppTypes type);


int main()
{
    for(auto &type: displayedCppTypes){
        try {
            size_t size = sizeofType(type);
            display(type, size);
        } catch(const char* message) {
            cerr << "ERROR: "<< message << endl;
        }
    }
}

size_t sizeofType(cppTypes typeName) {
    size_t size = 0;
    switch (typeName)
    {
    case cppTypes::CHAR:
        size= sizeof(char);
        break;

    case cppTypes::SHORT:
        size = sizeof(short);
        break;

    case cppTypes::INT:
        size = sizeof(int);
        break;

    case cppTypes::LONG:
        size = sizeof(long);
        break;

    case cppTypes::LONGLONG:
        size = sizeof(long long);
        break;

    case cppTypes::FLOAT:
        size = sizeof(float);
        break;

    case cppTypes::DOUBLE:
        size = sizeof(double);
        break;

    case cppTypes::LONGDOUBLE:
        size = sizeof(long double);
        break;

    case cppTypes::BOOL:
        size= sizeof(bool);
        break;

    default:
        throw "Unkown type exception";
        size = 0;
        break;
    }
    return size;
}

void display(cppTypes type, size_t size)
{
    cout << "Type: " << displayType(type) << " is of size: " << size << endl;
}

string displayType(cppTypes type) {
    string str_type = "None";
    switch (type)
    {
    case cppTypes::CHAR:
        str_type = "char";
        break;

    case cppTypes::SHORT:
        str_type = "short";
        break;

    case cppTypes::INT:
        str_type = "int";
        break;

    case cppTypes::LONG:
        str_type = "long";
        break;

    case cppTypes::LONGLONG:
        str_type = "long long";
        break;

    case cppTypes::FLOAT:
        str_type = "float";
        break;

    case cppTypes::DOUBLE:
        str_type = "double";
        break;

    case cppTypes::LONGDOUBLE:
        str_type = "long double";
        break;

    case cppTypes::BOOL:
        str_type = "bool";
        break;

    default:
        throw "Unkown type exception";
        str_type = "None";
        break;
    }
    return str_type;
}