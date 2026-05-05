#include <iostream>
#include "token.h"
#include "lexer.h"

int main() {
    Lexer lexer("{\"Name\":\"cats are cute\",\"age\": 123423,\"isAlive\": true}");

    while (true) {
        Token tok = lexer.NextToken();
        std::cout << tok.tokenTypeToString() << " '" << tok.literal << "'\n";
        if (tok.type == TokenType::END_OF_FILE) break;
    }
}
