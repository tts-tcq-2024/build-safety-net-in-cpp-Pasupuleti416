#include "Soundex.h"
#include <cctype>

char output;

char getSoundexCodedigit1(char c);
char getSoundexCodedigit2(char c);
char getSoundexCodedigit3(char c);
char getSoundexCodedigit4(char c);
char getSoundexCodedigit5(char c);
char getSoundexCodedigit6(char c);

char getSoundexCode(char c) {
    c = toupper(c);
    return getSoundexCodedigit1(c);
}

char getSoundexCodedigit1(char c)
{
    if (c == 'B' || c == 'F' || c == 'P' || c == 'V')
    {
        return '1';
    }
    else
    {
        return getSoundexCodedigit2(c);
    }
}

char getSoundexCodedigit2(char c)
{
    if (c == 'C' || c == 'G' || c == 'J' || c == 'K' || c == 'Q' || c == 'S' || c == 'X' || c == 'Z')
    {
        return '2';
    }
    else
    {
        return getSoundexCodedigit3(c);
    }
}

char getSoundexCodedigit3(char c)
{
    if (c == 'C' || c == 'G')
    {
        return '3';
    }

    else
    {
        return getSoundexCodedigit4(c);
    }
}

char getSoundexCodedigit4(char c)
{
    if (c == 'L')
    {
        return '4';
    }
    else
    {
        return getSoundexCodedigit5(c);
    }
}

char getSoundexCodedigit5(char c)
{
    if (c == 'M' || c == 'N')
    {
        return '5';
    }
    else
    {
        return getSoundexCodedigit6(c);
    }
}

char getSoundexCodedigit6(char c)
{
    if (c == 'R')
    {
        return '6';
    }
    else
    {
       return '0'; 
    }
}

std::string appendLetterDigits(std::string& soundexAppend,const std::string& nameAppend)
{
    char prevCode = getSoundexCode(nameAppend[0]);
    for (size_t i = 1; i < nameAppend.length() && soundexAppend.length() < 4; ++i) {
        char code = getSoundexCode(nameAppend[i]);
        if (code != '0' && code != prevCode) {
            soundexAppend += code;
            prevCode = code;
        }
    }

    return soundexAppend;
}

std::string generateSoundex(const std::string& name) {
    if (name.empty()) return "";

    std::string soundex(1, toupper(name[0]));
    soundex = appendLetterDigits(soundex,name);

    while (soundex.length() < 4) {
        soundex += '0';
    }

    return soundex;
}
