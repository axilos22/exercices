#include <iostream>
#include <string>
#include <vector>

using namespace std;

static const unsigned int expectedArgumentNb = 2;
static const unsigned int systemArgumentOffset = 1; //called an offset. Is actually counting the program command as an argument.
static const char numericSeparator = '.';

void checkArgumentNumber(int argNumber);
string fetchArgument(int argRank, char* argv[]);
bool isArgumentFloat(string strNumber);
bool contains(char specificChar, string container);
void displaySum(string nb1, string nb2, string sum);
void usage();

int main(int argc, char *argv[])
{
    try {
        checkArgumentNumber(argc);
        string arg1 = fetchArgument(0, argv);
        string arg2 = fetchArgument(1, argv);
        
        if( isArgumentFloat(arg1) || isArgumentFloat(arg2) ) {
            float flt_arg1 = atof(arg1.c_str());
            float flt_arg2 = atof(arg2.c_str());
            float sum = flt_arg1 + flt_arg2;
            displaySum(to_string(flt_arg1), to_string(flt_arg2), to_string(sum));
        } else
        {
            int int_arg1 = atoi(arg1.c_str());
            int int_arg2 = atoi(arg2.c_str());
            int sum = int_arg1 + int_arg2;
            displaySum(to_string(int_arg1), to_string(int_arg2), to_string(sum));
        }
        
    }
    catch(const char* errorMessage) {
        cerr << "ERROR: " << errorMessage << endl;
        usage();
    }
}

void checkArgumentNumber(int argNumber) {
    if(argNumber > expectedArgumentNb + systemArgumentOffset)
        throw "Too many arguments provided !";
    if(argNumber < expectedArgumentNb + systemArgumentOffset)
        throw "Too few argument provided !";
}

string fetchArgument(int argRank, char* argv[]) {
    string retArgument = "empty_string";
    retArgument = argv[systemArgumentOffset + argRank];
    return retArgument;
}

bool isArgumentFloat(string strNumber) {
    return contains(numericSeparator, strNumber);
}

bool contains(char specificChar, string container) {
    return container.find(specificChar) != string::npos;
}

void displaySum(string nb1, string nb2, string sum) {
    cout << nb1 << "+" << nb2 << "=" << sum << endl;
}

void usage() {
    cout << "Usage:\nex2 <nb1> <nb2>\nex: ex2 1 20" << endl;
}