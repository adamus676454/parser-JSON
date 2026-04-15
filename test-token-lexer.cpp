#include <iostream>
#include "token.h"
#include "lexer.h"

int main() {
    Lexer lexer("{ :,\"test\"}");

    while (true) {
        Token tok = lexer.NextToken();
        std::cout << tok.tokenTypeToString() << " '" << tok.literal << "'\n";
        if (tok.type == TokenType::END_OF_FILE) break;
    }
}
