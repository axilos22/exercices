#include "inputParser.hpp"

InputParser::InputParser(int argc, char** argv) :
    argNb(argc)
{
    for(size_t argRank=0; argRank<argNb; argRank++)
    {
        rawArgList.push_back(argv[argRank]);
    }
}

size_t InputParser::getArgumentNumber()
{
    return argNb;
}

std::string InputParser::present()
{
    std::string presenting_string = "Argument Parsed: " + std::to_string(getArgumentNumber());
    for(size_t argRank=0; argRank<argNb; argRank++)
    {
        presenting_string.append("\n["+std::to_string(argRank)+"] = "+rawArgList[argRank]);
    }
    return presenting_string;
}