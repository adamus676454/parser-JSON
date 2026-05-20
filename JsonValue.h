#pragma once
#include <string>
#include <vector>
#include <map>
#include <variant>
#include <cstddef>

// JsonValue.h to odpowiednik interface{} z go

struct JsonValue;

using JsonArray = std::vector<JsonValue>;
using JsonObject = std::map<std::string, JsonValue>;

struct JsonValue {
    std::variant<std::nullptr_t, bool, double, std::string, JsonArray, JsonObject>value;
    JsonValue() : value(nullptr) {}
    JsonValue(std::nullptr_t) : value(nullptr) {}
    JsonValue(bool value) : value(value) {}
    JsonValue(double value) : value(value) {}
    JsonValue(int value) : value(static_cast<double>(value)) {}
    JsonValue(const std::string& value) : value(value) {}
    JsonValue(const char* value) : value(std::string(value)) {}
    JsonValue(const JsonArray& value) : value(value) {}
    JsonValue(const JsonObject& value) : value(value) {}
};