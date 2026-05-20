// komentarze skopiowane z poradnika w go z listy przykladowych projektow
#include "parser.h"
#include <iostream>
#include <string>

Parser::Parser(Lexer& l) : l(l) {
    // Read two tokens, so curToken and peekToken are both set
    nextToken();
    nextToken();
}

JsonObject Parser::ParseJson() {
    JsonObject values;

    // We check for initial { and then skip it
    if(curToken.type != TokenType::LBRACE) {
        return values;
    }
    nextToken();

    // we parse all the data in it and store it in values
    parseKeyVal(values);

    return values;
}
void Parser::nextToken() {
    curToken = peekToken;
    peekToken = l.NextToken();
}

// This funcion parses all the tokens
void Parser::parseKeyVal(JsonObject& values) {
    switch(curToken.type) {
        // when we encounter comma that means theres another key value pair
        // so we skip comma and do recursive parsekeyVal() to get next value
        case TokenType::COMMA:
            nextToken();
            parseKeyVal(values);
            break;
            
        // when we encounter a string then it will always be key
        // ex. "name" : "yash"
        //       ^        ^ 
        //      key     value
        case TokenType::STRING:
            {
                std::string key = curToken.literal;
                if(peekToken.type != TokenType::COLON) {
                    std::cerr << "Error while parsing! Expected COLON got " <<  peekToken.tokenTypeToString() << '\n';
                    return;
                }
                nextToken(); // colon
                nextToken(); // value

                if(curToken.type == TokenType::BOOL) {
                    if(curToken.literal == "true") {
                        values[key] = true;
                    } else {
                        values[key] = false;
                    }
                } else if(curToken.type == TokenType::INT) {
                    values[key] = std::stoi(curToken.literal);
                } else {
                    values[key] = curToken.literal;
                }
                // if it is not } then we continue the recursive call of parseKeyVal to read more values
                if(peekToken.type != TokenType::RBRACE) {
                    nextToken();
                    parseKeyVal(values);
                }
                break;
            }
        
        default:
            break;
    }
}