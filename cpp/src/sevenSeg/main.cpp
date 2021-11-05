#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define DEBUG 0

using namespace std;

const unsigned int CHAR_SIZE = 3;
const unsigned int MIN_DIGIT_COUNT = CHAR_SIZE;
const unsigned int MAX_DIGIT_COUNT = CHAR_SIZE * 100;

vector<string> getCharacter(size_t charRank, string line0, string line1, string line2);
void printCharacter(vector<string> character);
unsigned int identifyCharacter(vector<string> character);

int main()
{
    string line1;
    getline(cin, line1);
    string line2;
    getline(cin, line2);
    string line3;
    getline(cin, line3);
    size_t char_nb = line1.size() / CHAR_SIZE;
    string answer;
    for(int char_rank=0; char_rank < char_nb; char_rank++) {
        vector<string> character = getCharacter(char_rank, line1, line2, line3);
        #if DEBUG > 1
            printCharacter(character);
        #endif
        unsigned int numerical_character = identifyCharacter(character);
        answer.append(to_string(numerical_character));
    }
    cout << answer << endl;
}

vector<string> getCharacter(size_t rank, string line0, string line1, string line2) {
    vector<string> character;
    character.push_back(line0.substr(rank*CHAR_SIZE, CHAR_SIZE));
    character.push_back(line1.substr(rank*CHAR_SIZE, CHAR_SIZE));
    character.push_back(line2.substr(rank*CHAR_SIZE, CHAR_SIZE));
    return character;
}

void printCharacter(vector<string> character) {
    for( string st : character) {
        cerr << st << endl;
    }
}

bool hasNoStroke(string line) {
    bool result = line.compare("   ") == 0;
    #if DEBUG > 0
        cerr << "Comparing:" << line << " and " << "   " << endl;
        cerr << "Result is " << result << endl;
    #endif
    return result;
}

bool hasBottomStroke(string line) {
    return line.compare(" _ ") == 0;
}

bool hasLeftStroke(string line)  {
    return line.compare("  |") == 0;
}

bool hasDoubleStroke(string line)  {
    return line.compare("| |") == 0;
}

bool hasDoubleAndBottomStroke(string line)  {
    return line.compare("|_|") == 0;
}

bool hasLeftandBottomStroke(string line) {
    return line.compare("|_ ") == 0;
}

bool hasBottomAndRightStroke(string line) {
    return line.compare(" _|") == 0;
}

bool hasBottomAndLeftStroke(string line) {
    return line.compare("|_ ") == 0;
}

unsigned int identifyCharacter(vector<string> character) {
    // line 0 elimination
    if(hasNoStroke(character.at(0))) { // 1 or 4
        if(hasDoubleAndBottomStroke(character.at(1))) {
            return 4;
        } else {
            return 1;
        }
    } //line 1 elimination
    else if (hasDoubleStroke(character.at(1))) {
        return 0;
    }
    else if (hasLeftStroke(character.at(1))) {
        return 7; 
    } //line 2 elimination          
    else if (hasBottomAndLeftStroke(character.at(2))) {
        return 2;
    }
    else if (hasBottomAndRightStroke(character.at(2))) { // 3 or 5 or 9
        if (hasBottomAndRightStroke(character.at(1))) {
            return 3;
        } else if (hasBottomAndLeftStroke(character.at(1))) {
            return 5;
        } else {
            return 9;
        }
    }
    else if (hasDoubleAndBottomStroke(character.at(2))) { // 6 or 8
        if(hasBottomAndLeftStroke(character.at(1))) {
            return 6;
        } else {
            return 8;
        }
    }
    return 9;
}
