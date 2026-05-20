// komentarze skopiowane z poradnika w go z listy przykladowych projektow
#pragma once
#include "token.h"
#include "lexer.h"
#include "JsonValue.h"

// this structure will hold the tokens we get from our lexer
class Parser {
    public:
    Parser(Lexer& l);
    JsonObject ParseJson();
    void nextToken();
    void parseKeyVal(JsonObject& values);

    private:
    Lexer& l;
    Token curToken;
    Token peekToken;
};
