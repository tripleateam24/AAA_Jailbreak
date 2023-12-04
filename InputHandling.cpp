#include "InputHandling.h"
#include <cctype>
using namespace std;

string clearWhiteSpaceAndCapitalize(string input)
{
    bool newWord = true;
    for (size_t i = 0; i < input.length(); i++) {
        if (isspace(input[i])) {
            newWord = true;
        }
        else {
            if (newWord) {
                input[i] = toupper(input[i]);
                newWord = false;
            }
            else {
                input[i] = tolower(input[i]);
            }
        }
    }

    // Erase leading and trailing whitespace
    size_t firstNonSpace = input.find_first_not_of(' ');
    size_t lastNonSpace = input.find_last_not_of(' ');

    if (firstNonSpace == string::npos) {
        return "";
    }

    return input.substr(firstNonSpace, lastNonSpace - firstNonSpace + 1);
}
