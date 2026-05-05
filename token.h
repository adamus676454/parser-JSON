// komentarze skopiowane z poradnika w go z listy przykladowych projektow
#pragma once
#include <string>
enum class TokenType{
    ILLEGAL,
    END_OF_FILE,

    COMMA,  // ,
    COLON,  // :
    LBRACE, // {
    RBRACE, // }
    LBRACK, // [
    RBRACK, // ]

    STRING,
    INT,
    BOOL,
    TRUE,
    FALSE
};
class Token{
    public:
    TokenType type;
    std::string literal;
    Token(TokenType type, std::string literal): type(type), literal(literal){}
    Token(): type(TokenType::ILLEGAL), literal(""){}
    std::string tokenTypeToString() {
        switch(type) {
            case TokenType::ILLEGAL: return "ILLEGAL";
            case TokenType::END_OF_FILE: return "END_OF_FILE";
            case TokenType::COMMA: return "COMMA";
            case TokenType::COLON: return "COLON";
            case TokenType::LBRACE: return "LBRACE";
            case TokenType::RBRACE: return "RBRACE";
            case TokenType::LBRACK: return "LBRACK";
            case TokenType::RBRACK: return "RBRACK";
            case TokenType::STRING: return "STRING";
            case TokenType::INT: return "INT";
            case TokenType::BOOL: return "BOOL";
            default: return "UNKNOWN";
        }
    }
};