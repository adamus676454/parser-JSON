#include <iostream>
#include <string>
#include "lexer.h"
#include "parser.h"

int main() {
    std::string data = R"({
        "imie": "tester",
        "wiek": 20,
        "isActive": true,
        "zainteresowania": "C++"
    })";

    Lexer lexer(data);
    Parser parser(lexer);

    JsonObject vals = parser.ParseJson();

    for (const auto& [key, val] : vals) {
        std::cout << "Key: " << key << " -> Value: ";
        if (std::holds_alternative<std::string>(val.value)) {
            std::cout << "[String] " << std::get<std::string>(val.value);
        } 
        else if (std::holds_alternative<double>(val.value)) {
            std::cout << "[Int] " << std::get<double>(val.value);
        } 
        else if (std::holds_alternative<bool>(val.value)) {
            std::cout << "[Bool] " << (std::get<bool>(val.value) ? "true" : "false");
        } 
        else if (std::holds_alternative<std::nullptr_t>(val.value)) {
            std::cout << "[Null] null";
        } 
        else {
            std::cout << "Other type";
        }
        
        std::cout << "\n";
    };
}