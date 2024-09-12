#include "Soundex.h"
#include <cctype>

char output;

void getSoundexCodedigit1(char c);
void getSoundexCodedigit2(char c);
void getSoundexCodedigit3(char c);
void getSoundexCodedigit4(char c);
void getSoundexCodedigit5(char c);
void getSoundexCodedigit6(char c);

char getSoundexCode(char c) {
    c = toupper(c);
    getSoundexCodedigit1(c);
    getSoundexCodedigit2(c);
    getSoundexCodedigit3(c);
    getSoundexCodedigit4(c);
    getSoundexCodedigit5(c);
    getSoundexCodedigit6(c);
    return output;
}

void getSoundexCodedigit1(char c)
{
    if (c == 'B' || c == 'F' || c == 'P' || c == 'V')
    {
        output = '1';
    }
}

void getSoundexCodedigit2(char c)
{
    if (c == 'C' || c == 'G' || c == 'J' || c == 'K' || c == 'Q' || c == 'S' || c == 'X' || c == 'Z')
    {
        output = '2';
    }
}

void getSoundexCodedigit3(char c)
{
    if (c == 'C' || c == 'G')
    {
        output = '3';
    }
}

void getSoundexCodedigit4(char c)
{
    if (c == 'L')
    {
        output = '4';
    }
}

void getSoundexCodedigit5(char c)
{
    if (c == 'M' || c == 'N')
    {
        output = '5';
    }
}

void getSoundexCodedigit6(char c)
{
    if (c == 'R')
    {
        output = '6';
    }
    else
    {
       output = '0'; 
    }
}

std::string appendLetterDigits(const std::string& letterDigits)
{
    char prevCode = getSoundexCode(letterDigits[0]);
    for (size_t i = 1; i < letterDigits.length() && soundex.length() < 4; ++i) {
        char code = getSoundexCode(letterDigits[i]);
        if (code != '0' && code != prevCode) {
            soundex += code;
            prevCode = code;
        }
    }

    return soundex;
}

std::string generateSoundex(const std::string& name) {
    if (name.empty()) return "";

    std::string soundex(1, toupper(name[0]));
    appendLetterDigits(name);
    /*char prevCode = getSoundexCode(name[0]);

    for (size_t i = 1; i < name.length() && soundex.length() < 4; ++i) {
        char code = getSoundexCode(name[i]);
        if (code != '0' && code != prevCode) {
            soundex += code;
            prevCode = code;
        }
    }*/

    while (soundex.length() < 4) {
        soundex += '0';
    }

    return soundex;
}
