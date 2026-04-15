// komentarze skopiowane z poradnika w go z listy przykladowych projektow
#pragma once
#include "token.h"

class Lexer{
    public:
    Lexer(std::string input);
    void readChar();
    Token NextToken();
    std::string readString();
    private:
    std::string input; // Input string is the string which we want to convert to json
    int position; // Position is the pointer that keeps track of what character we are reading
    int readPosition; // This pointer is one character of position pointer
    char ch; // This holds the current character of readPosition
};