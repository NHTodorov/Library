#pragma once
#include <string>
#include <algorithm>

// function to convert string to lower letters and remove spaces 
std::string StringConvert(const std::string& input) {
    std::string result = input;
    transform(result.begin(), result.end(), result.begin(), ::tolower);
    result.erase(remove(result.begin(), result.end(), ' '), result.end());
    return result;
}
