#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum cppTypes {
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

const vector<cppTypes> displayedCppTypes = {CHAR, SHORT, INT, LONG, LONGLONG, FLOAT, DOUBLE, LONGDOUBLE, BOOL};

unsigned int sizeofType(cppTypes typeName);
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

unsigned int sizeofType(cppTypes typeName) {
    size_t size = 0;
    switch (typeName)
    {
    case CHAR:
        size= sizeof(char);
        break;

    case SHORT:
        size = sizeof(short);
        break;

    case INT:
        size = sizeof(int);
        break;

    case LONG:
        size = sizeof(long);
        break;

    case LONGLONG:
        size = sizeof(long long);
        break;

    case FLOAT:
        size = sizeof(float);
        break;

    case DOUBLE:
        size = sizeof(double);
        break;

    case LONGDOUBLE:
        size = sizeof(long double);
        break;

    case BOOL:
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
    case CHAR:
        str_type = "char";
        break;

    case SHORT:
        str_type = "short";
        break;

    case INT:
        str_type = "int";
        break;

    case LONG:
        str_type = "long";
        break;

    case LONGLONG:
        str_type = "long long";
        break;

    case FLOAT:
        str_type = "float";
        break;

    case DOUBLE:
        str_type = "double";
        break;

    case LONGDOUBLE:
        str_type = "long double";
        break;

    case BOOL:
        str_type = "bool";
        break;

    default:
        throw "Unkown type exception";
        str_type = "None";
        break;
    }
    return str_type;
}