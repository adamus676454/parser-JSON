// komentarze skopiowane z poradnika w go z listy przykladowych projektow
#include "token.h"
#include "lexer.h"

Lexer::Lexer(std::string input): input(input), position(0), readPosition(0), ch(0){
    readChar();
}

// This function increments the position of position and readPointer by one,
// and replaces the current character with next character
void Lexer::readChar(){
    if (readPosition >= input.length()){
        ch = 0;
    }else{
        ch = input[readPosition];
    }
    position = readPosition;
    readPosition += 1;
}

// This the the actual function where we convert our string into tokens
Token Lexer::NextToken(){
    Token tok;
    switch(ch){
        case '{':
            tok = Token(TokenType::LBRACE, std::string(1, ch));
            break;
        case '}':
            tok = Token(TokenType::RBRACE, std::string(1, ch));
            break;
        case ':':
            tok = Token(TokenType::COLON, std::string(1, ch));
            break;
        case ',':
            tok = Token(TokenType::COMMA, std::string(1, ch));
            break;
        case '"':
            readChar();
            tok.literal = readString(); // This reads characters until " is encountered
            tok.type = TokenType::STRING;
            break;
        case 0: // there is '\0' at the end of the string
            tok = Token(TokenType::END_OF_FILE, "");
            break;
    }
    readChar();
    return tok;
}

// reads a string till " is encountered and returns that string
std::string Lexer::readString(){
    std::string str;
    while(ch != '"'){
        str += ch;
        readChar();
    }
    return str;
}