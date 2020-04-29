#include <iostream>
#include <string>

using namespace std;

const string getWelcomeString();

int main()
{
    string display_message = getWelcomeString();
    cout << display_message << endl;
}

const string getWelcomeString() {
    return "Hello World !";
}