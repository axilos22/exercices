#include <string>
#include <vector>

class InputParser {    
    public:
        InputParser(int argc, char** argv);
        size_t getArgumentNumber();
        std::string present();
    private:
        size_t argNb;
        std::vector<std::string> rawArgList;
};
